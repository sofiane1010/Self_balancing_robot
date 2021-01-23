#include <Arduino.h>
#include <stdio.h>

const int stepPin = 3; 
const int dirPin = 2;


void setup() {
  pinMode(dirPin,OUTPUT); 
  pinMode(stepPin,OUTPUT);
}
void loop() {
  digitalWrite(dirPin, HIGH);
  for (int i = 0; i < 4000; i++){  
    digitalWrite(stepPin, LOW);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(60);
  }
  delay(500);
  digitalWrite(dirPin, LOW);
  for (int i = 0; i < 4000; i++){  
    digitalWrite(stepPin, LOW);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(100);
  }
  delay(500);
  }