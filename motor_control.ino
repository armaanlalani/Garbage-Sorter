
#include <Servo.h>

int pinRamp = 6;      // digital pin 9 (ramp)
int pinPush = 9;
Servo servoRamp;       // servo that rotates ramp
Servo servoPush;

void setup() {
  // put your setup code here, to run once:

  servoRamp.attach(pinRamp);
  servoPush.attach(pinPush);
  Serial.begin(9600);
  Serial.println("--- Begin serial communication to servos ---");
  servoRamp.write(0);
  servoPush.write(0);
  delay(15);

}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available()>0){ 
    char ch = Serial.read();
  
    if (ch == '0') {
      Serial.println(" 0 deg ");
      servoRamp.write(0);  
      delay(15);
    }
  
    if (ch == '9') {
      Serial.println(" 90 deg ");
      servoRamp.write(45);
      delay(15);

    }

    if (ch == '8') {
      Serial.println(" 180 deg ");
      servoRamp.write(90);
      delay(15);
    }

    if (ch == 'p') {
      Serial.println(" PUSHING ");
      servoPush.write(180);
      delay(2000);
      servoPush.write(0);
      delay(2000);
    }

   

//    if (ch == '0') {
//      Serial.println(" STOP SERVO ");
//      servoRamp.write(0);  
//      delay(15);
//    }
//
//    if (ch == '9') {
//      Serial.println(" Clockwise servo ");
//      servoRamp.write(45);
//      delay(1820);
//      //servoRamp.write(90);
//    }
//
//    if (ch == '8') {
//      Serial.println(" Counter-clockwise servo ");
//      servoRamp.write(90);
//      delay(1800);
//      //servoRamp.write(90);
//    }
//
//    if (ch == '0') {
//      Serial.println(" RESET SERVO ");
//      servoRamp.write(180);
//      delay(15);
//    }

  } 

}
