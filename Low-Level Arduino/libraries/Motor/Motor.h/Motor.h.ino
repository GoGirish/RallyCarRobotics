/*
 * Motor.h - Library for controlling the drive motor for the rally car
 * Created by Govind "Go" Girish and Alex Lutkenhouse
 */

#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor
{
  public:
    Motor (int _pin);
    void fullSpeedForward();
    void fullSpeedBackward();
    void Brake();
  private:
    int _pin;
};

#endif
