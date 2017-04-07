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
  while (i < 2)
  {
    drive.writeMicroseconds(2000);
    delay(900);
    //steering.write(100);
    //delay(100);
    steering.write(26);
    //drive.writeMicroseconds(1500);
    delay(500);
    drive.writeMicroseconds(1500);
    delay(200);
    drive.writeMicroseconds(1000);
    //steering.write(44);

    
    delay(700);
    //steering.write(91);
    //
    //brakes the car
    
    i = 4;
  }
  steering.write(86);
  //drive.writeMicroseconds(1500);
}
