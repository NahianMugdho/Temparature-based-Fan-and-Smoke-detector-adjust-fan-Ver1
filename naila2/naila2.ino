#include<Wire.h>
#include<LiquidCrystal_I2C.h>
const int en = 2, rw = 1, rs = 0, d4 = 4, d5 = 5, d6 = 6, d7 = 7, bl = 3;
const int i2c_addr = 0x27;

LiquidCrystal_I2C lcd(i2c_addr, en, rw, rs, d4, d5, d6, d7, bl,POSITIVE);


int gs = A0;
int vout =A1;
int buzz =10;


int fanA =6;
int fanB =7;
int fanpwm = 9;
int spd = 200;


int fanC=  2;
int fanD=  4;
int fanpwm2 = 3;


int smoke;
float temp;
float vout_temp;
float temp1;

void fanon()
{
  analogWrite(fanpwm,spd);
  digitalWrite(fanA,HIGH);
  digitalWrite (fanB,LOW); 
}

void adjon()
{
  analogWrite(fanpwm2,spd);
  digitalWrite(fanC,HIGH);
  digitalWrite (fanD,LOW); 
}
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  Serial.begin(9600);
  
  pinMode(buzz,OUTPUT);
  pinMode(fanA,OUTPUT);
  pinMode(fanB,OUTPUT);
  pinMode(fanpwm,OUTPUT);
}

void loop() {
  
  smoke = analogRead(gs);
  vout_temp = analogRead(vout);
  temp1 = (vout_temp * 500) / 1023;

  
 
  
  if(smoke>80)
  {
    
    adjon();
    digitalWrite(buzz,HIGH);
  }
  else
  {
    digitalWrite(fanC,LOW);
   digitalWrite (fanD,LOW);
    digitalWrite(buzz,LOW);
    
  }

  if(temp1>25)
  {
    fanon();
    
  }
  else
  {
     digitalWrite(fanA,LOW);
     digitalWrite (fanB,LOW);
   
  }
 Serial.print("Temp:");
  Serial.print(temp1);
  Serial.println("Gas Density:");
  Serial.print(smoke);
  
  
  lcd.setCursor(0, 0);
  
  lcd.print("Temp:");
  lcd.print(temp1);
  lcd.print("*C");
  lcd.setCursor(0, 1);
 
  lcd.print("Gas Density: ");
  lcd.print(smoke);
  delay(5000);
  

}
