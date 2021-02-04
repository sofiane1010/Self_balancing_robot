#include <Arduino.h>
#include <MPU6050_light.h>

MPU6050 mpu(Wire);

long timer = 0;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  byte status = mpu.begin();
  mpu.setFilterAccCoef(0.04);
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  while(status!=0){ } // stop everything if could not connect to MPU6050
}

void loop() {
  mpu.update();

  if(millis() - timer > 20){ // print data every second
    
    Serial.print(F("ANGLE     X: "));Serial.print(mpu.getAngleX());
    Serial.print("\tY: ");Serial.print(mpu.getAngleY());
    Serial.print("\tZ: ");Serial.println(mpu.getAngleZ());
    timer = millis();
  }

}