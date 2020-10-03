#include <SoftwareSerial.h>
SoftwareSerial bluetooth(2, 5); // Demand the lib SoftwareSerial 
int motorpin1l = 9 ;
int motorpin2l = 6 ;            
int motorpin1r = 5 ;               
int motorpin2r = 10;
int enable1    = 11;            // MIGHT NEED TO TURN THESE ON
int enable2    = 3 ;            
int valueleft  = 0 ;                     
int valueright = 0 ;      
boolean debug  = true;
void setup() {
  Serial.begin(115200);        // Begin Arduino Serial
  bluetooth.begin(115200);     // in the same baudrate as bluetooth
  Serial.println("MIT App Inventor 2");  
                               // Print smartphone 
                               //software version 
  Serial.println("Release nb151 - Sep 13, 2016"); 
                               // see:   
                               // http://ai2.appinventor.mit.edu/
  pinMode(motorpin1l, OUTPUT);    
  pinMode(motorpin2l, OUTPUT); 
  pinMode(motorpin1r, OUTPUT); 
  pinMode(motorpin2r, OUTPUT); 
}
void loop() {
  if (bluetooth.available()) {
    while (bluetooth.available()) 
                              
    {
      valueleft  = bluetooth.parseInt();  
   
      valueright = bluetooth.parseInt();
       if ((bluetooth.available()>0) and (bluetooth.available()<255))
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
                 
       else if (bluetooth.available() == 'a'){ //forward
          digitalWrite(motorpin1l, HIGH);
          digitalWrite(motorpin2l, LOW);
          digitalWrite(motorpin1r, HIGH);
          digitalWrite(motorpin2r, LOW);
        }
       else if (bluetooth.available() == 'b'){ //left
          digitalWrite(motorpin1l, HIGH);
          digitalWrite(motorpin2l, LOW);
          digitalWrite(motorpin1r, LOW);
          digitalWrite(motorpin2r, LOW);
        }
       else if (bluetooth.available() == 'c'){ //stop
          digitalWrite(motorpin1l, LOW);
          digitalWrite(motorpin2l, LOW);
          digitalWrite(motorpin1r, LOW);
          digitalWrite(motorpin2r, LOW);
        }
       else if (bluetooth.available() == 'd'){ //right
          digitalWrite(motorpin1l, LOW);
          digitalWrite(motorpin2l, LOW);
          digitalWrite(motorpin1r, HIGH);
          digitalWrite(motorpin2r, LOW);
        }
       else if (bluetooth.available() == 'e'){ //back
          digitalWrite(motorpin1l, LOW);
          digitalWrite(motorpin2l, HIGH);
          digitalWrite(motorpin1r, LOW);
          digitalWrite(motorpin2r, HIGH);
        }
       
       
  
       
                }
           }
      }
    


