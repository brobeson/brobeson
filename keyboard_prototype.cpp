#include <pitches.h>

// variables
int note[] = {NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4};
int sizeSize1 = 8;
int melody[] = {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3,
                NOTE_G3, 0,       NOTE_B3, NOTE_C4};
int duration1[] = {4, 8, 8, 4, 4, 4, 4, 4};

// constants
const int buzzerPin = 10;
const int button1 = 3;
const int button2 = 4;
const int button3 = 5;
const int button4 = 6;
const int button5 = 7;

setup() {
  for (int 1 = 3; i < 8; i++) {
    pinMode(i, INPUT);
  }
  pinMode(buzzerPin, OUTPUT);
}

loop() {
  if (digitalRead(button1) == HIGH && digitalRead(button2) == HIGH) {
    for (int i = 0; i < songSize1; i++) {
      int d = 1000 / duration1[i];
      tone(buzzerPin, melody1[i], d);
      int pause = d * 1.30;
      delay(pause);
      noTone(buzzerPin);
    }
  } else if (digitalRead(button1) == HIGH) {
    tone(buzzerPin, note[0], 20);
  } else if (digitalRead(button2) == HIGH) {
  } else if (digitalRead(button3) == HIGH) {
  } else if (digitalRead(button4) == HIGH) {
  } else if (digitalRead(button5) == HIGH) {
    tone(buzzerPin, note[4], 20);
  }
}