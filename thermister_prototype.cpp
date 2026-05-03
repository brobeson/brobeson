const int sensorPin = A0;    // Thermistor
const float baseTemp = 26.0; // celsius

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);

  // Set all LEDs as output and turn them off.
  for (int x = 6; x < 9; x++) {
    pinMode(x, OUTPUT);
    digitalWrite(x, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  double tempK = log(10000.0 * ((1024.0 / sensorVal - 1)));
  tempK = 1 / (0.0011148 +
               (0.000234125 + (0.0000000876741 * tempK * tempK)) * tempK);
  float tempC = tempK - 273.15;
  float tempF = (tempC * 9.0) / 5.0 + 32.0;
  Serial.print(tempK);
  Serial.print(" Kelvin. ");
  Serial.print(tempC);
  Serial.print(" degrees C. ");
  Serial.print(tempF);
  Serial.print(" degrees F. ");
  if (tempC < baseTemp) {
    // TODO Add code to turn off all LEDs.
  } else if (tempC < baseTemp + 4) {
    // TODO Add code to turn on bottom LED.
  } else if (tempC < baseTemp + 6) {
    // TODO Add code to turn on bottom and middle LED.
  } else {
    // TODO Add code to turn on all LEDs.
  }
  delay(1000);
}
