//Declaring arduino pins and what they connect to on the motor controller
const int IN1 = 6;
const int IN2 = 7;
const int ENA = 11;

//Function Block to cause the motor to spin such that it moves the wheelchair forward
void forward(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 255);
  Serial.print("forward");
}

//Function Block to cause the motor to spin such that it moves the wheelchair in reverse
void reverse(){
  Serial.print("reverse ");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 255);
}

//Function block causing the wheelchair to stop
void stop(){
  Serial.print("stop");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
  
}
void setup() {
  //Setting each of the arduino pins that connect to the motor controller
  //to output so they will send out signals to the motor controller
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  //Serial monitor initialized to facilitate debugging if needed
  Serial.begin(9600); 
}

void loop() {
  //Calls upon the functions that cause the wheelchair to move forward, delay for 2
  //seconds then reverse delay for 2 more seconds and then stop
  forward();
  delay(2000);
  reverse();
  delay(2000);
  stop();
}
