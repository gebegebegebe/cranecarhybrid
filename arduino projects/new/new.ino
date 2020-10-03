int in1A = 10;
int in2A = 11;  
int motorA = 9;  

int in1B = 6;
int in2B = 5;
int motorB = 3;

int RS = A1;
int MS = A0;
int LS = A2;


void setup()
{
  pinMode(in1A, OUTPUT);
  pinMode(in2A, OUTPUT);
  pinMode(motorA, OUTPUT);
  pinMode(in1B, OUTPUT);
  pinMode(in2B, OUTPUT);
  pinMode(motorB, OUTPUT);
  pinMode(MS, INPUT);
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);

  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
}
void loop()
{
  RS = digitalRead(A1);
  MS = digitalRead(A0);
  LS = digitalRead(A2);
Serial.println(digitalRead(A1));
  if((LS == 0 && MS == 1 && RS == 0))     // Move Forward
  {
    analogWrite(motorA, 200);
    digitalWrite(in1A, HIGH);
    digitalWrite(in2A, LOW);
    analogWrite(motorB, 200);
    digitalWrite(in1B, HIGH);
    digitalWrite(in2B, LOW);
  }
  
   if((LS == 0 && MS == 0 && RS == 1))     // Turn right
  {
    analogWrite(motorA, 200);
    digitalWrite(in1A, LOW);
    digitalWrite(in2A, LOW);
    analogWrite(motorB, 200);
    digitalWrite(in1B, HIGH);
    digitalWrite(in2B, LOW);
  }
    if((LS == 0 && MS == 1 && RS == 1))     // Turn right
  {
    analogWrite(motorA, 200);
    digitalWrite(in1A, LOW);
    digitalWrite(in2A, LOW);
    analogWrite(motorB, 200);
    digitalWrite(in1B, HIGH);
    digitalWrite(in2B, LOW);
  }
  
   if((LS == 1 && MS == 0 && RS == 0))    // turn left  
  {
    analogWrite(motorA, 200);
    digitalWrite(in1A, HIGH);
    digitalWrite(in2A, LOW);
    analogWrite(motorB, 200);
    digitalWrite(in1B, LOW);
    digitalWrite(in2B, LOW);
  }
    if((LS == 1 && MS == 1 && RS == 0))    // turn left again
  {
    analogWrite(motorA, 200);
    digitalWrite(in1A, HIGH);
    digitalWrite(in2A, LOW);
    analogWrite(motorB, 200);
    digitalWrite(in1B, LOW);
    digitalWrite(in2B, LOW);
  }
   if((LS == 0 && MS == 0 && RS == 0))     // stop
  {
    analogWrite(motorA, 200);
    digitalWrite(in1A, LOW);
    digitalWrite(in2A, LOW);
    analogWrite(motorB, 200);
    digitalWrite(in1B, LOW);
    digitalWrite(in2B, LOW);
  }
  
}
