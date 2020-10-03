int in1A = 10;
int in2A = 11;  
int motorA = 9;  

int in1B = 6;
int in2B = 5;
int motorB = 3;

int RS = A2;
int MS = A1;
int LS = A0;


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
  RS = digitalRead(A0);
  MS = digitalRead(A1);
  LS = digitalRead(A2);
Serial.println(digitalRead(A1));
  if((LS == 0 && MS == 1 && RS == 0))     // Move Forward
  {
    analogWrite(motorA, 120);
    digitalWrite(in1A, HIGH);
    digitalWrite(in2A, LOW);
    analogWrite(motorB, 120);
    digitalWrite(in1B, HIGH);
    digitalWrite(in2B, LOW);
  }
  
   if((LS == 0 && MS == 0 && RS == 1))     // Turn right
  {
    analogWrite(motorA, 120);
    digitalWrite(in1A, LOW);
    digitalWrite(in2A, LOW);
    analogWrite(motorB, 120);
    digitalWrite(in1B, LOW);
    digitalWrite(in2B, HIGH);
  }
  
   if((LS == 1 && MS == 0 && RS == 0))    // turn left
  {
    analogWrite(motorA, 120);
    digitalWrite(in1A, HIGH);
    digitalWrite(in2A, LOW);
    analogWrite(motorB, 120);
    digitalWrite(in1B, LOW);
    digitalWrite(in2B, LOW);
  }
  
   if((LS == 1  && MS == 1 && RS == 1))     // stop
  {
    analogWrite(motorA, 80);
    digitalWrite(in1A, LOW);
    digitalWrite(in2A, LOW);
    analogWrite(motorB, 80);
    digitalWrite(in1B, LOW);
    digitalWrite(in2B, LOW);
  }
  if((LS == 1 && MS == 0 && RS == 0))    // turn left
  {
    analogWrite(motorA, 120);
    digitalWrite(in1A, HIGH);
    digitalWrite(in2A, LOW);
    analogWrite(motorB, 120);
    digitalWrite(in1B, LOW);
    digitalWrite(in2B, LOW);
  }
}
