//#include <arduino.h>

int ldr = 17; //analogovy pin kde je pripojeno LDR
int ldr_value = 0; //variable to store LDR values
int LED = 5;
int LASER = 4;
int BUTTON = 2;
bool trigger = true;
 
void setup()
{
 Serial.begin(9600); //spuštění serioveho rozhrani
 pinMode(LED, OUTPUT);
 pinMode(LASER, OUTPUT);
 digitalWrite(LASER, HIGH);
 pinMode(BUTTON, INPUT);
}
 
void loop()
{
 ldr_value = analogRead(ldr); //čte hodnoty LDR
 Serial.println(ldr_value); //zobrazí hodnoty LDR na seriove lince
 if (trigger){
    if (ldr_value < 800) {
        Serial.println("mensi nez tisic");
        //digitalWrite(LED, LOW);
    } 
    else {
        Serial.println("jsem v elsu pico");
        trigger = false;
        digitalWrite(LED, HIGH);
    }
 }
 else{
     if(digitalRead(BUTTON) == LOW){
         trigger = true;
         digitalWrite(LED, LOW);
         Serial.println("zmackl jsi tlacitko"); 
     }
     else{
        Serial.println("Nezmackl jsi tlacitko"); 
     }
 }
 delay(500); //wait

}
