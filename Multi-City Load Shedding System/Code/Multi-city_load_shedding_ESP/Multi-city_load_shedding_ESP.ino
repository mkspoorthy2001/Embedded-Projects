#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "3pRJv2v6AyxfugXsxjDxaCohDX2XVS7y";
char ssid[] = "XXXX";
char pass[] = "XXXXX";
BlynkTimer timer;
WidgetLCD lcd(V2);
String text;
void myTimerEvent()
{
  Blynk.virtualWrite(V2, millis() / 1000);
}

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);  
  timer.setInterval(1000L, myTimerEvent);
  lcd.clear();
  lcd.print(3,0,"MULTI-CITY");
  lcd.print(1,1,"LOAD  SHEDDING"); 
  delay(1000);
  
}

void loop()
{
  if(Serial.available() > 0)
  {
    text = Serial.readString();
  }

}
