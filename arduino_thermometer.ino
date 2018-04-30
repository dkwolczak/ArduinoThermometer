#include <LiquidCrystal.h>  
#define   sensor    0       

// Variables: 
 int Vin;                   
 float Temp;                
 float TF;                  
 float TC;                  
 int redLedPin= 13;         
 int switchState = 0;      


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(redLedPin, OUTPUT); 
  pinMode(13,OUTPUT);
pinMode(8, INPUT);
  
  lcd.begin(16,2);        
  lcd.print("The Temp is:");     
}


void loop() {
switchState = digitalRead(8);


  
  digitalWrite(redLedPin, HIGH);
  Vin = analogRead(sensor);
  Temp=(500*Vin)/1023;

  TF = ((9*Temp)/5)+32;   
  TC = ((9*Temp)/5)+0;

  lcd.setCursor(0, 1);
  lcd.print(Temp);
  

  lcd.setCursor(8, 2);
  lcd.print("C");    

if (switchState == LOW && Temp > 40) {
  digitalWrite(13, LOW);
}
else{ digitalWrite(13, HIGH);
}

  delay(1000);
}

