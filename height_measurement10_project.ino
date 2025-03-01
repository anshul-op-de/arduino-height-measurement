/* trigger pin of ultrsonic sensor is connected to digital pin 7 of arduino
   and echo pin is connected to digital pin 8
*/
//lcd
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int numRows = 2;
const int numCols = 16;

//ultrasonic sensor
const int echo=3;
const int trigg=2;
const int set=8;

long distcm ,distinches ,totalht_cm ,totalht_inches ,ht_cm ,ht_inches;


//function to find time interval between transmission and reception of pulse
long pulseduration(){
  long timeinterval;
  digitalWrite(trigg,LOW);
  delayMicroseconds(2);
  digitalWrite(trigg,HIGH);
  delayMicroseconds(5);
  digitalWrite(trigg,LOW);
  timeinterval = pulseIn(echo,HIGH);
  return timeinterval; 
}
//function to convert duration to cm
long microsectocm(long t)
{
  return(t*0.0175);
}
//function to convert duration to cm
long microsectoinches(long t)
{
  return(t*0.00689);
}

void setup() {
  Serial.begin(9600);
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
 // pinMode(A2,OUTPUT);
  //pinMode(A3,OUTPUT);
  pinMode(trigg,OUTPUT);
  pinMode(echo,INPUT);

  analogWrite(A0,LOW);
  analogWrite(A1,HIGH);
  //analogWrite(A2,LOW);
  //analogWrite(A3,HIGH);
  
  totalht_cm = microsectocm( pulseduration());
  totalht_inches = microsectoinches( pulseduration());
  lcd.begin(numCols,numRows);
  lcd.print("HEIGHT MEASURING");
  delay(500);
  lcd.clear();
}

void loop() {
  /*if(digitalRead(set)==HIGH){
    
    Serial.println("ON");
    }*/
  distcm = microsectocm( pulseduration());
  distinches = microsectoinches( pulseduration());
  ht_cm = totalht_cm - distcm;
  ht_inches = totalht_inches - distinches; 
  Serial.print(distinches);
  Serial.print("in, ");
  Serial.print(distcm);
  Serial.print("cm");
  Serial.println();
  delay(1000);
//lcd part
  lcd.setCursor(0,0);
  lcd.print(ht_cm);
  lcd.setCursor(5,0);
  lcd.print(" cm");
  lcd.setCursor(0,1);
  lcd.print(ht_inches);
  lcd.setCursor(5,1);
  lcd.print(" inches");
  delay(2000);
  lcd.setCursor(0,0);
  lcd.print("   ");
  lcd.setCursor(0,1);
  lcd.print("   ");
}










