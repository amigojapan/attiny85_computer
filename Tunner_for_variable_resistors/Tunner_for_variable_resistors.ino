//Analogue button tunner
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(A0);    
  // turn the ledPin on
  Serial.print(sensorValue,DEC);
   Serial.print("\n");
}
