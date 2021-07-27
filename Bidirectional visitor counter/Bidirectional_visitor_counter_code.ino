#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int pir1=6,pir2=7;
const int green=8,red=9;
int in=0,out=0;
void setup() 
{  
  lcd.begin(16, 2); 
  pinMode(pir1, INPUT);
  pinMode(pir2, INPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  lcd.begin(16, 2);
  lcd.setCursor(3, 0);
  lcd.print("G  CHANDAN");
  lcd.setCursor(4, 1);
  lcd.print("PROJECTS");
  delay(800);
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("PROJECT");
  lcd.setCursor(2, 1);
  lcd.print("BIDIRECTIONAL");
  delay(800);
  lcd.clear(); 
  lcd.setCursor(4, 0);
  lcd.print("PROJECT");
  lcd.setCursor(0, 1);
  lcd.print("VISITOR COUNTER");
  delay(800);
}

void loop() 
{
 if (digitalRead(pir1))
 {
   digitalWrite(green,HIGH);
   in = in+1;
   delay(1000);
 }
  else  
   digitalWrite(green,LOW);   
  
  if (digitalRead(pir2))
 {
   digitalWrite(red,HIGH);
   out = out+1;      
   delay(1000); 
 }
  else
   digitalWrite(red,LOW);
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print("WELCOME");
  lcd.setCursor(1,1);
  lcd.print("IN:");
  lcd.setCursor(4,1);
  lcd.print(in);
  lcd.setCursor(10,1);
  lcd.print("OUT:");
  lcd.setCursor(14,1);
  lcd.print(out);
  delay(1000); 
}
 
