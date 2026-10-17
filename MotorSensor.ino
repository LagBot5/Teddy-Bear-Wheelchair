const int IN1 = 2;
const int IN2 = 3;
const int ENA = 10;
const int trig = 13;
const int echo = 12;
long duration;
int distance;

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
  

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  forward();
  delay(2000);
  reverse();
  sensor();
}