#include <Servo.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
Servo servo1; 
Servo servo2;
const int pir=8;
void setup() 
{
  pinMode(pir,INPUT);
  lcd.begin(16, 2); 
  servo1.attach(9);
  servo2.attach(10);
  servo1.write(90);           
  servo2.write(90);
  lcd.setCursor(3, 0);
  lcd.print("G  CHANDAN");
  lcd.setCursor(4, 1);
  lcd.print("PROJECTS");
  delay(800);
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("PROJECT");
  lcd.setCursor(1, 1);
  lcd.print("AUTOMATIC DOOR");
  lcd.clear();  
  delay(1000);
}

void loop() 
{
  lcd.setCursor(5,0);
  lcd.print("WELCOME");
  
  if (digitalRead(pir))
  {
    lcd.setCursor(2,1);
    lcd.print("DOOR  OPENED");
    servo1.write(0);
    servo2.write(0);
    delay(1000);
  }
  else
  {
    lcd.setCursor(2,1);
    lcd.print("DOOR  CLOSED");
    servo1.write(90);
    servo2.write(90);
    delay(1000);
  }
  
    
}
