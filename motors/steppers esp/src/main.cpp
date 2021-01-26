#include <Arduino.h>
#include <stepper.h>

void setup() {
  pinMode (18, OUTPUT);
  pinMode (19, OUTPUT);
  digitalWrite(19, HIGH);
  Serial.begin(115200);
}
 
void loop() {
  setSpeed(1000);
  run(1000);
  setSpeed(-1000);
  run(1000);
}