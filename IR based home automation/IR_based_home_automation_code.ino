#include<IRremote.h>
int RECV_PIN=9;
IRrecv irrecv(RECV_PIN);
decode_results results;
int red=11;
int green=13;
int blue=10;
int fan=12;
int val=0;
int status1=0,status2=0,status3=0,status4=0;

void setup()
{
  Serial.begin(9600);
  Serial.println("BULB(0)| FAN1(1)| FAN2(2)| BUZZER(3)| TURN OFF ALL (POWER)");
  irrecv.enableIRIn();
  
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
}
void loop()
{
 
  if(irrecv.decode(&results))
  {
    
    if(results.value==16593103)
    {
      status1=(!status1);
      digitalWrite(13,status1);
    }
    
    if(results.value==16582903)
    {
      status2=(!status2);
      digitalWrite(12,status2);
    }
    if(results.value==16599223)
    {
      status3=(!status3);
      digitalWrite(10,status3);
    }
    
    if(results.value==16615543)
    { status4=(!status4);
      digitalWrite(11,status4);
    }
    if(results.value==16580863)
    {
       digitalWrite(13,LOW);
       digitalWrite(12,LOW);
       digitalWrite(11,LOW);
       digitalWrite(10,LOW);
    }
    irrecv.resume();  
  }
  if(digitalRead(9))
  {
      while(digitalRead(9));
      val=(!val);
      digitalWrite(9,val);
  }
}
  
