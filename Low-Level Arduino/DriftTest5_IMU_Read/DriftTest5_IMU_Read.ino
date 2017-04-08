#include "Servo.h"
#include "Motor.h"

unsigned long currentMillis = 0;

const int button1Pin = 2;
//const int button2Pin = 3;
////const int button3Pin = 4;
Servo steering;
Servo drive;
int button1State = 0;
//int button2State = 0;
//int button3State = 0;
int i = 0;

//IMU Initalization
#include<Wire.h>
const int MPU_addr=0x68;  // I2C address of the MPU-6050
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;


void setup() {
  //IMU Setup
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);

  
  currentMillis = 0;
  // put your setup code here, to run once:
  //pinMode(button1Pin, INPUT);
  //pinMode(button2Pin, INPUT);
  //pinMode(button3Pin, INPUT);
  Serial.begin(9600);
  steering.attach(10);
  drive.attach(9);
  steering.write(86);
  //arm ESC (electronic speed control).
  drive.writeMicroseconds(0);
  delay(1000);
  drive.writeMicroseconds(1500);
  delay(100);
  i = 0;
}

void loop() 
{
  // put your main code here, to run repeatedly:
  currentMillis = millis();

  //Print IMU Data to Serial Monitor
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
  AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)     
  AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Tmp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  GyX=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
//
//  
  Serial.print(currentMillis);
  Serial.print("\t");
  Serial.print(AcX); Serial.print("\t");
  Serial.print(AcY); Serial.print("\t");
//  Serial.print(AcZ); Serial.print("\t");
  Serial.print(GyX); Serial.print("\t");
//  Serial.print(GyY); Serial.print("\t");
//  Serial.print(GyZ); Serial.print("\n");
//  
//
//
//  //pu6 o6e h4q
    
  if (currentMillis < 6000)
  {
    DriftLeft();
  }
}

void DriftLeft()
{
  if (currentMillis >= 0 && currentMillis <= 2000)
  {
    steering.write(86);
    //delay(2000);
  }

  else if (currentMillis >= 2001 && currentMillis <= 3000)
  {
    drive.writeMicroseconds(2000);
    //delay(1000);
  }

  else if (currentMillis <= 3010)
  {
    steering.write(146);
    //delay(10);
  }

  else if (currentMillis <= 4010)
  {
    drive.writeMicroseconds(1120);
    //drive.Brake();

    //delay (1000);
  }

  else if (currentMillis <= 5010)
  {
    steering.write(86);
    drive.writeMicroseconds(1550);
    //delay(1000);
  }

  else
  {
    steering.write(86);
    drive.writeMicroseconds(1500);
  }
}
