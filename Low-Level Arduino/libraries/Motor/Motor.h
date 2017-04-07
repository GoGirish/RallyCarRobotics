/*
 * Motor.h - Library for controlling the drive motor for the rally car
 * Created by Govind "Go" Girish and Alex Lutkenhouse
 */

#ifndef Motor_h
#define Motor_h

#include "Arduino.h"
#include "Servo.h"

class Motor
{
  public:
    //Motor (int _pin);
    void writeMicroseconds(int microseconds);
    void fullSpeedForward();
    void setup(int pin);
    void fullSpeedBackward();
    void Brake();
    void speed(int s);
  private:
    int _pin;
    Servo _drive;
    int _pwm_in_ms;
};

#endif