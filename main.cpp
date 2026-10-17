#include <Servo.h>

const int SERVO_PIN = 9;
//const int MOTOR_PIN     = 5;
int mode = 1;

Servo myServo;

void setup() {
  myServo.attach(SERVO_PIN);
  myServo.write(0);
  Serial.begin(9600);
}

void POSA(){
  Serial.print("POSA ");
  myServo.write(90);
}

void POSB(){
  Serial.print("POSB ");
  myServo.write(0);
}

void Race(){
  POSA();
  //move forward
  //detect black tape
  //move backwards
}

void Recycle(){
  POSA();
  
  //move forward
 
  //if car detects distants or stops 
  //POSB();
  //after does that then POSA();
  //then moves backewards
}

void loop() {
  switch (mode){
    case 1:
    Race();
    break;
    
    case 2:
    Recycle();
    break;
    
    default:
    break;
  //POSA();
  //delay(3000);
  //POSB();
  //delay(3000);
  }
}
