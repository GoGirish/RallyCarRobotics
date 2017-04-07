#include "Motor.h"
#include "Servo.h"

Motor drive;
Servo steering;
int i = 0;

void setup() 
{
  // put your setup code here, to run once:
  drive.setup(9);
  steering.attach(10);
  steering.write(86);
  delay(1000);
  i = 0;
}

void loop() 
{
  // put your main code here, to run repeatedly:
  while (i < 2)
  {
    drive.fullSpeedForward();
    delay(1000);
    steering.write(26);
    delay(10);
    drive.writeMicroseconds(1120);
    //drive.Brake();

    delay (1000);
    steering.write(86);
    drive.writeMicroseconds(1550);
    delay(1000);
    //steering.write(86);
    i = 4;
  }
  steering.write(86);
  drive.writeMicroseconds(1500);
}
