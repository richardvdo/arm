//##################################################################################
//                         code perceuse + bras                                    #
//                         18/04/24                                                #
//                         TODO:
//           - implementer perceuse
//             - commande moteur pas a pas
//             - calculer vitesse
//             - buté haut bas 
//             - gamme de vitesse ?
//             - choisir vitesse pot
//             - distance
//             - offset
//             - up/down
//             - repeat ?
//
//           - pompe liquide de coupe
//             - on/off
//             - quantité
//
//           - correlé arm
//
//##################################################################################


#include <Servo.h>
#include <Stepper.h>



const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

const int buttonUpPin = 16;
const int buttonDownPin = 17; 
const int buttonStartPin = 18; 
const int buttonStopPin = 19; 
const int buttonSpeedRange = 20; 
const int buttonCutLiquid = 21; 

int const potPinSpeed = A3; // analog pin used to connect the potentiometer
int const potPinDistance = A4;
int const potPinLiquideQt = A5;

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

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
  // set the speed at 60 rpm:
  myStepper.setSpeed(60);






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
// block perceuse
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);


// partie arm
  Serial.println(" -- nouvelle boucle -- ");
  
  potValServoRot = analogRead(potPinServoRot); // read the value of the potentiometer
  Serial.print(", potValServoRot: ");
  Serial.println(potValServoRot);
  potValServoArm1 = analogRead(potPinServoArm1); // read the value of the potentiometer
  Serial.print(", potValServoArm1: ");
  Serial.println(potValServoArm1);
  potValServoArm2 = analogRead(potPinServoArm2); // read the value of the potentiometer
  Serial.print(", potValServoArm2: ");
  Serial.println(potValServoArm2);

  buttonCloseState = digitalRead(buttonClosePin);
  Serial.print(", buttonCloseState: ");
  Serial.println(buttonCloseState);
  buttonOpenState = digitalRead(buttonOpenPin);
  Serial.print(", buttonOpenState: ");
  Serial.println(buttonOpenState);
  if (buttonCloseState == LOW) {
    angleServoClaw = 0;
  } 
  if (buttonOpenState == LOW) {
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
  delay(30);
}
