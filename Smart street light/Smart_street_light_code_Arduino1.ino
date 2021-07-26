const int trig1=13,trig2=12,trig3=3,trig4=2;
const int echo1=11,echo2=10,echo3=5,echo4=4;

long duration1,duration2,duration3,duration4;
float distance1,distance2,distance3,distance4;

const int A=6,B=7,C=8,D=9;
void setup()
{
  Serial.begin(9600);
  pinMode(trig1, OUTPUT);
  pinMode(trig2, OUTPUT);
  pinMode(trig3, OUTPUT);
  pinMode(trig4, OUTPUT);
 
  pinMode(echo1, INPUT);
  pinMode(echo2, INPUT);
  pinMode(echo3, INPUT);
  pinMode(echo4, INPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  
}

void loop()
{
  digitalWrite(trig1, LOW);
  delayMicroseconds(2); 
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trig1, LOW);
  duration1=pulseIn(echo1,HIGH);
  distance1=duration1*0.034/2;  
  
  digitalWrite(trig2, LOW);
  delayMicroseconds(2); 
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trig2, LOW);
  duration2=pulseIn(echo2,HIGH);
  distance2=duration2*0.034/2;
    
  digitalWrite(trig3, LOW);
  delayMicroseconds(2); 
  digitalWrite(trig3, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trig3, LOW);
  duration3=pulseIn(echo3,HIGH);
  distance3=duration3*0.034/2;  
  
  digitalWrite(trig4, LOW);
  delayMicroseconds(2); 
  digitalWrite(trig4, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trig4, LOW);
  duration4=pulseIn(echo4,HIGH);
  distance4=duration4*0.034/2;
  
  
  if ((distance1>100)&&(distance1<350))
    digitalWrite(A, HIGH);
  else
    digitalWrite(A, LOW);
  if ((distance2>100)&&(distance2<350))
    digitalWrite(B, HIGH);
  else
    digitalWrite(B, LOW);
  if ((distance3>100)&&(distance3<350))
    digitalWrite(C, HIGH);
  else
    digitalWrite(C, LOW);
  if ((distance4>100)&&(distance4<350))
    digitalWrite(D, HIGH);
  else
    digitalWrite(D, LOW);  
  
  
 }
