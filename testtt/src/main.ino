//#include <arduino.h>
#include <ESP8266WiFi.h>
#include <Hash.h>
#include <Ticker.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPClient.h>
#include <DNSServer.h>

int LED = 5;
int BUZZ = 12;
int LASER = 4;
int BUTTON = 2;
volatile bool trigger = true;
const byte Comparator = 14;
volatile unsigned int period = 20, eror = 1;
volatile unsigned int time_now, time_interupt;
bool LASER_ON = true;
volatile bool blink = true;
 
void setup()
{
 Serial.begin(9600); //spuštění serioveho rozhrani
 pinMode(LED, OUTPUT);
 pinMode(BUZZ, OUTPUT);
 pinMode(LASER, OUTPUT);
 pinMode(BUTTON, INPUT);
 pinMode(Comparator, INPUT_PULLUP); //přerušení
 digitalWrite(LASER, HIGH);
 digitalWrite(LED, HIGH);
 attachInterrupt(digitalPinToInterrupt(Comparator), Interupt , CHANGE);
 time_now = millis(); //vysílání laseru
 time_interupt = millis(); // přijímání z fototranzistoru
}

void loop()
{
  if (millis() >= time_now + period){ //kontrola vysílače
    //Serial.println(LED_ON ? "Zapnuto": "Vypnuto");
    //Serial.println(millis() - time_now);
    time_now = millis(); //nastavení výchozího času
    LASER_ON ? digitalWrite(LASER, LOW) : digitalWrite(LASER, HIGH); //vypnutí/zapnutí laseru
    LASER_ON = !LASER_ON; //uložení aktuálního stavu do paměti
  }
  if (millis() >= time_interupt + 10*period){ //kontrola, že dlouho nepřišel signál (reaguje na změnu)
    digitalWrite(LED, LOW); //vypnu ledky
    digitalWrite(BUZZ, HIGH); //zapnu bzučák
    trigger = false; //nezapezpečeno
    time_interupt = millis(); //posunutí času, aby se podmínka nespouštěla po každém průchodu, ale po každém 10ém.
   //Kdyby se podmínka vyhodnocovala pořád, nikdy by se nevyhodnotila funkce Interupt z důvodu trigger = false
  }
}

void Interupt()
{
  if (trigger){ //zabezpečení ?
    if (blink){ //první průchod - nastavení času
      time_interupt = millis(); //nastavení času
      blink = !blink; //vypnout fuknci
    }
    else if (millis() <= time_interupt + period + eror && millis() >= time_interupt + period - eror){ //kontrola správného intervalu signálu
      Serial.println(millis() - time_interupt); //pomocný výpis ke kontrole periody
      time_interupt = millis(); //nastavení nového času
    }
    else{
      Serial.println("Spatny cas");
      Serial.println(millis() - time_interupt); //výpis špatného času
      digitalWrite(LED, LOW); //vypnutí ledek
      digitalWrite(BUZZ, HIGH); //zapnutí alarmu
      trigger = false; //prostor je narušen (podmínka trigger nebude probíhat)
    }
  }
  else{
    if(digitalRead(BUTTON) == LOW){ //je zmáčknuté tlačítko (Ground zapojen na pin = LOW místo HIGH)
      blink = !blink; //synchronizace času (funkce blink proběhne znovu a nastaví se čas)
      digitalWrite(LED, HIGH); //zapnutí ledek
      digitalWrite(BUZZ, LOW); //vypnutí bzučáku
      trigger = true; // prostor zabezpečen
      Serial.println("Zmackl jsem tlacitko"); //ověření
    }
  }
}
