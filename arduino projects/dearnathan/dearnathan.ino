int MotorA = 9;
int in1A = 10;
int in2A = 11;

int MotorB = 3;
int in1B = 5;
int in2B = 6;

const int trigPin = 7;
const int echoPin = 4;

//define variables
long duration;
int distance;


void setup() {
  pinMode (in1A, OUTPUT);
  pinMode (in2A, OUTPUT);
  pinMode (MotorA, OUTPUT);
  pinMode (in1B, OUTPUT);
  pinMode (in2B, OUTPUT);
  pinMode (MotorB, OUTPUT);
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);

Serial.begin(9600);

}

void loop() {
//Clears trigPin
digitalWrite (trigPin, LOW);
delayMicroseconds (2);

//Sets the trigPin on HIGH State for 10 ms 
digitalWrite (trigPin, HIGH);
delayMicroseconds (10);
digitalWrite (trigPin, LOW);

//Reads the echoPin, returns the sound wave travel time in ms
duration = pulseIn (echoPin, HIGH);

//Calculating the distance
distance = duration*0.034/2;

//Prints the distance on the Serial Monitor
Serial.print ("Distance: ");
Serial.println(distance);

if (distance > 10) {
  //Forward A
  analogWrite(MotorA, 100);
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, HIGH);

  //Forward B
  analogWrite(MotorB, 100);
  digitalWrite(in1B, LOW);
  digitalWrite(in2B, HIGH);
}
else
{
  //Stop
  analogWrite(MotorA, 0);
  analogWrite(MotorB, 0);
  delay(600);

  //Turn Left
    //Reverse A
    analogWrite(MotorA, 100);
    digitalWrite(in1A, HIGH);
    digitalWrite(in2A, LOW);
  

    //Forward B
    analogWrite(MotorB, 100);
    digitalWrite(in1B, LOW);
    digitalWrite(in2B, HIGH);
    delay(1000);
}


}




