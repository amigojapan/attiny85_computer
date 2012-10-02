//Analogue button tunner
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  Serial.begin(9600);
}

int which_button_was_pressed(int value) {
  int dif=0;
  //Serial.print(value,DEC);
   // Serial.print("\n");
  #define X 5//tolerance
  dif=value-95;//I found it hard to tune the resistors to exact values, so instead I tuned these values to close to the average of the resistor values
  if(dif>-X&&dif<X) return 1;
  dif=value-174;
  if(dif>-X&&dif<X) return 2;
  dif=value-250;
  if(dif>-X&&dif<X) return 3;
  dif=value-337;
  if(dif>-X&&dif<X) return 4;
  dif=value-463;
  if(dif>-X&&dif<X) return 5;
  dif=value-600;
  if(dif>-X&&dif<X) return 6;
  dif=value-693;
  if(dif>-X&&dif<X
  ) return 7;
  return 0;
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(A0);    
  // turn the ledPin on
  Serial.print(which_button_was_pressed(sensorValue),DEC);
  //which_button_was_pressed(sensorValue);
   Serial.print("\n");
}
