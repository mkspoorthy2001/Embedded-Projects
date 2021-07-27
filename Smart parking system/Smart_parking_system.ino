#include <LiquidCrystal.h>
#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
const int pir1=A3,pir2=A4,pir3=A5;
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
const int trig=8;
const int echo1=A0,echo2=A1,echo3=A2;
long duration1,duration2,duration3;
float distance1,distance2,distance3;
int A,B,C;
void setup() 
{  
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(trig, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(echo2, INPUT);
  pinMode(echo3, INPUT);
  
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
  servo1.write(90);           
  servo2.write(90);
  servo3.write(90);
  delay(3000); 
  
  lcd.begin(16, 2);
  lcd.setCursor(4, 0);
  lcd.print("SPOORTHY");
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
  lcd.setCursor(1, 1);
  lcd.print("PARKING SYSTEM");
  delay(800);
  lcd.clear(); 
  
}

void loop()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2); 
  digitalWrite(trig, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trig, LOW);
  
  duration1=pulseIn(echo1,HIGH);
  distance1=duration1*0.034/2;
  
  duration2=pulseIn(echo2,HIGH);
  distance2=duration2*0.034/2;
  
  duration3=pulseIn(echo3,HIGH);
  distance3=duration3*0.034/2;
  
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("PARKING STATUS"); 
  
  if (A)
  {
    lcd.setCursor(0,1);
    lcd.print("F1");
    delay(100);
  }
  else
  {
    lcd.setCursor(0,1);
    lcd.print("E1");
    delay(100);
  }
  
  if (B)
  {
    lcd.setCursor(4,1);
    lcd.print("F2");
    delay(100);
  }
  else
  {
    lcd.setCursor(4,1);
    lcd.print("E2");
    delay(100);
  }
  
  if (C)
  {
    lcd.setCursor(8,1);
    lcd.print("F3");
    delay(100);
  }
  else
  {
    lcd.setCursor(8,1);
    lcd.print("E3");
    delay(100);
  }
    
    
  if ((distance1>0)&&(distance1<308))
    A=1;
  
  else
    A=0;  
  
  if ((distance2>0)&&(distance2<308))
    B=1;
  else
    B=0;
  
  if ((distance3>0)&&(distance3<308))
    C=1;  
  else
    C=0;
  
  
  if (analogRead(pir1)>100)
  {
    servo1.write(0);
    delay(100);
  }
  else
  {
    servo1.write(90);
    delay(100);
  }
  
  if (analogRead(pir2)>100)
  {
    servo2.write(0);
    delay(100);
  }
  else
  {
    servo2.write(90);
    delay(100);
  }
  
  if (analogRead(pir3)>100)
  {
    servo3.write(0);
    delay(100);
  }
  else
  {
    servo3.write(90);
    delay(100);
  }
  
}
