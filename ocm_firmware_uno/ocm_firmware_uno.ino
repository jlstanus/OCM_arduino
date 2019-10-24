/* Pin Mapping Arduino UNO - Adafruit SD shield
   Lidar SDA: A5
   Lidar SCL: A4
   Stepper_X A: 100
   Stepper_X B: 101
   Stepper_Y A: 102
   Stepper_Y B: 103
   SD pinMode: 104



*/

bool scanner = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  initLidar();
}

void loop() {
  handleSerial();
  if (scanner){
    scanning();
  }
}

void handleSerial() {
  while (Serial.available() > 0) {
    char incomingCharacter = Serial.read();
    switch (incomingCharacter) {
      case 'a':
        scanner = true;
        Serial.println("Scan Started");
        break;

      case 'o':
        scanner = false;
        Serial.println("Scan Stopped");
        break;
    }
  }
}
