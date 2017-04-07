#include "Arduino.h"
#include "Servo.h"
#include "ServoControl.h"

//The angles of steering go from 50 degrees (full left) to 130 degrees (full right).

void ServoControl::setup(int pin, int cAngle)
{
    _steering.attach(pin);
    _pin = pin;
    calibrate(cAngle);
    //_drive.writeMicroseconds(1500);
    // _steering.writeMicroseconds(0);
    // delay(1000);
    // _steering.writeMicroseconds(1500);
    // delay(100);
    // _pwm_in_ms = 1500;
}

void ServoControl::fullLeft()
{
    _steering.write(_maxLeftAngle);
}

void ServoControl::fullRight()
{
    _steering.write(_maxRightAngle);
}

void ServoControl::writeMicroseconds(int microseconds)
{
    _steering.writeMicroseconds(microseconds);
}

void ServoControl::setAngle(int angle)
{
    _steering.write(_midAngle + angle);
    // int sAngle = angle + cAngle;
    // _steering.write(sAngle);
}

void ServoControl::calibrate(int calAngle)
{
    //If calAngle is positive, that means the steering was veering to the left, and this is shifting the steering to the right by "calAngle".
    //If calAngle is negative, that means the steering was veering to the right, and this is shifting the steering to the left by "calAngle".
    _midAngle = 90 + calAngle;
    _maxLeftAngle = _midAngle - 50;
    _maxRightAngle = _midAngle + 50;
}