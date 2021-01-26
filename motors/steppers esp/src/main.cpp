#include <Arduino.h>
#include <stepper.h>

const int dirPin = 19;
const int stepPin = 18;

Stepper stepper1(dirPin, stepPin);

void setup() {
  pinMode (stepPin, OUTPUT);
  pinMode (dirPin, OUTPUT);
  Serial.begin(115200);
  stepper1.setMaxSpeed(1250);
}
 
void loop() {
  stepper1.moveTo(1250);
  stepper1.setSpeed(2000);
  stepper1.run();
  stepper1.moveTo(1250);
  stepper1.setSpeed(-2000);
  stepper1.run();
}