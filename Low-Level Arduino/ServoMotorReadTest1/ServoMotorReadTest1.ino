#include "Servo.h"

Servo steering;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  steering.attach(10);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  int angle = steering.read();
  Serial.print(angle);
  Serial.print("\n");9
}
