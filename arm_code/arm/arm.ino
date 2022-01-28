/*

  Parts required:
  - servo motor
  - 10 kilohm potentiometer
  - two 100 uF electrolytic capacitors


*/

// include the Servo library
#include <Servo.h>

Servo servoRot;  // create a servo object
Servo servoArm1;
Servo servoArm2;
Servo servoClaw;


int const potPinServoRot = A0; // analog pin used to connect the potentiometer
int const potPinServoArm1 = A1; // analog pin used to connect the potentiometer
int const potPinServoArm2 = A2; // analog pin used to connect the potentiometer
int const potPinServoClaw = A3; // analog pin used to connect the potentiometer
int potValServoRot;  // variable to read the value from the analog pin
int potValServoArm1;  // variable to read the value from the analog pin
int potValServoArm2;  // variable to read the value from the analog pin
int potValServoClaw;  // variable to read the value from the analog pin
int angleServoRot;   // variable to hold the angle for the servo motor
int angleServoArm1;   // variable to hold the angle for the servo motor
int angleServoArm2;   // variable to hold the angle for the servo motor
int angleServoClaw;   // variable to hold the angle for the servo motor


void setup() {
  servoRot.attach(5); // attaches the servo on pin 9 to the servo object
  servoArm1.attach(9);
  servoArm2.attach(10);
  servoClaw.attach(11);
  Serial.begin(9600); // open a serial connection to your computer
}

void loop() {

  
  potValServoRot = analogRead(potPinServoRot); // read the value of the potentiometer
  Serial.print("potValServoRot: ");
  Serial.print(potValServoRot);
  potValServoArm1 = analogRead(potPinServoArm1); // read the value of the potentiometer
  Serial.print("potValServoArm1: ");
  Serial.print(potValServoArm1);
  potValServoArm2 = analogRead(potPinServoArm2); // read the value of the potentiometer
  Serial.print("potValServoArm2: ");
  Serial.print(potValServoArm2);
  potValServoClaw = analogRead(potPinServoClaw); // read the value of the potentiometer
  Serial.print("potValServoClaw: ");
  Serial.print(potValServoClaw);

  // scale the numbers from the pot & print out the angle for the servo motor
  angleServoRot = map(potValServoRot, 0, 1023, 0, 179);
  Serial.print(", angleServoRot: ");
  Serial.println(angleServoRot);
  angleServoArm1 = map(potValServoArm1, 0, 1023, 0, 179);
  Serial.print(", angleServoArm1: ");
  Serial.println(angleServoArm1);
  angleServoArm2 = map(potValServoArm2, 0, 1023, 0, 179);
  Serial.print(", angleServoArm2: ");
  Serial.println(angleServoArm2);
  angleServoClaw = map(potValServoClaw, 0, 1023, 0, 179);
  Serial.print(", angleServoClaw: ");
  Serial.println(angleServoClaw);

  // set the servo position
  servoRot.write(angleServoRot);
  servoArm1.write(angleServoArm1);
  servoArm2.write(angleServoArm2);
  servoClaw.write(angleServoClaw);
  
  // wait for the servo to get there
  delay(15);
}
