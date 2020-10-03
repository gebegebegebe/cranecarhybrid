/*------ Arduino Line Follower Code----- */
/*-------definning Inputs------*/
#define MS 0
#define LS 2      // left sensor
#define RS 1      // right sensor
/*-------definning Outputs------*/
#define LM1 5       // left motor
#define LM2 6       // left motor
#define RM1 10       // right motor
#define RM2 11       // right motor
void setup()
{
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
}
void loop()
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
