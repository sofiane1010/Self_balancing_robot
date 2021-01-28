#include <Arduino.h>
#include <stepper.h>

Stepper::Stepper(int dirPin, int stepPin){
  this->dirPin = dirPin;
  this->stepPin = stepPin;
  this->currentPos = 0;
  this->initialPeriode = 2000;
  this->accelInterval = 20;
}

void Stepper::run() {

  this->currentPeriode = this->initialPeriode;
  this->currentSpeed = (1000000) / (2 * this->initialPeriode);

  int prevTime = millis();
  for (int i = 0; i < this->targetPosition;i++){
    if(millis() - prevTime >= this->accelInterval) {
      prevTime = millis();
      this->setCurrentSpeed();
    }
    digitalWrite(this->stepPin,HIGH);
    delayMicroseconds(this->currentPeriode < this->finalPeriode ? this->finalPeriode : this->currentPeriode);
    digitalWrite(this->stepPin,LOW);
    delayMicroseconds(this->currentPeriode < this->finalPeriode ? this->finalPeriode : this->currentPeriode);
    this->currentPos++;
  }
  this->currentPos = 0;
}

void Stepper::setMaxSpeed(int maxStepPerSec){
  this->minPeriode = (1000000) / (2*abs(maxStepPerSec)); // règle de 3 (stepPerSec => 1000ms, 1step => 2periode)
}

void Stepper::setSpeed(int stepPerSec){
  if(stepPerSec > 0) digitalWrite(this->dirPin, HIGH);
  if(stepPerSec < 0) digitalWrite(this->dirPin, LOW);
  this->finalPeriode = (1000000) / (2*abs(stepPerSec)); // règle de 3 (stepPerSec => 1000ms, 1step => 2periode)
  if (this->finalPeriode < this->minPeriode)
    this->finalPeriode = this->minPeriode;
}

void Stepper::setCurrentSpeed(){
  if((int)this->targetPosition/2 > this->currentPos){
    this->currentSpeed += this->acceleration * this->accelInterval/1000;
    this->currentPeriode = 1000000 / (2 * this->currentSpeed);
  } else {
    this->currentSpeed -= this->acceleration * 0.02;
    this->currentPeriode = 1000000 / (2 * this->currentSpeed);
    this->currentPeriode = this->currentPeriode > this->initialPeriode ? this->initialPeriode : this->currentPeriode;
  }
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

void Stepper::setAcceleration(int accel){
  this->acceleration = accel;
}