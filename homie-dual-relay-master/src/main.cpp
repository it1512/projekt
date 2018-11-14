#include <ESP8266WiFi.h>
#include <Homie.h>

int led = 2;

void setup() {
  Serial.begin(115200);
  Serial << endl << endl;

  Homie_setFirmware("mqtt", "1.0.0");
  Homie.setup();

  pinMode(led, OUTPUT);
}


void loop() {
    digitalWrite(led, HIGH);
  Homie.loop();
}