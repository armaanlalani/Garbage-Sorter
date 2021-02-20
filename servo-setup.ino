
#include <Servo.h>

int pinRamp = 9;      // digital pin 9 (ramp)
int pinPush = 6;
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
  //Serial.println('\x00');
  // put your main code here, to run repeatedly:
  //byte ch = '\x00';
  //Serial.println(ch);
//  if (Serial.available()){ 
//    byte r = 1;
//    r = r * (Serial.read() - '0');

  if (Serial.available()) {
    int byte = Serial.read();
    Serial.println( byte );
  
    if (byte == 0) {
      Serial.println(" 0 deg ");
      servoRamp.write(0);   
      delay(15);
    }
  
    if (byte == 9) {
      Serial.println(" 90 deg ");
      servoRamp.write(30);
      delay(15);

    }

    if (byte == 8) {
      Serial.println(" 180 deg ");
      servoRamp.write(60);
      delay(15);
    }
    
    if (byte == 2){
      Serial.println(" PUSHING ");
      servoPush.write(110);
      delay(2000);
      servoPush.write(0);
      delay(2000);
    }

//   if (byte == 3) {
//    
//   }
  }
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
