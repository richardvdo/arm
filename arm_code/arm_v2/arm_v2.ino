#include <Servo.h>

Servo servoRot;  // create a servo object
Servo servoArm1;
Servo servoArm2;
Servo servoClaw;

int angleServoRot;   // variable to hold the angle for the servo motor
int angleServoArm1;   // variable to hold the angle for the servo motor
int angleServoArm2;   // variable to hold the angle for the servo motor
int angleServoClaw;   // variable to hold the angle for the servo motor

int angleServoRotMap;   // variable to hold the angle for the servo motor
int angleServoArm1Map;   // variable to hold the angle for the servo motor
int angleServoArm2Map;   // variable to hold the angle for the servo motor
int angleServoClawMap;   // variable to hold the angle for the servo motor


void setup() {
  servoRot.attach(5); // attaches the servo on pin 9 to the servo object
  servoArm1.attach(9);
  servoArm2.attach(10);
  servoClaw.attach(11);

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

     angleServoRot = angleServoRot + cmdAngleServoRot;
     angleServoRot = min(angleServoRot, 100);
     angleServoRot = max(angleServoRot, 0);
     Serial.print("\n angleServoRot: ");
     Serial.println(angleServoRot);
          
     angleServoArm1 = angleServoArm1 + cmdAngleServoArm1;
     angleServoArm1 = min(angleServoArm1, 100);
     angleServoArm1 = max(angleServoArm1, 0);
     Serial.print("\n angleServoArm1: ");
     Serial.println(angleServoArm1);
      
     angleServoArm2 = angleServoArm2 + cmdAngleServoArm2;
     angleServoArm2 = min(angleServoArm2, 100);
     angleServoArm1 = max(angleServoArm2, 0);
     Serial.print("\n angleServoArm2: ");
     Serial.println(angleServoArm2);
      
     angleServoClaw = angleServoClaw + cmdAngleServoClaw;
     angleServoClaw = min(angleServoClaw, 100);
     angleServoClaw = max(angleServoClaw, 0);
     Serial.print("\n angleServoClaw: ");
     Serial.println(angleServoClaw); 

    }
  }


  // scale the numbers from the pot & print out the angle for the servo motor
  angleServoRotMap = map(angleServoRot, 0, 100, 60, 120);
  Serial.print(", angleServoRotMap: ");
  Serial.println(angleServoRotMap);
  angleServoArm1Map = map(angleServoArm1, 0, 100, 63, 179);
  Serial.print(", angleServoArm1Map: ");
  Serial.println(angleServoArm1Map);
  angleServoArm2Map = map(angleServoArm2, 0, 100, 47, 126);
  Serial.print(", angleServoArm2Map: ");
  Serial.println(angleServoArm2Map);
  angleServoClawMap = map(angleServoClaw, 0, 100, 1, 179);
  Serial.print(", angleServoClawMap: ");
  Serial.println(angleServoClawMap);

  // set the servo position
  servoRot.write(angleServoRotMap);
  servoArm1.write(angleServoArm1Map);
  servoArm2.write(angleServoArm2Map);
  servoClaw.write(angleServoClawMap);
  
  // wait for the servo to get there
  delay(30);


  
}
