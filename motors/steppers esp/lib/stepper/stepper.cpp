#include <Arduino.h>
#include <stepper.h>

Stepper::Stepper(int dirPin, int stepPin){
  this->dirPin = dirPin;
  this->stepPin = stepPin;
  this->currentPos = 0;
}

void Stepper::run() {
    for (int i = 0; i < this->targetPosition;i++){
      digitalWrite(this->stepPin,HIGH);
      delayMicroseconds(this->periode);
      digitalWrite(this->stepPin,LOW);
      delayMicroseconds(this->periode);
      this->currentPos++;
  }
}

void Stepper::setMaxSpeed(int maxStepPerSec){
  this->minPeriode = (1000000) / (2*abs(maxStepPerSec)); // règle de 3 (stepPerSec => 1000ms, 1step => 2periode)
}

void Stepper::setSpeed(int stepPerSec){
  if(stepPerSec > 0) digitalWrite(this->dirPin, HIGH);
  if(stepPerSec < 0) digitalWrite(this->dirPin, LOW);

  this->periode = (1000000) / (2*abs(stepPerSec)); // règle de 3 (stepPerSec => 1000ms, 1step => 2periode)
  if (this->periode < this->minPeriode)
    this->periode = this->minPeriode;
}

int Stepper::currentPosition(){
  return this->currentPos;
}

void Stepper::setCurrentPosition(int newPosition){
  this->currentPos = newPosition;
}

void Stepper::moveTo(int targetPosition){
  this->targetPosition = targetPosition;
}