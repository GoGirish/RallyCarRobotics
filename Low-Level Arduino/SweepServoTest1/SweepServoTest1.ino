/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() 
{
  myservo.attach(10);  // attaches the servo on pin 9 to the servo object
//  for (val = 0; val <= 2000; val += 1)
//  {
//    myservo.writeMicroseconds(val);
//    delay(5);
//  }
  //myservo.writeMicroseconds(2000);
}

void loop() 
{
//  for (pos = 45; pos <= 135; pos += 1) { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(5);                       // waits 15ms for the servo to reach the position
//  }
//  
//  for (pos = 135; pos >= 45; pos -= 1) { // goes from 180 degrees to 0 degrees
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(5);                       // waits 15ms for the servo to reach the position
//  }
    myservo.write(50);

   // myservo.writeMicroseconds(1600);

//    myservo.writeMicroseconds(1600);
//    delay(5000);
//    myservo.writeMicroseconds(1500);
//    delay(5000);

}
