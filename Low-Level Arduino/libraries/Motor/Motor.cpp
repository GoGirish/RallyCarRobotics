#include "Arduino.h"
#include "Motor.h"
#include "Servo.h"

// Motor::Motor(int pin)
// {
//   __drive.attach(pin);
//   //_drive.writeMicroseconds(1500);
//   _drive.writeMicroseconds(0);
//   delay(1000);
//   _drive.writeMicroseconds(1500);
//   delay(100);
// }

void Motor::setup(int pin)
{
  _drive.attach(pin);
  _pin = pin;
  //_drive.writeMicroseconds(1500);
  _drive.writeMicroseconds(0);
  delay(1000);
  _drive.writeMicroseconds(1500);
  delay(100);
  _pwm_in_ms = 1500;
}

void Motor::fullSpeedForward()
{
  _drive.writeMicroseconds(2000);
  _pwm_in_ms = 2000;
}

void Motor::fullSpeedBackward()
{
  _drive.writeMicroseconds(1000);
  _pwm_in_ms = 1000;
}

void Motor::Brake()
{
  //NOTE THAT THIS BRAKE IS PURELY EXPERIMENTAL.

  // _drive.writeMicroseconds(1500);
  // _pwm_in_ms = 1500;
  int brakeSpeed = 1500 - (_pwm_in_ms-1500);
  writeMicroseconds(brakeSpeed);
  delay(100);
  writeMicroseconds(1500);
}

void Motor::writeMicroseconds(int microseconds)
{
  _drive.writeMicroseconds(microseconds);
  _pwm_in_ms = microseconds;
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
  double a = ((double)s)/100;
  int b = (int)(500*a);
  int c = b + 1500;
  _drive.writeMicroseconds(c);
  _pwm_in_ms = c;
}