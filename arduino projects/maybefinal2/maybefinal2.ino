#include <SoftwareSerial.h>

#include <Servo.h> // servo library 
Servo myservo1, myservo2, myservo3, myservo4; // servo name

#define E1 8  // Enable Pin for motor 1 10
#define E2 9  // Enable Pin for motor 2 11
#define I1 10  // Control pin 1 for motor 1 9 
#define I2 11  // Control pin 2 for motor 1 6
#define I3 12  // Control pin 1 for motor 2
#define I4 13  // Control pin 2 for motor 2
int state = 0;

int bluetoothTx = 5; // bluetooth tx to 10 pin
int bluetoothRx = 4; // bluetooth rx to 11 pin



SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
 
void setup() {
    pinMode(E1, OUTPUT);
    pinMode(E2, OUTPUT);
    pinMode(I1, OUTPUT);
    pinMode(I2, OUTPUT);
    pinMode(I3, OUTPUT);
    pinMode(I4, OUTPUT);
    myservo1.attach(2); // attach servo signal wire to pin 9
  myservo2.attach(3);
  myservo3.attach(6);
  myservo4.attach(7);
  //Setup usb serial connection to computer
    Serial.begin(9600);
    bluetooth.begin(9600);
}

void loop() {

//Set Speed
    analogWrite(E1, 150);
    analogWrite(E2, 180);


if (bluetooth.available() > 0) 
{     // Checks whether data is comming from the serial port
 state = bluetooth.read();            // Reads the data from the serial port
 }
 
 if (state == 'a') {
  moveForward();
 }
  
 else if (state == 'b') {
 moveLeft();
 }
 
 else if (state == 'c') {
 moveRight();
 }
 
 else if (state == 'd') {
 moveBackward();
 }

 else if (state == NULL) {
 stopMoving();
 }
//Read from bluetooth and write to usb serial
  if(bluetooth.available()>= 2 )
  {
    unsigned int servopos = bluetooth.read();
    unsigned int servopos1 = bluetooth.read();
    unsigned int realservo = (servopos1 *256) + servopos;
    Serial.println(realservo);

    if (realservo >= 1000 && realservo <1180) {
      int servo1 = realservo;
      servo1 = map(servo1, 1000, 1180, 0, 180);
      myservo1.write(servo1);
      Serial.println("Servo 1 ON");
      delay(10);
    }
    if (realservo >= 2000 && realservo <2180) {
      int servo2 = realservo;
      servo2 = map(servo2, 2000, 2180, 0, 180);
      myservo2.write(servo2);
      Serial.println("Servo 2 ON");
      delay(10);
    }
    if (realservo >= 3000 && realservo <3180) {
      int servo3 = realservo;
      servo3 = map(servo3, 3000, 3180, 0, 180);
      myservo3.write(servo3);
      Serial.println("Servo 3 ON");
      delay(10);
    }
    if (realservo >= 4000 && realservo <4180) {
      int servo4 = realservo;
      servo4 = map(servo4, 4000, 4180, 0, 180);
      myservo4.write(servo4);
      Serial.println("Servo 4 ON");
      delay(10);
    }
    
  }
}

void stopMoving() {
    digitalWrite(I1, LOW);
    digitalWrite(I2, LOW);
    digitalWrite(I3, LOW);
    digitalWrite(I4, LOW);
}

void moveForward() {
    digitalWrite(I1, HIGH);
    digitalWrite(I2, LOW);
    digitalWrite(I3, HIGH);
    digitalWrite(I4, LOW);
}

void moveBackward() {
    digitalWrite(I1, LOW);
    digitalWrite(I2, HIGH);
    digitalWrite(I3, LOW);
    digitalWrite(I4, HIGH);
}

void moveLeft() {
    digitalWrite(I1, HIGH);
    digitalWrite(I2, LOW);
    digitalWrite(I3, LOW);
    digitalWrite(I4, LOW);
}

void moveRight() {
    digitalWrite(I1, LOW);
    digitalWrite(I2, LOW);
    digitalWrite(I3, HIGH);
    digitalWrite(I4, LOW);
}
