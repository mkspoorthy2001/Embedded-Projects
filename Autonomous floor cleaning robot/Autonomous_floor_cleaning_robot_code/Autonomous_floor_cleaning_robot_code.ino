int RightMotorIn1 = 2;
int RightMotorIn2 = 3;
int LeftMotorIn1 =  4;
int LeftMotorIn2 =  5;
#define echoPin 12 
#define trigPin 11
long duration;
int distance,a=600;
#define mopping 7

void setup() 
{
 Serial.begin(9600);
 
 pinMode(trigPin, OUTPUT); 
 pinMode(echoPin, INPUT); 
 pinMode(RightMotorIn1,OUTPUT);
 pinMode(RightMotorIn2,OUTPUT);
 pinMode(LeftMotorIn1,OUTPUT);
 pinMode(LeftMotorIn2,OUTPUT);
 pinMode(mopping,OUTPUT);
// pinMode(side_check,INPUT);
 digitalWrite(mopping, HIGH);
 delay(200);
}

String Text;


void loop()
{
 digitalWrite(mopping, HIGH);
 if(Serial.available() > 0)
  {
    Text = Serial.readString();
  }
  
  while(1)
  {
    if(Serial.available() > 0)
  {
    Text = Serial.readString();
  }
  if((Text == "manual") || (Text == "Manual"))
  { 
    Serial.println("\t\t\t Manual MODE :"); 
    delay(1000);
    Manual();
    Text = "0"; 
  } 
  else if((Text == "automatic") || (Text == "Automatic"))
  {     
    Serial.println("\t\t\t Auto MODE   :");
    Serial.println("\t\t\t\t\t MOPPING MODE   :");
    delay(1000);
    Auto(); 
    Text = "0";     
  }
 }
}

 void Manual(void)
 {
  while(1)
 {
  
  
  if(Serial.available() > 0)
 
  {
    Text = Serial.readString();
  }
  
    if ((Text == "w") || (Text == "W") || (Text == "Forward")|| (Text == "forward"))
    {
     Serial.println("\t\t\t\t       Forward");
     Forward();
     Text="0"; 
    }
    else if ((Text == "s") || (Text == "S") || (Text == "Reverse")|| (Text == "reverse"))
    {
     Serial.println("\t\t\t\t       Reverse") ;
     Reverse();
     Text="0";
    }
    else if ((Text == "a") || (Text == "A") || (Text == "Left")|| (Text == "left"))
    {
     Serial.println("\t\t\t\t       Left") ;
     Left();
     Text="0";
    }
    else if ((Text == "d") || (Text == "D") || (Text == "Right")|| (Text == "right"))
    {
     Serial.println("\t\t\t\t       Right");
     Right(); 
     Text="0";
    }
    else if ((Text == "q") || (Text == "Q") || (Text == "Stop")|| (Text == "stop"))
    {
     Serial.println("\t\t\t\t       Stop");
     Stop(); 
     Text="0";
    }
    else if ((Text == "automatic") || (Text == "Automatic"))
    {
     Serial.println("\n\n\n\n\t\t\t Auto MODE   :");
     Auto();     
     Text = "0";
    }
 }
 }
 

void Auto()
{
  left_turn();  
}

void left_turn()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH); 
  distance = duration * 0.034 / 2; 
  
  if(distance <= 20 )
   {    
    Stop();
    delay(1000);
    digitalWrite(mopping, LOW);
    delay(800);
    digitalWrite(mopping, HIGH);
    delay(200);
    Left();
    delay(a);
    Forward();
    
    delay(150);
    
    Stop();
    delay(1000);
    Left();
    delay(a);
    right_turn();
   }
   else
   {
      
      Forward();      
      delay(100); 
      left_turn();     
   }
}

void right_turn()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH); 
  distance = duration * 0.034 / 2; 
  
  if(distance <= 20 )
   {    
    Stop();
    delay(1000);
    digitalWrite(mopping, LOW);
    delay(800);
    digitalWrite(mopping, HIGH);
    delay(200);
    Right();
    delay(a);
    
    Forward();
    delay(150);
    
    Stop();
    delay(1000);
    Right();
    delay(a);
    left_turn();
   }
   else
   {
      
      Forward();
      delay(100); 
      right_turn();     
   }
}
void Left(void)
{
  digitalWrite(RightMotorIn1,HIGH);
  digitalWrite(RightMotorIn2,LOW);
  digitalWrite(LeftMotorIn1,LOW);
  digitalWrite(LeftMotorIn2,HIGH); 
  delay((a+40));
  Stop();
}

void Right(void)
{
  digitalWrite(RightMotorIn1,LOW);
  digitalWrite(RightMotorIn2,HIGH);
  digitalWrite(LeftMotorIn1,HIGH);
  digitalWrite(LeftMotorIn2,LOW); 
  delay((a+95));
  Stop();
}

void Stop(void)
{
  digitalWrite(RightMotorIn1,LOW);
  digitalWrite(RightMotorIn2,LOW);
  digitalWrite(LeftMotorIn1,LOW);
  digitalWrite(LeftMotorIn2,LOW);
  digitalWrite(mopping, LOW);
}

void Reverse(void)
{
  digitalWrite(RightMotorIn1,HIGH);
  digitalWrite(RightMotorIn2,LOW);
  digitalWrite(LeftMotorIn1,HIGH);
  digitalWrite(LeftMotorIn2,LOW); 
  delay(a);
  Stop();
}

void Forward(void)
{
  digitalWrite(RightMotorIn1,LOW);
  digitalWrite(RightMotorIn2,HIGH);
  digitalWrite(LeftMotorIn1,LOW);
  digitalWrite(LeftMotorIn2,HIGH);
  delay(a);
  Stop();
  
}
