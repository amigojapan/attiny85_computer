//Analogue button tester (arduino)
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  Serial.begin(9600);
}

int which_button_was_pressed(int value) {
  int dif=0;
  //Serial.print(value,DEC);
   // Serial.print("\n");
  #define X 35//tolerance
  dif=value-240;//I found it hard to tune the resistors to exact values, so instead I tuned these values to close to the average of the resistor values
  if(dif>-X&&dif<X) return 1;
  dif=value-451;
  if(dif>-X&&dif<X) return 2;
  dif=value-640;
  if(dif>-X&&dif<X) return 3;
  dif=value-800;
  if(dif>-X&&dif<X) return 4;
  dif=value-1008;
  if(dif>-X&&dif<X) return 5;
  //dif=value-600;
  //if(dif>-X&&dif<X) return 6;
  //dif=value-693;
  //if(dif>-X&&dif<X) return 7;
  return 0;
}
int read_button(){
  int val0,val1,val2,val3,val4,val5,val6,val7,garbage;
  delay(1);
  garbage=analogRead(A0);
  delay(20);
  val0=analogRead(A0);
  delay(1);
  val1=analogRead(A0);
  delay(1);
  val2=analogRead(A0);
  delay(1);
  val3=analogRead(A0);
  delay(1);
  val4=analogRead(A0);
  delay(1);
  val5=analogRead(A0);
  delay(1);
  val6=analogRead(A0);
  delay(1);
  val7=analogRead(A0);
 
  sensorValue = (val0+val1+val2+val3+val4+val5+val6+val7)/8;//get the average of 4 reads    
  return which_button_was_pressed(sensorValue);
}

int button_down() {
  int button=0;
  button=read_button();
  while(button==0) {
    button=read_button();
  }
  return button;
}

int button_up() {
  int downbutton;
  int button=0;
  downbutton=button_down();
  button=downbutton;
  while(button!=0) {
    button=read_button();
  }
  return downbutton;
  delay(300);
}

void loop() {
  // read the value from the sensor:
  // turn the ledPin on
  Serial.print(button_up(),DEC);
  //delay(300);
  //which_button_was_pressed(sensorValue);
   Serial.print("\n");
}
