int i;
const int enablePin = 5;
const int dirA = 4;
const int dirB = 3;

void setup() {
  pinMode(enablePin, OUTPUT);
  pinMode(dirA, OUTPUT);
  pinMode(dirB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.print("One way, then the other");
  digitalWrite(enablePin, HIGH);
  for (i = 0; i < 5; i++) {
    digitalWrite(dirA, HIGH);
    digitalWrite(dirB, LOW);
    delay(500);
    digitalWrite(dirA, LOW);
    digitalWrite(dirB, HIGH);
    delay(500);
  }
  digitalWrite(enablePin, LOW);
  delay(2000);

  Serial.println("fast/slow stop example");
  digitalWrite(enablePin, HIGH);
  digitalWrite(dirA, HIGH);
  digitalWrite(dirB, LOW);
  delay(300);
  digitalWrite(enablePin, LOW); // Slow stop
  digitalWrite(dirA, LOW);
  digitalWrite(dirB, HIGH);
  delay(3000);
  digitalWrite(dirA, LOW);
  delay(2000);

  Serial.println("PWM full then slow"); // PWM=pulse width modulation
  analogWrite(enablePin, 255);
  digitalWrite(dirA, HIGH);
  digitalWrite(dirB, LOW);
  delay(2000);
  analogWrite(enablePin, 180);
  delay(2000);
  analogWrite(enablePin, 128);
  delay(2000);
  analogWrite(enablePin, 50);
  delay(2000);
  analogWrite(enablePin, 128);
  delay(2000);
  analogWrite(enablePin, 180);
  delay(2000);
  analogWrite(enablePin, 255);
  delay(2000);
  digitalWrite(enablePin, LOW);
  delay(2000);
}
