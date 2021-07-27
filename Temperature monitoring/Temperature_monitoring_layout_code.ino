#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int fan=8;
const int buzzer=7;
const int led=13;
const int temp_sensor= A0;
float temp_value;
void setup() 
{  
  Serial.begin(9600);
  pinMode(temp_sensor, INPUT);
  pinMode(led, OUTPUT);
  pinMode(fan, OUTPUT);
  pinMode(buzzer, OUTPUT);
  lcd.begin(16, 2);
  lcd.setCursor(3, 0);
  lcd.print("G  CHANDAN");
  lcd.setCursor(4, 1);
  lcd.print("PROJECTSS");
  delay(800);
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("PROJECT");
  lcd.setCursor(2, 0);
  lcd.print("TEMPERATURE");
  lcd.setCursor(5, 1);
  lcd.print("MONITORING");
  delay(800);
  lcd.clear();  
}

void loop() 
{
  temp_value=analogRead(temp_sensor)*0.00488*100;
  lcd.setCursor(1,0);
  lcd.print("Temperature:");
  lcd.print(temp_value,0);
  delay(200);
  if (temp_value >= 60)
  {
    digitalWrite(led,HIGH);
    digitalWrite(fan,HIGH);
    digitalWrite(buzzer,HIGH);
    lcd.setCursor(3,1);
    lcd.print("FAN is  ON");
    delay(200);
  }  
  else
  {
    digitalWrite(led,LOW);
    digitalWrite(fan,LOW);
    digitalWrite(buzzer,LOW);
    lcd.setCursor(3,1);
    lcd.print("FAN is OFF");
    delay(200);
  }
  lcd.clear(); 
}
