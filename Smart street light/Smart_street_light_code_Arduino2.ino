#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
const int street_light1=13,street_light2=12,street_light3=11,street_light4=10;
const int ldr=A0;
const int A=A2,B=A3,C=A4,D=A5;
String text;
void setup() 
{  
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.begin(16, 2);
  lcd.setCursor(3, 0);
  lcd.print("G  CHANDAN");
  lcd.setCursor(4, 1);
  lcd.print("PROJECTS");
  delay(800);
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("PROJECT");
  delay(800);
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("SMART");
  lcd.setCursor(2, 1);
  lcd.print("STREET LIGHT");
  delay(800);
  lcd.clear(); 
  
  pinMode(street_light1, OUTPUT);
  pinMode(street_light2, OUTPUT);
  pinMode(street_light3, OUTPUT);
  pinMode(street_light4, OUTPUT);
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  pinMode(C, INPUT);
  pinMode(D, INPUT);
  pinMode(ldr, INPUT);  
}

void loop()
{
 if (analogRead(ldr)>20)
   day();
 else
   night(); 
}

void day() 
{ 
  digitalWrite(street_light1, LOW);
  digitalWrite(street_light2, LOW);
  digitalWrite(street_light3, LOW);
  digitalWrite(street_light4, LOW);
  lcd.setCursor(5,0);
  lcd.print("SUNNY");
  lcd.setCursor(4,1);
  lcd.print("MORNING"); 
  delay(500);
  lcd.clear();
}

void night() 
{ 
  digitalWrite(street_light1, LOW);
  digitalWrite(street_light2, LOW);
  digitalWrite(street_light3, LOW);
  digitalWrite(street_light4, LOW);
  lcd.setCursor(6,0);
  lcd.print("DARK");
  lcd.setCursor(5,1);
  lcd.print("NIGHT"); 
  delay(100);
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("NO MOVEMENT");
  lcd.setCursor(1,1);
  lcd.print("ALL LIGHTS OFF"); 
  delay(100);
  lcd.clear();  
  
    
  if (((analogRead(A1))>150))
  {
   lcd.setCursor(4,0);
   lcd.print("MOVEMENT");
   lcd.setCursor(0,1);
   lcd.print("L1"); 
   digitalWrite(street_light1, HIGH);
   digitalWrite(street_light2, LOW);
   digitalWrite(street_light3, LOW);
   digitalWrite(street_light4, LOW);
    delay(1000);
   lcd.clear();
  }
  else
  { digitalWrite(street_light1, LOW);
  digitalWrite(street_light2, LOW);
  digitalWrite(street_light3, LOW);
  digitalWrite(street_light4, LOW);
   
   lcd.clear();
  }
  if (((analogRead(A2))>150))
  {
   lcd.setCursor(4,0);
   lcd.print("MOVEMENT");
   lcd.setCursor(3,1);
   lcd.print("L2"); 
   digitalWrite(street_light1, LOW);
   digitalWrite(street_light2, HIGH);
   digitalWrite(street_light3, LOW);
   digitalWrite(street_light4, LOW);
    delay(1000);
   lcd.clear(); 
  }
  else
  { digitalWrite(street_light1, LOW);
  digitalWrite(street_light2, LOW);
  digitalWrite(street_light3, LOW);
  digitalWrite(street_light4, LOW);
   lcd.clear();
  }
  if (((analogRead(A3))>150))
  {
   lcd.setCursor(4,0);
   lcd.print("MOVEMENT");
   lcd.setCursor(6,1);
   lcd.print("L3");
   digitalWrite(street_light1, LOW);
   digitalWrite(street_light2, LOW);
   digitalWrite(street_light3, HIGH);
   digitalWrite(street_light4, LOW);
    delay(1000);
   lcd.clear();
  }
  else
  { digitalWrite(street_light1, LOW);
  digitalWrite(street_light2, LOW);
  digitalWrite(street_light3, LOW);
  digitalWrite(street_light4, LOW);
   lcd.clear();
  }
  if (((analogRead(A4))>150))
  {
   lcd.setCursor(4,0);
   lcd.print("MOVEMENT");
   lcd.setCursor(8,1);
   lcd.print("L4");
   digitalWrite(street_light1, LOW);
   digitalWrite(street_light2, LOW);
   digitalWrite(street_light3, LOW);
   digitalWrite(street_light4, HIGH);    
   delay(1000);
    lcd.clear();
    
  }
  else
  { digitalWrite(street_light1, LOW);
  digitalWrite(street_light2, LOW);
  digitalWrite(street_light3, LOW);
  digitalWrite(street_light4, LOW);
   lcd.clear();
  }
}
 
