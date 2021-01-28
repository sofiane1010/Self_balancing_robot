#include <Arduino.h>
#include <stepper.h>
#include <string>

Stepper::Stepper(int dirPin1, int stepPin1, int dirPin2, int stepPin2){
  this->dirPin1 = dirPin1;
  this->stepPin1 = stepPin1;
  this->dirPin2 = dirPin2;
  this->stepPin2 = stepPin2;
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
    digitalWrite(this->stepPin2,HIGH);
    digitalWrite(this->stepPin1,HIGH);
    delayMicroseconds(this->currentPeriode < this->finalPeriode ? this->finalPeriode : this->currentPeriode);
    digitalWrite(this->stepPin2,LOW);
    digitalWrite(this->stepPin1,LOW);
    delayMicroseconds(this->currentPeriode < this->finalPeriode ? this->finalPeriode : this->currentPeriode);
    this->currentPos++;
  }
  this->currentPos = 0;
}


void Stepper::setMaxSpeed(int maxStepPerSec){
  this->minPeriode = (1000000) / (2*abs(maxStepPerSec)); // règle de 3 (stepPerSec => 1000ms, 1step => 2periode)
}

void Stepper::setSpeed(int stepPerSec){
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

void Stepper::moveTo(int targetPosition, std::string runMode){
  if(targetPosition > 0) {
    if(runMode == "translate"){
      digitalWrite(this->dirPin1, HIGH);
      digitalWrite(this->dirPin2, LOW);
    }
    else{
      digitalWrite(this->dirPin1, HIGH);
      digitalWrite(this->dirPin2, HIGH);
    }
  }
  if(targetPosition < 0) {
    if(runMode == "translate"){
      digitalWrite(this->dirPin1, LOW);
      digitalWrite(this->dirPin2, HIGH);
    }
    else{
      digitalWrite(this->dirPin1, LOW);
      digitalWrite(this->dirPin2, LOW);
    }
  }
  this->targetPosition = abs(targetPosition);
}

void Stepper::setAcceleration(int accel){
  this->acceleration = accel;
}