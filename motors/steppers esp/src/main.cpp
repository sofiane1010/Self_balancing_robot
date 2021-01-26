#include <Arduino.h>
#include <stepper.h>

const int dirPin = 19;
const int stepPin = 18;

Stepper stepper1(dirPin, stepPin);

void setup() {
  pinMode (stepPin, OUTPUT);
  pinMode (dirPin, OUTPUT);
  Serial.begin(115200);
  stepper1.setMaxSpeed(10000);
}
 
void loop() {
  float t = millis();
  stepper1.moveTo(400000);
  stepper1.setSpeed(2000000);
  stepper1.setAcceleration(1000);
  stepper1.run();
  Serial.println((millis() - t)/1000);
  delay(1000);
}