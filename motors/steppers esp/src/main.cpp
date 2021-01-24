 #include <Arduino.h>
 #include <AccelStepper.h>
 
// int driverPUL = 18;    // PUL- pin
// int driverDIR = 19;    // DIR- pin
 
// // Variables
 
// int pd = 400;       // Pulse Delay period
// boolean setdir = LOW; // Set Direction
 
// // Interrupt Handler
 
// void setup() {
 
//   pinMode (driverPUL, OUTPUT);
//   pinMode (driverDIR, OUTPUT);
  
// }
 
// void loop() {
  
//     digitalWrite(driverDIR,setdir);
//     digitalWrite(driverPUL,HIGH);
//     delayMicroseconds(pd);
//     digitalWrite(driverPUL,LOW);
//     delayMicroseconds(pd);
 
// }

AccelStepper stepper3(AccelStepper::FULL2WIRE, 18,19);

void setup()
{  
    stepper3.setMaxSpeed(300.0);
    stepper3.setAcceleration(100.0);
    stepper3.moveTo(1000000);
    Serial.begin(9600);
}

void loop()
{
    // Change direction at the limits
    stepper3.run();
    Serial.println("coucou");
}