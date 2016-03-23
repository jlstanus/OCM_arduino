
//Micro: 0, 1, 2, 3, 7   Mega: 2, 3, 18, 19, 20, 21   Due: all
#define MYPIN1 2
#define MYPIN2 3
#define MYPIN3 0
#define MYPIN4 1


volatile int counter_tetha = 0;  //This variable will increase or decrease depending on the rotation of encoder
volatile int counter_phi = 0;  //This variable will increase or decrease depending on the rotation of encoder
volatile int previous_counter_t = 0;
volatile int previous_counter_p = 0;
volatile int tetha = 0;
volatile int phi = 0;

void setup() {
  Serial.begin (9600);
  Serial.flush();
  //Setting up interrupt
  //A rising pulse from encodenren activated ai0(). AttachInterrupt 0 is DigitalPin nr 2 on moust Arduino.
  attachInterrupt(digitalPinToInterrupt(MYPIN1), ai0, RISING);

  //B rising pulse from encodenren activated ai1(). AttachInterrupt 1 is DigitalPin nr 3 on moust Arduino.
  attachInterrupt(digitalPinToInterrupt(MYPIN2), ai1, RISING);

  //A rising pulse from encodenren activated ai0(). AttachInterrupt 2 is DigitalPin nr 18 on moust Arduino.
  attachInterrupt(digitalPinToInterrupt(MYPIN3), ai2, RISING);

  //B rising pulse from encodenren activated ai1(). AttachInterrupt 3 is DigitalPin nr 19 on moust Arduino.
  attachInterrupt(digitalPinToInterrupt(MYPIN4), ai3, RISING);

  pinMode(11, OUTPUT); // Set pin 2 as trigger pin
  pinMode(5, INPUT); // Set pin 3 as monitor pin
  digitalWrite(11, LOW); // Set trigger LOW for continuous read

  delay(100); // Waits to make sure everything is powered up before sending or receiving data

}

void loop() {


  int rho = pulseIn(5, HIGH); // Count how long the pulse is high in microseconds
  if(rho != 0){ // If we get a reading that isn't zero, let's print it
        rho = rho/10; // 10usec = 1 cm of distance for LIDAR-Lite

    // Calcul angles
    tetha += counter_tetha - previous_counter_t;
  phi += counter_phi - previous_counter_p;

  previous_counter_t = counter_tetha;
  previous_counter_p = counter_phi;
  // Send the value of counter
  Serial.print(rho, DEC); Serial.print ("    "); Serial.print (tetha, DEC); Serial.print ("    "); Serial.println (phi, DEC);
  delay(20); //Delay so we don't overload the serial port
}
}

void ai0() {
  // ai0 is activated if DigitalPin nr 2 is going from LOW to HIGH
  // Check pin 3 to determine the direction
  if (digitalRead(MYPIN2) == LOW) {
    counter_tetha++;
  } else {
    counter_tetha--;
  }
}

void ai1() {
  // ai0 is activated if DigitalPin nr 3 is going from LOW to HIGH
  // Check with pin 2 to determine the direction
  if (digitalRead(MYPIN1) == LOW) {
    counter_tetha--;
  } else {
    counter_tetha++;
  }
}

void ai2() {
  // ai0 is activated if DigitalPin nr 18 is going from LOW to HIGH
  // Check with pin 19 to determine the direction
  if (digitalRead(MYPIN4) == LOW) {
    counter_phi--;
  } else {
    counter_phi++;
  }
}

void ai3() {
  // ai3 is activated if DigitalPin nr 19 is going from LOW to HIGH
  // Check with pin 18 to determine the direction
  if (digitalRead(MYPIN3) == LOW) {
    counter_phi++;
  } else {
    counter_phi--;
  }
}


