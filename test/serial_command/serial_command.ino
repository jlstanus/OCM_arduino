

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  handleSerial();
  // Everything else loop() does…
}

void handleSerial() {
  while (Serial.available() > 0) {
    char incomingCharacter = Serial.read();
    switch (incomingCharacter) {
      case '+':
        Serial.println("+ pressed");
        break;

      case '-':
        Serial.println("- pressed");
        break;
    }
  }
}
