#include "Arduino.h"
#include "Motor.h"
#include "Servo.h"

Servo drive;

// Motor::Motor(int pin)
// {
//   drive.attach(pin);
//   //drive.writeMicroseconds(1500);
//   drive.writeMicroseconds(0);
//   delay(1000);
//   drive.writeMicroseconds(1500);
//   delay(100);
// }

void Motor::setup(int pin)
{
  drive.attach(pin);
  //drive.writeMicroseconds(1500);
  drive.writeMicroseconds(0);
  delay(1000);
  drive.writeMicroseconds(1500);
  delay(100);
}

void Motor::fullSpeedForward()
{
  drive.writeMicroseconds(1700);
}

void Motor::fullSpeedBackward()
{
  drive.writeMicroseconds(1000);
}

void Motor::Brake()
{
  drive.writeMicroseconds(1500);
}

void Motor::writeMicroseconds(int microseconds)
{
  drive.writeMicroseconds(microseconds);
}

//int s = the power of thrust. 100 is full power forward. 0 is full brake. -100 is full power backwards.
void Motor::speed(int s)
{
  if (s > 100)
  {
    s = 100;
  }
  if (s < -100)
  {
    s = -100;
  }
  //takes the difference between brake and full power (2000 - 1500 = 500. Similarly, backwards full power is 1000. 1500 - 1000 = 500).
  //multiplies the difference by the percentage form of s (40 = 40%, -30 = -30%). Then adds this number to 1500.
  int x = (500*(s/100))+1500;
  int a = s/100;
  int b = 500*a;
  int c = b + 1500;
  drive.writeMicroseconds(c);
}