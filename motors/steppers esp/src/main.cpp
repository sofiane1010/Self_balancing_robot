#include <Arduino.h>
#include <stepper.h>

const int dirPin1 = 19;
const int stepPin1 = 18;
const int dirPin2 = 33;
const int stepPin2 = 32;
int flag = true;

Stepper steppers(dirPin1, stepPin1, dirPin2, stepPin2);

void setup() {
  pinMode (stepPin1, OUTPUT);
  pinMode (dirPin1, OUTPUT);
  pinMode (stepPin2, OUTPUT);
  pinMode (dirPin2, OUTPUT);
  Serial.begin(115200);
  steppers.setMaxSpeed(10000);
  steppers.setAcceleration(5000);
}
 
void loop() {
  if(flag){
  steppers.moveTo(-2000, "translate");
  steppers.setSpeed(5000);
  steppers.run();
  flag = false;
  }

}