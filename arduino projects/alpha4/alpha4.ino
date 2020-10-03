int motorpin1l = 9 ;
int motorpin2l = 8 ;            
int motorpin1r = 12 ;               
int motorpin2r = 13;
int enable1    = 10;            // MIGHT NEED TO TURN THESE ON
int enable2    = 11 ;            
int state = 0;
int valueleft  = 0 ;                     
int valueright = 0 ;      
boolean debug  = true;

void setup() {
  pinMode(motorpin1l, OUTPUT);    
  pinMode(motorpin2l, OUTPUT); 
  pinMode(motorpin1r, OUTPUT); 
  pinMode(motorpin2r, OUTPUT);
  Serial.begin(9600); 
}
void loop() {
   //Speed
   analogWrite(enable1, 150);
   analogWrite(enable2, 150);
  
  if (Serial.available() > 0) {
    state = Serial.read();
    
/*    while (state) 
                              
    {
      valueleft  = bluetooth.parseInt();  
   
      valueright = bluetooth.parseInt();
       if ((state>0) and (state<255))
        if (debug) {             
          Serial.print("left: ");   
          Serial.println(valueleft);
          Serial.print("right: ");
          Serial.println(valueright);
          
                 }

        if (bluetooth.read() == ',') {
          analogWrite(enable1, valueleft); 

                 }
                 
        else if (bluetooth.read() == '\n') {
          analogWrite(enable2, valueright);
         
                 }
*/                 
       if (state == 'a'){ //forward
          digitalWrite(motorpin1l, HIGH);
          digitalWrite(motorpin2l, LOW);
          digitalWrite(motorpin1r, HIGH);
          digitalWrite(motorpin2r, LOW);
        }
       else if (state == 'b'){ //left
          digitalWrite(motorpin1l, HIGH);
          digitalWrite(motorpin2l, LOW);
          digitalWrite(motorpin1r, LOW);
          digitalWrite(motorpin2r, LOW);
        }
       else if (state == 'c'){ //stop
          digitalWrite(motorpin1l, LOW);
          digitalWrite(motorpin2l, LOW);
          digitalWrite(motorpin1r, LOW);
          digitalWrite(motorpin2r, LOW);
        }
       else if (state == 'd'){ //right
          digitalWrite(motorpin1l, LOW);
          digitalWrite(motorpin2l, LOW);
          digitalWrite(motorpin1r, HIGH);
          digitalWrite(motorpin2r, LOW);
        }
       else if (state == 'e'){ //back
          digitalWrite(motorpin1l, LOW);
          digitalWrite(motorpin2l, HIGH);
          digitalWrite(motorpin1r, LOW);
          digitalWrite(motorpin2r, HIGH);
        }
       
       
  
       
            
           }
      }
    


