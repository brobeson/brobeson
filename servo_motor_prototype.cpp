#include <Servo.h>

Servo myServo;         // Creates a Servo object
int potVal;            // Value from the potentiometer
int angle;             // Angle for the Servo
const int potPin = A0; // Potentiometer Pin

void setup() {
  Serial.begin(9600);
  pinMode(potPin, INPUT);
  myServo.attach(9); // This is how you set up a Servo motor
  for (int i = 0; i < 180; i++) {
    myServo.write(i);
    delay(10);
  }
  for (int i = 180; i > 0; i--) {
    myServo.write(i);
    delay(10);
  }
}

void loop() {
  potVal = analogRead(potPin);
  Serial.print("potVal: ");
  Serial.print(potVal);
  // Map from Potentiometer reading to angle
  angle = map(potVal, 0, 1023, 0, 179);
  Serial.print(", angle: ");
  Serial.print(angle);
  myServo.write(angle);
  delay(250);
}