void setup() {
  int MotorA = 3;
  int in1A = 6;
  int in2A = 11;

  int MotorB = 9;
  int in1B = 5;
  int in2B = 6;

  int RS = A0;
  int MS = A1;
  int LS = A2;

  pinMode (in1A, OUTPUT);
   pinMode (in2A, OUTPUT);
    pinMode (MotorA, OUTPUT);
     pinMode (in2B, OUTPUT);
      pinMode (in2B, OUTPUT);
       pinMode (MotorB, OUTPUT);
        pinMode (RS, INPUT);
         pinMode (LS, INPUT);
Serial.begin(9600);
pinMode(A0, INPUT);
pinMode(A1, INPUT);
pinMode(A3, INPUT);


}

void loop() {
 if (digitalRead(A2)&&digitalRead(A0)) //Move Forward

 {
  analogWrite(3, 150);
  digitalWrite(in1A, HIGH);
  digitalWrite(in2A, LOW);
  analogWrite(MotorB, 150);
  digitalWrite(in1B, HIGH);
  digitalWrite(in2B, LOW);
 }

 if (!(digitalRead(A2)&&digitalRead(A0)) //Turn Right
 {
  analogWrite(3, 0);
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, LOW);
  analogWrite(MotorB, 150);
  digitalWrite(in1B, HIGH);
  digitalWrite(in2B, LOW);
 }

 if (digitalRead(A2)&&!(digitalRead(A0))); //Turn Left
 {
  analogWrite(3, 150);
  digitalWrite(in1A, HIGH);
  digitalWrite(in2A, LOW);
  analogWrite(MotorB, 0);
  digitalWrite(in1B, LOW);
  digitalWrite(in2B, LOW);
 }
 if (!(digitalRead(A2)&&!(digitalRead(A0))) // Stop
 {
  analogWrite(3, 0);
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, LOW);
  analogWrite(MotorB, 0);
  digitalWrite(in1B, LOW);
  digitalWrite(in2B, LOW);
 }
 }
 
