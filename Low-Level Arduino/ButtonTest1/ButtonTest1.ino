#include "Servo.h"

const int buttonPin = 2;
Servo steering;
int buttonState = 0;

void setup() 
{
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  steering.attach(10);
}

void loop() 
{
  
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH)
  {
    steering.write(40);
  }
  if (buttonState == LOW)
  {
    steering.write(90);
  }
}
