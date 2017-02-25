#include <Servo.h>

Servo drive;
Servo steering;
int i;

void setup() 
{
  // put your setup code here, to run once:
  drive.attach(9);
  steering.attach(10);
  //steering.writeMicroseconds(1500);
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
  while (i <2)
  {
    drive.writeMicroseconds(1900);
    delay(1000);
    
    drive.writeMicroseconds(1100);
    steering.write(128);

    
    delay(1000);
    //steering.write(91);
    //
    //brakes the car
    
    i = 4;
  }
  drive.writeMicroseconds(1500);
}
