int value1 = LOW;
int value2 = LOW;
int value3 = LOW;
int value4 = LOW;

const int redLedPin = 12;
const int greenLedPin = 11;

const int button1Pin = 7;
const int button2Pin = 6;
const int button3Pin = 5;
const int button4Pin = 4;

const int combination = 4; // 1,2,3,4

void setup() {
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  pinMode(button4Pin, INPUT);
  digitalWrite(redLedPin, LOW);
  digitalWrite(greenLedPin, LOW);
  Serial.begin(9600);
}

void loop() {
  int attempt = 0;
  value1 = digitalRead(button1Pin);
  value2 = digitalRead(button2Pin);
  value3 = digitalRead(button3Pin);
  value4 = digitalRead(button4Pin);
  Serial.println("%d", value1);
  Serial.println("%d", value2);
  Serial.println("%d", value3);
  Serial.println("%d", value4);
  if (attempt == 0) {
    if (value1 == HIGH) {
      ++attempt;
    } else {
      attempt = 0;
      digitalWrite(redLedPin, HIGH);
      delay(500);
      digitalWrite(redLedPin, LOW);
    }
  } else if (attempt == 1) {
    if (value2 == HIGH) {
      ++attempt;
    } else {
      attempt = 0;
      digitalWrite(redLedPin, HIGH);
      delay(500);
      digitalWrite(redLedPin, LOW);
    }
  } else if (attempt == 2) {
    if (value3 == HIGH) {
      ++attempt;
    } else {
      attempt = 0;
      digitalWrite(redLedPin, HIGH);
      delay(500);
      digitalWrite(redLedPin, LOW);
    }
  } else if (attempt == 3) {
    if (value4 == HIGH) {
      ++attempt;
    } else {
      attempt = 0;
      digitalWrite(redLedPin, HIGH);
      delay(500);
      digitalWrite(redLedPin, LOW);
    }
  }
  if (attempt == combination) {
    attempt = 0;
    digitalWrite(greenLedPin, HIGH);
    delay(1000);
    digitalWrite(greenLedPin, LOW);
  }
}