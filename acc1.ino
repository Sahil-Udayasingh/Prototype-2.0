/*
 * 
 * This code is basic usage MPU-6050 Accelerometer and Gyroscope
 * 
 * This code displays all data:
 * -GyroScopeX, Gyro Y, Gyro Z
 * -Gyro Angle X, Gyro Angle Y, Gyro Angle Z 
 * -Accel X, Accel Y, Accel Z
 * -Accel Angle X, Accel Angle Y,Accel Angle Z,
 * 
 * Library and code have been taken from:
 * https://github.com/tockn/MPU6050_tockn
 * 
 * Updated by Ahmad Shamshiri on July 03, 2018 in Ajax, Ontario, Canada
 * for Robojax.com
 * Get this code from Robojax.com
 * Watch video instruction for this code at:https://youtu.be/uhh7ik02aDc
 * 
 */
#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

long timer = 0;
float x,y,z,cb;
int count=0,target=20;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
}

void loop() {
  int ldr=analogRead(A3);
  Serial.println(ldr);
  delay(500);
  mpu6050.update();

  if(millis() - timer > 1000){
    /*
    Serial.println("=======================================================");
    Serial.print("temp : ");Serial.println(mpu6050.getTemp());
    Serial.print("accX : ");Serial.print(mpu6050.getAccX());
    Serial.print("  accY : ");Serial.print(mpu6050.getAccY());
    Serial.print("  accZ : ");Serial.println(mpu6050.getAccZ());
  
    Serial.print("gyroX : ");Serial.print(mpu6050.getGyroX());
    Serial.print("  gyroY : ");Serial.print(mpu6050.getGyroY());
    Serial.print("  gyroZ : ");Serial.println(mpu6050.getGyroZ());
  
    Serial.print("accAngleX : ");Serial.print(mpu6050.getAccAngleX());
    Serial.print("  accAngleY : ");Serial.println(mpu6050.getAccAngleY());
  
    Serial.print("gyroAngleX : ");Serial.print(mpu6050.getGyroAngleX());
    Serial.print("  gyroAngleY : ");Serial.print(mpu6050.getGyroAngleY());
    Serial.print("  gyroAngleZ : ");Serial.println(mpu6050.getGyroAngleZ());
    
    Serial.print("angleX : ");Serial.print(mpu6050.getAngleX());
    Serial.print("  angleY : ");Serial.print(mpu6050.getAngleY());
    Serial.print("  angleZ : ");Serial.println(mpu6050.getAngleZ());
    Serial.println("=======================================================");
    */
    timer = millis();

    if((mpu6050.getGyroAngleX()-x>3.5||mpu6050.getGyroAngleX()-x<(-3.5)||mpu6050.getGyroAngleY()-y<(-3.5)||mpu6050.getGyroAngleY()-y>3.5||mpu6050.getGyroAngleZ()-z<(-3.5)||mpu6050.getGyroAngleZ()-z>3.5)&&(ldr>200))
    {
    count=count+2;
    }
   else if((mpu6050.getGyroAngleX()-x>3.5||mpu6050.getGyroAngleX()-x<(-3.5)||mpu6050.getGyroAngleY()-y<(-3.5)||mpu6050.getGyroAngleY()-y>3.5||mpu6050.getGyroAngleZ()-z<(-3.5)||mpu6050.getGyroAngleZ()-z>3.5)&&(ldr<200))
    {
    count=count+1;
    }
    Serial.println(count);
    cb=(count/20);
    Serial.println(cb);
    if(count>target)
    {
        digitalWrite(13,HIGH);
        digitalWrite(12,LOW);
    }
    else
    {
        digitalWrite(12,HIGH);  
        digitalWrite(13,LOW);  

    }
    
    x=mpu6050.getGyroAngleX();
    y=mpu6050.getGyroAngleY();
    z=mpu6050.getGyroAngleZ();
    
    }

} 
