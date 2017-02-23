#include "Arduino.h"
#include "Morse.h"
#include "Servo.h"

Servo drive;

Motor::Motor(int pin)
{
  drive.attach(pin);
  drive.writeMicroseconds(1500);
}

void Motor::fullSpeedForward()
{
  drive.writeMicroseconds(2000);
}

void Motor::fullSpeedBackward()
{
  drive.writeMicroseconds(1000);
}

void Motor::Brake()
{
  drive.writeMicroseconds(1500);
}
