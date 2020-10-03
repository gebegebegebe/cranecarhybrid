int motorA ;
int In1A;
int In2A;

int motorB;
int In1B;
int In2B;

int LS;
int MS;
int RS;

void setup()
{
  pinMode(In1A, OUTPUT);
  pinMode(In2A, OUTPUT);
  pinMode(In1B, OUTPUT);
  pinMode(In2B, OUTPUT);
  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  
}
void loop()
;
LS = digitalRead(A2);
MS = digitalRead(A0);
RS = digitalRead(A1);

{
  if(digitalRead(LS) && digitalRead(RS) && !digitalRead(MS))     // Move Forward
  {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }
  
   if(digitalRead(LS) && !digitalRead(RS) && digitalRead(MS))     // Turn right
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }
  
   if(!digitalRead(LS) && digitalRead(RS) && digitalRead(MS))    // turn left
  {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  }
  
   if(digitalRead(LS) && digitalRead(RS) && digitalRead(MS))     // stop
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  }
}
