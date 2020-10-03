#include <SoftwareSerial.h>

SoftwareSerial BT(5, 6); 
// creates a "virtual" BT port/UART
// connect BT module TX to D10
// connect BT module RX to D11
// connect BT Vcc to 5V, GND to GND

#define E1 10  // Enable Pin for motor 1
#define E2 11  // Enable Pin for motor 2
#define I1 9  // Control pin 1 for motor 1
#define I2 8  // Control pin 2 for motor 1
#define I3 12  // Control pin 1 for motor 2
#define I4 13  // Control pin 2 for motor 2
int state      = 0 ;
int valueleft  = 0 ;                     
int valueright = 0 ; 

void setup()  
{    
    pinMode(E1, OUTPUT);
    pinMode(E2, OUTPUT);
    pinMode(I1, OUTPUT);
    pinMode(I2, OUTPUT);
    pinMode(I3, OUTPUT);
    pinMode(I4, OUTPUT);


  // set the data rate for the SoftwareBT port
  BT.begin(9600);

  // Send test message to other device
  BT.println("Hello from Arduino");
}

char a; // stores incoming character from other device

void loop() 
{
 a=(BT.read());
//Set Speed
    analogWrite(E1, 160);
    analogWrite(E2, 180);


if (BT.available())  
  {
      valueleft  = BT.parseInt();  
   
      valueright = BT.parseInt();
       if ((a>0) and (a<255))
        {             
          BT.print("left: ");   
          BT.println(valueleft);
          BT.print("right: ");
          BT.println(valueright);
          
                 }

        if (BT.read() == ',') {
          analogWrite(E1, valueleft); 

                 }
                 
        else if (BT.read() == '\n') {
          analogWrite(E2, valueright);
         
                 };

  }  
 
 
  if (a == 'a') {
    digitalWrite(I1, HIGH);
    digitalWrite(I2, LOW);
    digitalWrite(I3, HIGH);
    digitalWrite(I4, LOW);
    }
  
  else if (a == 'b') {
    digitalWrite(I1, HIGH);
    digitalWrite(I2, LOW);
    digitalWrite(I3, LOW);
    digitalWrite(I4, LOW);
    }
 
  else if (a == 'c') {
    digitalWrite(I1, LOW);
    digitalWrite(I2, LOW);
    digitalWrite(I3, HIGH);
    digitalWrite(I4, LOW);
    } 
 
  else if (a == 'd') {
    digitalWrite(I1, LOW);
    digitalWrite(I2, HIGH);
    digitalWrite(I3, LOW);
    digitalWrite(I4, HIGH);
    }

  else if (a == NULL) {
    digitalWrite(I1, LOW);
    digitalWrite(I2, LOW);
    digitalWrite(I3, LOW);
    digitalWrite(I4, LOW);
    }
 }


