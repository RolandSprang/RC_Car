const int trigger = A0;
const int echo = A1;



uint32_t gul_distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {

}

/**
 * Measuge the distance using the Ultrawave sensor HC-SR04
 * Writes the measured distance into a global variable "gul_distance"
 */
void measureDistance() {
  digitalWrite(trigger, LOW);                 // Set Trigger to Low to get a clear signal
  delayMicroseconds(10);
  digitalWrite(trigger, HIGH);                // Set Trigger to High to send ultrasonic waves
  delayMicroseconds(250);
  digitalWrite(trigger, LOW);                 // End sendings ultrasonic waves

  uint32_t ul_duration;
  ul_duration = pulseIn(echo, HIGH); // measure incomming pulses from the sensor
  gul_distance = (ul_duration / 2) / 29.1;    // convert reseaved signal. (elapsed way / (ultrasonic moves 29.1 ms/cm)
}
