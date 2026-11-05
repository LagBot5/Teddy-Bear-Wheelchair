const int trackingPin = 7;
bool val;


void setup() {
  pinMode(trackingPin, INPUT);
  Serial.begin(9600);


}

void loop() {
  val = digitalRead(trackingPin);
  // If the sensor senses a high value (Detects black line)
  if(val == HIGH)
  {
  // Print output to Serial Monitor
  Serial.println("Detect: Black!");
  }
  else
  {
  // Otherwise, print opposite output to Serial Monitor
  Serial.println("Detect: White!");
  }

}
