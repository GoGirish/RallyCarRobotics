#include "Motor.h"
#include <Servo.h>
//Servo s;
Motor motor;
void setup() 
{
  // put your setup code here, to run once:
  //  Serial.begin(9600);  
  //  Serial.println("--- Start Serial Monitor ---");
  //    Serial.println(" Type in Box above, . ");
  //  Serial.println("ENTER DUTY CYCLE IN MICROSECONDS");  
  //  Serial.println(); 
  //s.attach(9);
  motor.setup(9);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  //motor.fullSpeedForward();
  motor.speed(40);
  //motor.writeMicroseconds(1700);
  //s.writeMicroseconds(1800);
}

