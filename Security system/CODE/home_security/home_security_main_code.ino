const int wall=2,garden_pir=3,door_window=4,fire=6,gas=5,greenled=8,security_system=9,gsm=7;
int red,green,a,b;
void setup() 
{
  Serial.begin(9600);
  pinMode(wall, INPUT);
  pinMode(garden_pir, INPUT);
  pinMode(door_window, INPUT);
  pinMode(fire, INPUT);
  pinMode(gas, INPUT);
  pinMode(gsm, OUTPUT);
}
void loop()
{
  statuscheck();
  delay(1000);
}

void statuscheck()
{
  if(digitalRead(security_system)==1)
  {
    Serial.println("Security System Activated");
    delay(1000);
    system_activated();
  }
  else
  Serial.println("Security System Deactivated");
  delay(1000);
}

void system_activated() 
{
 
  gasloop(); 
  
}

void level1()
{
  if(digitalRead(wall)== 1)
  {
   Serial.println("LEVEL 1 BREACH");
   delay(2000);
   while(1)
   level2();
  }
  else
  {
    delay(2000);
    system_activated();
  }
}

void level2()
{
  if(digitalRead(garden_pir)==1)
  {
    Serial.println("LEVEL 2 BREACH");
    while(1)
    level3();
  }
  else
  {
    Serial.println("WARNING ALEART");
    delay(2000);
    level2;
  }
}

void level3()
{
  if(digitalRead(door_window)==1)
  {
    Serial.println("LEVEL 3 BREACH");
    digitalWrite(gsm, LOW);
    delay(2000);
    while(1)
    statuscheck();
  }
  else if(digitalRead(door_window)==0)
  {
   Serial.println("RED ALERT !!! DANGER");
   digitalWrite(gsm, HIGH);
   delay(2000);
   level3();
  }
}


void gasloop()
{
  if(digitalRead(gas)==1)
  {
    Serial.println("GAS LEAKAGE");
    delay(1000);
    
    level1();
  }
  else
  {
      
    level1();
  }
    
  if(digitalRead(fire)==1)
  {
    Serial.println("FIRE/SMOKE DETECTED");
    delay(1000);
    
  }
  else
  {    
    level1();
  }
  
}
