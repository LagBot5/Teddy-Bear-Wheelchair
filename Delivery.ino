#include <Servo.h>
// Servo Pin
const int SERVO_PIN = 5;
Servo myServo;
//US sensor pins
//motor pins
const int IN1 = 6;
const int IN2 = 7;
const int ENA = 11;


void setup() {
  myServo.attach(SERVO_PIN);
  myServo.write(0);
  Serial.begin(9600);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

}

void forward(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 255);
  //Serial.print("forward");
}

void reverse(){
  //Serial.print("reverse ");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 255);
}

void stop(){
 //Serial.print("stop");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0); 
}

void POSA(){
  myServo.write(90);
  //Serial.print("A ");
}

void POSB(){
  myServo.write(0);
 // Serial.print("B ");
}


void loop() {
  // put your main code here, to run repeatedly:
  forward();
  delay(7000);

  //Serial.print("distance: ");
  //Serial.print(distance);
  //Serial.print("cm \n");

  
    stop();
    
    POSA();
    delay(1000);
    POSB();
    delay(1000);

    stop();
    delay(20000);
  
}
