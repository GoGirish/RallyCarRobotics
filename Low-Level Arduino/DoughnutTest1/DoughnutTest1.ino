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
  delay(2000);
  while (i < 2)
  {
        // put your main code here, to run repeatedly:
    steering.write(28);
    delay(200);
    drive.writeMicroseconds(2000);
    delay(500);
    i = 4;
  }
}
