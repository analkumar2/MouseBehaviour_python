const int tonePin = 13;

void setup() {
  pinMode(tonePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char input = Serial.read();
    if (input == 's') {
      Serial.write(1); // send HIGH signal to laptop
      delay(1000);
      for (int i = 0; i < 10; i++) {
        tone(tonePin, 8000, 1000);
        delay(1000);
      }
      Serial.write(0); // send LOW signal to laptop
    }
  }
}
