#include <Servo.h>

Servo servoRot;  // create a servo object
Servo servoArm1;
Servo servoArm2;
Servo servoClaw;

const int buttonClosePin = 12;
const int buttonOpenPin = 13; 
int buttonCloseState = 0; 
int buttonOpenState = 0; 

int const potPinServoRot = A0; // analog pin used to connect the potentiometer
int const potPinServoArm1 = A1; // analog pin used to connect the potentiometer
int const potPinServoArm2 = A2; // analog pin used to connect the potentiometer

int potValServoRot;  // variable to read the value from the analog pin
int potValServoArm1;  // variable to read the value from the analog pin
int potValServoArm2;  // variable to read the value from the analog pin

int angleServoRot;   // variable to hold the angle for the servo motor
int angleServoArm1;   // variable to hold the angle for the servo motor
int angleServoArm2;   // variable to hold the angle for the servo motor
int angleServoClaw;   // variable to hold the angle for the servo motor


void setup() {
  servoRot.attach(5); // attaches the servo on pin 9 to the servo object
  servoArm1.attach(9);
  servoArm2.attach(10);
  servoClaw.attach(11);
  pinMode(buttonClosePin, INPUT);
  pinMode(buttonOpenPin, INPUT);
  digitalWrite(buttonClosePin, HIGH);
  digitalWrite(buttonOpenPin, HIGH);
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

  buttonCloseState = digitalRead(buttonClosePin);
  Serial.print(", buttonCloseState: ");
  Serial.println(buttonCloseState);
  buttonOpenState = digitalRead(buttonOpenPin);
  Serial.print(", buttonOpenState: ");
  Serial.println(buttonOpenState);
  if (buttonCloseState == HIGH) {
    angleServoClaw = 0;
  } 
  if (buttonOpenState == HIGH) {
    angleServoClaw = 179;
  }

  // scale the numbers from the pot & print out the angle for the servo motor
  angleServoRot = map(potValServoRot, 0, 1023, 60, 120);
  Serial.print(", angleServoRot: ");
  Serial.println(angleServoRot);
  angleServoArm1 = map(potValServoArm1, 0, 1023, 63, 179);
  Serial.print(", angleServoArm1: ");
  Serial.println(angleServoArm1);
  angleServoArm2 = map(potValServoArm2, 0, 1023, 47, 126);
  Serial.print(", angleServoArm2: ");
  Serial.println(angleServoArm2);

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
