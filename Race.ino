const int IN1 = 6;
const int IN2 = 7;
const int ENA = 11;

void setup() {

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  Serial.begin(9600);

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

void loop() {
  // put your main code here, to run repeatedly:
    forward();
    delay(5000);
    stop();
    delay(500);
    reverse();
    delay(5000);
    stop();
    delay(10000);
}
