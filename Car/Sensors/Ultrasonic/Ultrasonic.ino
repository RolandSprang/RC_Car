int trigger = 12;
int echo = 11;
long duration;

long distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  digitalWrite(trigger, LOW);              // Set Trigger to Low to get a clear signal
  delay(10);                                
  digitalWrite(trigger, HIGH);             // Set Trigger to High to send ultrasonic waves
  delay(10);                               
  digitalWrite(trigger, LOW);              // End sendings ultrasonic waves
  
  duration = pulseIn(echo, HIGH);           // measure incomming pulses from the sensor
  distance = (duration / 2) / 29.1;         // convert reseaved signal. (elapsed way / (ultrasonic moves 29.1 ms/cm)

  Serial.print(distance);            // Den Weg in Zentimeter ausgeben
  Serial.println(" cm");               //

  delay(500
}
