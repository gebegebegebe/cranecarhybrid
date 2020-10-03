int SensorA = A0;

void setup() {
Serial.begin(9600);
pinMode(A0, INPUT);

}

void loop() {

Serial.print("status :");
Serial.println(digitalRead(A0));

}
