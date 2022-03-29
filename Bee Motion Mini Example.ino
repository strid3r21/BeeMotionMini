#include "Arduino.h"



const int sensorPin = 5;    // Pin number the PIR sensor is on
const int ledpin = 2;       // Pin Number the LED is on
int sensorValue = LOW;



void setup() {
  Serial.begin(115200);
  

  pinMode(ledpin, OUTPUT);
  pinMode(sensorPin, INPUT);
}


void loop() {
  sensorValue = digitalRead(sensorPin);
  
  if(sensorValue == HIGH){

    Serial.println("ON!");
    digitalWrite(ledpin, HIGH);   
  delay(500);
  }else if(sensorValue == LOW){
    Serial.println("OFF!");
    digitalWrite(ledpin, LOW);    
  delay(500); 

  }
}
