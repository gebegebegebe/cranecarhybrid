#define MS 1      // middle sensor
#define LS 2      // left sensor
#define RS 0      // right sensor
#define LM1 5       // left motor
#define LM2 6       // left motor
#define RM1 10       // right motor
#define RM2 11       // right motor
#define In1 3
#define In2 9
void setup()
{
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(MS, INPUT);
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
}
void loop()
{
Serial.println(digitalRead(A1));
  if(digitalRead(LS) && digitalRead(RS) && !digitalRead(MS))     // Move Forward
  {
    analogWrite(In1, 150);
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    analogWrite(In2, 150);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }
  
   if(digitalRead(LS) && !digitalRead(RS) && digitalRead(MS))     // Turn right
  {
    analogWrite(In1, 150);
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    analogWrite(In2, 150);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }
  
   if(!digitalRead(LS) && digitalRead(RS) && digitalRead(MS))    // turn left
  {
    analogWrite(In1, 150);
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    analogWrite(In2, 150);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  }
  
   if(digitalRead(LS) && digitalRead(RS) && digitalRead(MS))     // stop
  {
    analogWrite(In1, 150);
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    analogWrite(In2, 150);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  }
}
