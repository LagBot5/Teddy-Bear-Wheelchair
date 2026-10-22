#include <Servo.h>

// Servo Pin
const int SERVO_PIN = 9;
Servo myServo;

// Motor Pins
const int IN1 = 2;
const int IN2 = 3;
const int ENA = 10;

// Ultra Sonic Sensors Pins
const int trig = 13
const int echo = 12;
long duration;
int distance;

// Change: 1 = Race  2 = Recycle Run
int mode = 1;

void setup() {
  // Servo Setup
  myServo.attach(SERVO_PIN);
  myServo.write(0);
  
  // Motor Setup
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
    
  // Ultrasonic Sensor maybe
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
    
  Serial.begin(9600);
}

// Servo Code Blocks
void POSA(){
  Serial.print("POSA ");
  myServo.write(90);
}

void POSB(){
  Serial.print("POSB ");
  myServo.write(0);
}

// Motor Code Blocks
void forward(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 100);
  Serial.print("forward");
}

void reverse(){
  Serial.print("reverse");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 100);
}

// Ultra Sonic Sensor
void sensor(){
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("distance: ");
  Serial.print(distance);
  Serial.print("cm ");
}

void Race(){
  POSA();
  forward();
  //detect black tape
  delay(5000);
  reverse();
  delay(5000);
  
}

void Recycle(){
  POSA();
  
  forward();
  delay(5000);
 
  //if car detects distants or stops 
  //POSB();
  //after does that then POSA();
  //then moves backewards
  reverse();
  delay(5000);
  
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
  }
}
