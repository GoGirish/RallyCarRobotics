/*
 * ServoControl.h - Library for controlling the drive motor for the rally car
 * Created by Govind "Go" Girish and Alex Lutkenhouse
 */

#ifndef ServoControl
#define ServoControl

#include "Arduino.h"
#include "Servo.h"

class ServoControl
{
  public:
    //Motor (int _pin);
    void writeMicroseconds(int microseconds);
    void fullRight();
    void fullLeft();
    void setup(int pin);
    void calibrate(int calAngle);
    void setAngle(int angle);
  private:
    int _pin;
    int _midAngle;
    int _maxRightAngle;
    int _maxLeftAngle;
    Servo _steering;
    int _pwm_in_ms;
};

#endif