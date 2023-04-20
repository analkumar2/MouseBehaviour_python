const int tonePin = 8;
long randNumber;
bool hasitstarted = false;

void setup() {
  pinMode(tonePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (hasitstarted == false) {
    if (Serial.available() > 0) {
      // Read the message from the serial port
      char message = Serial.read();

      // Perform an action based on the received message
      if (message == 's') {
        // unsigned starttime = millis();
        // while (millis() - starttime < 100) { // we need to do this because laptop is not a RTOS and sometimes process the incoming signals late
          Serial.println(1); // sends signal to the laptop to start recording
        // }

        randNumber = random(30,80);
        for (int i=0; i<randNumber; i++) {
          tone(tonePin, tone_freq, 50);
          delay(150);
        }
        tone(tonePin, dev_freq, 50);
        delay(150);
        randNumber = random(30,80);
        for (int i=0; i<randNumber; i++) {
          tone(tonePin, tone_freq, 50);
          delay(150);
        }

        // starttime = millis();
        // while (millis() - starttime < 100){ // we need to do this because laptop is not a RTOS and sometimes process the incoming signals late
          Serial.println(0); // sends signal to the laptop to stop recording
        // }
        delay(1); // A delay. Not sure if this is absolutely needed or not
        hasitstarted = true;
      }
    }
  }
  else if (hasitstarted == true) {
    if (Serial.available() > 0) {
      // Read the message from the serial port
      char message = Serial.read();

      // Perform an action based on the received message
      if (message == 'q') {
        hasitstarted = false;
      }
    }
    else {
      // unsigned starttime = millis();
      // while (millis() - starttime < 100) { // we need to do this because laptop is not a RTOS and sometimes process the incoming signals late
        Serial.println(1); // sends signal to the laptop to start recording
      // }

      randNumber = random(30,80);
      for (int i=0; i<randNumber; i++) {
        tone(tonePin, tone_freq, 50);
        delay(150);
      }
      tone(tonePin, dev_freq, 50);
      delay(150);
      randNumber = random(30,80);
      for (int i=0; i<randNumber; i++) {
        tone(tonePin, tone_freq, 50);
        delay(150);
      }

      // starttime = millis();
      // while (millis() - starttime < 100){ // we need to do this because laptop is not a RTOS and sometimes process the incoming signals late
        Serial.println(0); // sends signal to the laptop to stop recording
      // }
      delay(1); // A delay. Not sure if this is absolutely needed or not
    }
  }
}
