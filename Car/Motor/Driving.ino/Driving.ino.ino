// #include <Wire.h>

// Gleichstrommotor L
int GSML = 10;
int in1 = 9;
int in2 = 8;

// Gleichstrommotor R
int GSMR = 5;
int in3 = 7;
int in4 = 6;

int speedCar = 75;

typedef enum {
  FORWARD,
  BACKWARD,
  LEFT,
  RIGHT,
  TURN_LEFT,
  TURN_RIGHT
} car_direction;

void setup()
{
  pinMode(GSML, OUTPUT);    
  pinMode(GSMR, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  delay(500);
}
void loop()
{
  carDrive(100, FORWARD);
  delay(200);
  carStop();
  carDrive(100, LEFT);
  delay(300);
  carStop();
  delay(150);
} 
void carDrive(int speed_Car, car_direction dir) {
  switch(dir) {
    case FORWARD:
      driveForwart();
      break;
    case BACKWARD:
      driveBackward();
      break;
    case LEFT:
      driveLeft();
      break;
    case RIGHT:
      driveRight();
      break;
    case TURN_LEFT:
      turnLeft();
      break;
    case TURN_RIGHT:
      turnRight();
      break;
    default: 
      carStop;
  }
  analogWrite(GSML, speed_Car);   // Motor L
  analogWrite(GSMR, speed_Car * 1.2);   // Motor R
}

void carStop() {
    analogWrite(GSML, 0);   // Motor 1 soll mit der Geschwindigkeit "200" (max. 255) rotieren
    analogWrite(GSMR, 0);   // Motor 1 soll mit der Geschwindigkeit "200" (max. 255) rotieren
}

void driveForwart() {
  digitalWrite(in1, LOW);  // Motor L beginnt zu rotieren
  digitalWrite(in2, HIGH);

  digitalWrite(in3, LOW);  // Motor R beginnt zu rotieren
  digitalWrite(in4, HIGH);
}

void driveBackward() {
  digitalWrite(in1, HIGH);  // Motor L 
  digitalWrite(in2, LOW);

  digitalWrite(in3, HIGH);  // Motor R 
  digitalWrite(in4, LOW);
}

void driveLeft() {
  digitalWrite(in1, LOW);  // Motor L 
  digitalWrite(in2, LOW);

  digitalWrite(in3, LOW);  // Motor R 
  digitalWrite(in4, HIGH);
}

void driveRight() {
  digitalWrite(in1, LOW);  // Motor L 
  digitalWrite(in2, HIGH);

  digitalWrite(in3, LOW);  // Motor R 
  digitalWrite(in4, LOW);
}

void turnLeft() {
  digitalWrite(in1, HIGH);  // Motor L 
  digitalWrite(in2, LOW);

  digitalWrite(in3, LOW);  // Motor R 
  digitalWrite(in4, HIGH);
}

void turnRight() {
  digitalWrite(in1, LOW);  // Motor L 
  digitalWrite(in2, HIGH);

  digitalWrite(in3, HIGH);  // Motor R 
  digitalWrite(in4, LOW);
}
