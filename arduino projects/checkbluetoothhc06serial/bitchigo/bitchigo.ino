#define E1 8   // Enable Pin for motor 1
#define E2 9   // Enable Pin for motor 2
#define I1 10  // Control pin 1 for motor 1
#define I2 11  // Control pin 2 for motor 1
#define I3 12  // Control pin 1 for motor 2
#define I4 13  // Control pin 2 for motor 2
int state = 0;
 
void setup() {
    pinMode(E1, OUTPUT);
    pinMode(E2, OUTPUT);
    pinMode(I1, OUTPUT);
    pinMode(I2, OUTPUT);
    pinMode(I3, OUTPUT);
    pinMode(I4, OUTPUT);
    Serial.begin(9600);
}

void loop() {

//Set Speed
    analogWrite(E1, 160);
    analogWrite(E2, 180);


if (Serial.available() > 0)  {     // Checks whether data is comming from the serial port
 state = Serial.read();            // Reads the data from the serial port
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
