#include "Servo.h"

#define NEUTRAL 1500
#define FORWARD_MAX 2000
#define REVERSE_MAX 1000

Servo drive;
Servo drive1;
Servo drive2;

void setup() 
{
  // put your setup code here, to run once:
  drive.attach(9);
  drive1.attach(10);
  drive2.attach(11);
  drive.writeMicroseconds(1500);
//
  //arm your ESC motor:
  drive.writeMicroseconds(0);
  delay(1000);
  drive.writeMicroseconds(NEUTRAL);
  delay(100);
}

void loop() 
{
  // put your main code here, to run repeatedly:

  //drive ESC motor forward.
  drive.writeMicroseconds(1500);
  drive1.writeMicroseconds(1600);
  drive2.writeMicroseconds(1400);
  //drive.writeMicroseconds(1850);
}
