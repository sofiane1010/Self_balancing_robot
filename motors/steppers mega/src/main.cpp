#include <Arduino.h>
 
int driverPUL = 7;    // PUL- pin
int driverDIR = 6;    // DIR- pin
 
// Variables
 
int pd = 400;       // Pulse Delay period
boolean setdir = LOW; // Set Direction
 
// Interrupt Handler
 
void setup() {
 
  pinMode (driverPUL, OUTPUT);
  pinMode (driverDIR, OUTPUT);
  
}
 
void loop() {
  
    digitalWrite(driverDIR,setdir);
    digitalWrite(driverPUL,HIGH);
    delayMicroseconds(pd);
    digitalWrite(driverPUL,LOW);
    delayMicroseconds(pd);
 
}