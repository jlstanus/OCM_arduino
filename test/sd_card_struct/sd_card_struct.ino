#include <SD.h>


const int chipSelect = 4;
File dataFile;

struct datastore {
    uint16_t adc1;
    uint16_t adc2;
    float voltage;
    float current;
};

void setup() {
    Serial.begin(9600);
    Serial.print("Initializing SD card...");
    pinMode(10, OUTPUT);

    if (!SD.begin(chipSelect)) {
        Serial.println("Card failed, or not present");
        return;
    }

    Serial.println("card initialized.");
    dataFile = SD.open("datalog.dat", FILE_READ);
}

void loop() {
    if (dataFile.available()) {
        struct datastore myData;
        dataFile.read((uint8_t *)&myData, sizeof(myData));
        analogWrite(5, map(myData.adc1, 0, 1023, 0, 255));
        analogWrite(6, map(myData.adc2, 0, 1023, 0, 255));
        Serial.print(myData.voltage, 4);
        Serial.print(" ");
        Serial.println(myData.current, 4);
        delay(50);
    }
}
