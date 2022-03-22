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

// init ou pas du bras au milieu
  angleServoRot = 50;
  angleServoArm1 = 50;
  angleServoArm2 = 50;
  angleServoClaw = 50;


  
}

void loop() {


while (Serial.available() > 0) {

    // look for the next valid integer in the incoming serial stream:
    int cmdAngleServoRot = Serial.parseInt();
    // do it again:
    int cmdAngleServoArm1 = Serial.parseInt();
    // do it again:
    int cmdAngleServoArm2 = Serial.parseInt();
    // do it again:
    int cmdAngleServoClaw = Serial.parseInt();

    // look for the newline. That's the end of your sentence:
    if (Serial.read() == '\n') {
      // constrain the values to 0 - 255 and invert
      // if you're using a common-cathode LED, just use "constrain(color, 0, 255);"


     angleServoRot = angleServoRot + cmdAngleServoRot;
     angleServoArm1 = angleServoArm1 + cmdAngleServoArm1;
     angleServoArm2 = angleServoArm2 + cmdAngleServoArm2;
     angleServoClaw = angleServoClaw + cmdAngleServoClaw;


    }
  }


  // scale the numbers from the pot & print out the angle for the servo motor
  angleServoRot = map(angleServoRot, 0, 100, 60, 120);
  Serial.print(", angleServoRot: ");
  Serial.println(angleServoRot);
  angleServoArm1 = map(angleServoArm1, 0, 100, 63, 179);
  Serial.print(", angleServoArm1: ");
  Serial.println(angleServoArm1);
  angleServoArm2 = map(angleServoArm2, 0, 100, 47, 126);
  Serial.print(", angleServoArm2: ");
  Serial.println(angleServoArm2);
  angleServoClaw = map(angleServoClaw, 0, 100, 1, 179);
  Serial.print(", angleServoClaw: ");
  Serial.println(angleServoClaw);

  // set the servo position
  servoRot.write(angleServoRot);
  servoArm1.write(angleServoArm1);
  servoArm2.write(angleServoArm2);
  servoClaw.write(angleServoClaw);
  
  // wait for the servo to get there
  delay(30);


  
}
