#include <Servo.h>

// Servo Pin
const int SERVO_PIN = 5;
Servo myServo;

// Motor Pins
const int IN1 = 6;
const int IN2 = 7;
const int ENA = 11;

// Ultra Sonic Sensors Pins
const int trig = 1;
const int echo = 12;
long duration;
int distance;

// Change: 1 = Race  2 = Recycle Run
int mode = 3;

void setup() {
  // Servo Setup
  myServo.attach(SERVO_PIN);
  myServo.write(0);
  
  // Motor Setup
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(9, OUTPUT);
    
  // Ultrasonic Sensor maybe
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  
  Serial.begin(9600);
}

// Servo Code Blocks
void POSA(){
  myServo.write(90);
  Serial.print("A ");
}

void POSB(){
  myServo.write(0);
  Serial.print("B ");
}

// Motor Code Blocks
void forward(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 255);
  Serial.print("forward");
}

void reverse(){
  Serial.print("reverse ");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 255);
}

void stop(){
  Serial.print("stop");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
  
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

void Prototype(){
    forward();
    //delay(2000);
    //reverse();
    //delay(2000);
    //stop();
    //POSA();
    //delay(1000);
    //POSB();
    //delay(1000);
}

void loop() {
  switch (mode){
    case 1:
    Race();
    break;
    
    case 2:
    Recycle();
    break;

    case 3:
    digitalWrite(5, HIGH);  // change state of the LED by setting the pin to the HIGH voltage level
    Prototype();
    delay(2000);                      // wait for a second
    digitalWrite(5, LOW);   // change state of the LED by setting the pin to the LOW voltage level
    delay(2000); 
    break;
    
    default:
    break;
  }
}
