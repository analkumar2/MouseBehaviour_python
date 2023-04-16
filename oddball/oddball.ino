const int tonePin = 13;

void setup() {
  pinMode(tonePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // unsigned starttime = millis();
  // while (millis() - starttime < 100) { // we need to do this because laptop is not a RTOS and sometimes process the incoming signals late
    Serial.println(1); // sends signal to the laptop to start recording
  // }

  digitalWrite(tonePin, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(100);                      // wait for a second
  digitalWrite(tonePin, LOW);   // turn the LED off by making the voltage LOW
  delay(100);

  // starttime = millis();
  // while (millis() - starttime < 100){ // we need to do this because laptop is not a RTOS and sometimes process the incoming signals late
    Serial.println(0); // sends signal to the laptop to stop recording
  // }
  delay(1); // A delay. Not sure if this is absolutely needed or not
}
