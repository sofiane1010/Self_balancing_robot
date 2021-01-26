#include <Arduino.h>
#include <stepper.h>

int driverPUL = 18;    // PUL- pin
int driverDIR = 19;    // DIR- pin
float pd;   

void run(int position){
  for (int i = 0; i < position;i++){
      digitalWrite(driverPUL,HIGH);
      delayMicroseconds(pd);
      digitalWrite(driverPUL,LOW);
      delayMicroseconds(pd);
  }
}

void setSpeed(int stepPerSec) {
  if(stepPerSec > 0) digitalWrite(driverDIR, HIGH);
  if(stepPerSec < 0) digitalWrite(driverDIR, LOW);
  pd = (500*1000) / abs(stepPerSec); // règle de 3 (stepPerSec => 1000ms, 1step => 2pd)
  if (pd < 400.00)
    pd = 400.00;
}