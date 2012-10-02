//Get a nibble (arduino)
int sensorValue = 0;  // variable to store the value coming from the sensor
int datapin0 =7;
int datapin1 =6;
int datapin2 =5;
int datapin3 =4;

struct struct_nibble {
   char bit0;
   char bit1;
   char bit2;
   char bit3;
} nibble1,nibble2,nibble;
 
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
void clearLEDs() {
  digitalWrite(datapin0,LOW);
  digitalWrite(datapin1,LOW);
  digitalWrite(datapin2,LOW);
  digitalWrite(datapin3,LOW);
} 
void prompt_for_input() {
  //ifdef this so it only works on arduino
  Serial.print("Input:\n");
  //do pattern to prompt for input on LEDs
  clearLEDs();
}
  
void edit_nibble() {
  nibble.bit0=0;
  nibble.bit1=0;
  nibble.bit2=0;
  nibble.bit3=0;
  prompt_for_input();
  int button5_pressed=0;
  while(!button5_pressed) {
    int button=0;
    button=button_up();
    switch(button) {
        case 1:
            nibble.bit0=!nibble.bit0;
            break;
        case 2:
            nibble.bit1=!nibble.bit1;
            break;
        case 3:
            nibble.bit2=!nibble.bit2;
            break;
        case 4:
            nibble.bit3=!nibble.bit3;
            break;
        case 5:
            button5_pressed=1;
            break;
        default :
            ;//do nothing if other button pressed
    }
    //update LEDs
    digitalWrite(datapin0,nibble.bit0?HIGH:LOW);
    digitalWrite(datapin1,nibble.bit1?HIGH:LOW);
    digitalWrite(datapin2,nibble.bit2?HIGH:LOW);
    digitalWrite(datapin3,nibble.bit3?HIGH:LOW);
  }
} 

void loop() {
  // read the value from the sensor:
  // turn the ledPin on
  edit_nibble();
  nibble1=nibble;
  Serial.print(nibble1.bit0,DEC);
  Serial.print(nibble1.bit1,DEC);
  Serial.print(nibble1.bit2,DEC);
  Serial.print(nibble1.bit3,DEC);

  //delay(300);
  //which_button_was_pressed(sensorValue);
   Serial.print("\n");
}
