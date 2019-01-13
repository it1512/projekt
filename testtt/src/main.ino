//#include <arduino.h>
#include <ESP8266WiFi.h>
#include <Hash.h>
#include <Ticker.h>//#include <arduino.h>
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
 pinMode(Comparator, INPUT_PULLUP);
 digitalWrite(LASER, HIGH);
 digitalWrite(LED, HIGH);
 attachInterrupt(digitalPinToInterrupt(Comparator), Interupt , CHANGE);
 time_now = millis();
 time_interupt = millis();
}

void loop()
{
  if (millis() >= time_now + period){
    //Serial.println(LED_ON ? "Zapnuto": "Vypnuto");
    //Serial.println(millis() - time_now);
    time_now = millis();
    LASER_ON ? digitalWrite(LASER, LOW) : digitalWrite(LASER, HIGH);
    LASER_ON = !LASER_ON; 
  }
  if (millis() >= time_interupt + 10*period){
    digitalWrite(LED, LOW);
    digitalWrite(BUZZ, HIGH);
    trigger = false;
    time_interupt = millis();
  }
}

void Interupt()
{
  if (trigger){
    if (blink){
      time_interupt = millis();
      blink = !blink;
    }
    else if (millis() <= time_interupt + period + eror && millis() >= time_interupt + period - eror){
      Serial.println(millis() - time_interupt);
      time_interupt = millis();
    }
    else{
      Serial.println("Spatny cas");
      Serial.println(millis() - time_interupt);
      digitalWrite(LED, LOW);
      digitalWrite(BUZZ, HIGH);
      trigger = false;
    }
  }
  else{
    if(digitalRead(BUTTON) == LOW){
      blink = !blink;
      digitalWrite(LED, HIGH);
      digitalWrite(BUZZ, LOW);
      trigger = true;
      Serial.println("Zmackl jsem tlacitko");
    }
  }
}
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
 pinMode(Comparator, INPUT_PULLUP);
 digitalWrite(LASER, HIGH);
 digitalWrite(LED, HIGH);
 attachInterrupt(digitalPinToInterrupt(Comparator), Interupt , CHANGE);
 time_now = millis();
}

void loop()
{
  if (millis() >= time_now + period){
    //Serial.println(LED_ON ? "Zapnuto": "Vypnuto");
    //Serial.println(millis() - time_now);
    time_now = millis();
    LASER_ON ? digitalWrite(LASER, LOW) : digitalWrite(LASER, HIGH);
    LASER_ON = !LASER_ON; 
  }
}

void Interupt()
{
  if (trigger){
    if (blink){
      time_interupt = millis();
      blink = !blink;
    }
    else if (millis() <= time_interupt + period + eror && millis() >= time_interupt + period - eror){
      Serial.println(millis() - time_interupt);
      time_interupt = millis();
    }
    else{
      Serial.println("Spatny cas");
      Serial.println(millis() - time_interupt);
      digitalWrite(LED, LOW);
      digitalWrite(BUZZ, HIGH);
      trigger = false;
    }
  }
  else{
    if(digitalRead(BUTTON) == LOW){
      blink = !blink;
      digitalWrite(LED, HIGH);
      digitalWrite(BUZZ, LOW);
      trigger = true;
      Serial.println("Zmackl jsem tlacitko");
    }
  }
}
