#include <LiquidCrystal.h>
#include<Servo.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int trig_pin=10;
const int echo_pin=7;
long duration;
int distance;
int servopin=8;
Servo servo_test;
const int pirpin=13;
const int light=6;
int sensorstate=0;
const int temp_pin=A0;
float temp;
const int motor=9;

void setup()
{
  pinMode(temp_pin,INPUT);
  pinMode(trig_pin,OUTPUT);
  pinMode(echo_pin,INPUT);
  Serial.begin(9600);
  servo_test.attach(servopin);
  pinMode(light,OUTPUT);
  pinMode(pirpin,INPUT);
  lcd.begin(16, 2);
  lcd.setCursor(3, 0);
  lcd.print("G  CHANDAN");
  lcd.setCursor(4, 1);
  lcd.print("PROJECTS");
  delay(800);
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("PROJECT");
  lcd.setCursor(0, 1);
  lcd.print("HOME AUTOMATION");
  delay(800);
  lcd.clear(); 
}

void loop()
{
  digitalWrite(trig_pin,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin,LOW);
  duration = pulseIn(echo_pin,HIGH);
  distance= duration*0.034/2;
  
  if(distance<100)
  {
  servo_test.write(90);
  delay(3000);
  servo_test.write(0);
  delay(5000);
  lcd.setCursor(0,1);
  lcd.print("   open the gate  ");
  }
  else
  {
      
   lcd.setCursor(0,1);
   lcd.print("  close the gate  ");
  }
    
   sensorstate=digitalRead(pirpin);
  if(sensorstate)
  {
    digitalWrite(light,HIGH);
    lcd.setCursor(0,1);
    lcd.print("  On the lights   ");
    delay(1000);
  }
  else
  {
    digitalWrite(light,LOW);
     delay(1000);
  }
  
  temp=analogRead(temp_pin)*0.00488*100;
  Serial.print("Temperature");
  Serial.println(temp,0);
  delay(2000);
  if(temp>=60)
  {
    lcd.clear();
    digitalWrite(motor,1);
    lcd.setCursor(0,1);
    lcd.print("FAN IS ON");
    delay(1000);
   }
  else
 {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("FAN IS OFF");
    digitalWrite(motor,0);
}
}
  
 
