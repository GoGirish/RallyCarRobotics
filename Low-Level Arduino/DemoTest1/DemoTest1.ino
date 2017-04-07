#include "Servo.h"
#include "Motor.h"

const int button1Pin = 2;
const int button2Pin = 3;
const int button3Pin = 4;
Servo steering;
Servo drive;
int button1State = 0;
int button2State = 0;
int button3State = 0;
int i = 0;

void setup() 
{
  // put your setup code here, to run once:
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
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
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  button3State = digitalRead(button3Pin);
  

  if (button1State == HIGH)
  {
    //button2State = LOW;
    DriftLeft();
  }

  if (button2State == HIGH)
  {
    //button1State = LOW;
    DriftRight();
  }
  
  if (button3State == HIGH)
  {
    DriftJ_Turn();
    button3State = LOW;
  }
}

void DriftRight()
{
    steering.write(86);
    delay(2000);
    drive.writeMicroseconds(2000);
    delay(1000);
    steering.write(26);
    delay(10);
    drive.writeMicroseconds(1120);
    //drive.Brake();

    delay (1000);
    steering.write(86);
    drive.writeMicroseconds(1550);
    delay(1000);
    steering.write(86);
    drive.writeMicroseconds(1500);
}

void DriftLeft()
{
    steering.write(86);
    delay(2000);
    drive.writeMicroseconds(2000);
    delay(1000);
    steering.write(146);
    delay(10);
    drive.writeMicroseconds(1120);
    //drive.Brake();

    delay (1000);
    steering.write(86);
    drive.writeMicroseconds(1550);
    delay(1000);
    steering.write(86);
    drive.writeMicroseconds(1500);
}

void DriftJ_Turn()
{
    steering.write(86);
    delay(2000);
    drive.writeMicroseconds(2000);
    delay(900);
    steering.write(26);
    //drive.writeMicroseconds(1500);
    delay(500);
    drive.writeMicroseconds(1500);
    delay(200);
    drive.writeMicroseconds(1000);
    //steering.write(44);

    
    delay(700);
    steering.write(86);
    //CONSIDER DROPPING.
    //drive.writeMicroseconds(1500);
}




