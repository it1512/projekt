/*
 *   Tested with "WiFi Smart Socket ESP8266 MQTT"
 *   and "Sonoff - WiFi Wireless Smart Switch ESP8266 MQTT"
 *
 *   The Relay could be toggeled with the physical pushbutton
*/

#include <Homie.h>

//const int PIN_LED = 5;
const int PIN_LASER = 4;
/*const int PIN_TRANSISTOR = 2;
const int PIN_OFF = 1;
const int PIN_BUTTON = 0;*/

int counter = 0;
bool triggered = true;

/*unsigned long buttonDownTime = 0;
byte lastButtonState = 1;
byte buttonPressHandled = 0;*/

HomieNode switchNode("switch", "switch");

/*bool switchOnHandler(HomieRange range, String value) {
  if (value != "true" && value != "false") return false;

  bool on = (value == "true");
  digitalWrite(PIN_RELAY, on ? HIGH : LOW);
  switchNode.setProperty("on").send(value);
  Homie.getLogger() << "Switch is " << (on ? "on" : "off") << endl;

  return true;
}*/

/*void toggleRelay() {
  bool on = digitalRead(PIN_RELAY) == HIGH;
  digitalWrite(PIN_RELAY, on ? LOW : HIGH);
  switchNode.setProperty("on").send(on ? "false" : "true");
  Homie.getLogger() << "Switch is " << (on ? "off" : "on") << endl;
}*/

/*void loopHandler() {
  byte buttonState = digitalRead(PIN_BUTTON);
  if ( buttonState != lastButtonState ) {
    if (buttonState == LOW) {
      buttonDownTime     = millis();
      buttonPressHandled = 0;
    }
    else {
      unsigned long dt = millis() - buttonDownTime;
      if ( dt >= 90 && dt <= 900 && buttonPressHandled == 0 ) {
        toggleRelay();
        buttonPressHandled = 1;
      }
    }
    lastButtonState = buttonState;
  }
}*/

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println();
  //pinMode(PIN_BUTTON, INPUT);
  pinMode(PIN_LASER, OUTPUT);
  /*pinMode(PIN_TRANSISTOR, INPUT);
  pinMode(PIN_OFF, INPUT);
  pinMode(PIN_LED, OUTPUT);*/
  analogWrite(PIN_LASER, 80);


  Homie_setFirmware("itead-sonoff-buton", "1.0.0");
  //Homie.setLedPin(PIN_LED, LOW).setResetTrigger(PIN_BUTTON, LOW, 5000);

  //switchNode.advertise("on").settable(switchOnHandler);

  //Homie.setLoopFunction(loopHandler);
  Homie.setup();
}

void loop() {
  /*if (triggered)
  {
      if (digitalRead(PIN_TRANSISTOR) == HIGH)
        {
          if (counter == 1000)
          {
            Homie.getLogger() << "Safe" << endl;
            counter = 0;
          }
          else
            counter++;
        }
        else
        {
          //analogWrite(PIN_LASER, 0);
          digitalWrite(PIN_LED, HIGH);
          triggered = false;
          Homie.getLogger() << "Intruder" << endl;
        }
  }
  else
  {
      if (digitalRead(PIN_OFF) == HIGH)
      {
        //analogWrite(PIN_LASER, 80);
        digitalWrite(PIN_LED, LOW);
        triggered = true;
        Homie.getLogger() << "Safed" << endl;
      }
  }*/
  Homie.loop();
}