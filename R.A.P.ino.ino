#include <DHT.h>

//Constants
#define DHTPIN 28     
#define DHTTYPE DHT11   

DHT dht(DHTPIN, DHTTYPE);
int chk;
float hum;  
float temp;
int led = 43;
const int buzzer = 4;
int pirPin = 53;
int pirValue;  
const int ledPin = 28; 
long durationS;
int distanceS;
long durationD;
int distanceD;
int info = 0;
long durationF;
int distanceF;
int E1 = 10;  
int M1 = 12; 
int E2 = 11;                      
int M2 = 13;                        
const int trigPinS = 34; //stanga
const int echoPinS = 35;
const int trigPinD = 32; //dreapta
const int echoPinD = 33;
const int trigPinF = 42; //fata
const int echoPinF = 40;
int FlamePinF = 49;
int FlameF = HIGH;

int FlamePinD = 50;
int FlameS = HIGH; 
int FlamePinS = 52; 
int FlameD = HIGH; 
int fan = 51;  
int state = 0;
int stopat = 0;
int spd = 80;

void setup() 
  {
	pinMode(FlamePinD, INPUT);
	pinMode(FlamePinS, INPUT);
	pinMode(FlamePinF, INPUT);
	pinMode(M1, OUTPUT);   
    pinMode(M2, OUTPUT);
    pinMode(led, OUTPUT); 
    pinMode(trigPinS, OUTPUT);
	pinMode(echoPinS, INPUT);
	pinMode(trigPinD, OUTPUT);
	pinMode(echoPinD, INPUT);
	pinMode(trigPinF, OUTPUT);
	pinMode(echoPinF, INPUT);
	pinMode(fan, OUTPUT);
	pinMode(pirPin, INPUT);
	pinMode(ledPin, OUTPUT); 
	pinMode(buzzer, OUTPUT);
	dht.begin();
} 

void loop() 
{ 
  senzori();
  int sensorValue = analogRead(A8); 
  float voltage = sensorValue * (5.00 / 1023.00) * 2;
  hum = dht.readHumidity();
  temp= dht.readTemperature();
  if(temp > 48.00)
	{
	suna();
	}
  digitalWrite(led, LOW);
  
  if( FlameD == LOW)
  {
    dreapta(120);
    delay(150);
    stoop();
    delay(300);
  }
  if(FlameS == LOW)
  {
    stanga(120);
    delay(150);
    stoop();
    delay(300);
  }
   if(FlameF == LOW && FlameS== LOW && distanceF > 10 )
  {
    stanga(120);
    delay(150);
     stoop();
    delay(300);
  }
  if(FlameF == LOW && FlameD == LOW && distanceF > 10 )
  {
    dreapta(120);
    delay(150);
    stoop();
    delay(300);
  }
if(FlameF == LOW && distanceF > 12 )
  {
    fata(110);
    delay(150);
    stoop();
    delay(300);
  }
  if(FlameF == LOW && distanceF < 12 )
  {
    stoop();
    analogWrite(fan,180);
    suna();      
    delay(2000); 
  
  }
  if(FlameF == LOW && distanceF < 7 )
  {
    spate(150);
  }
}
else 
 
{
 analogWrite(fan,0);

 if(distanceF < 5)
{ 
  stoop();
  delay(100);
  spate();
  delay(700);
  stoop();
  delay(200);
  if(distanceS>distanceD)
  {
    stanga(140);
    delay(520);
    stoop();
  }
  else
  {
    dreapta(140);
    delay(520);
    stoop();
  }  
} 
else if (distanceS < 14)
{
   dreapta(120); 
}
else if (distanceD < 14)
{
   stanga(120);
}  
else
{
  
  fata(spd);
  delay(30);
}
}   
}      
}

void fata(int vit)
{
  digitalWrite(M1,HIGH);   
    digitalWrite(M2, HIGH);       
    analogWrite(E1, vit);  
    analogWrite(E2, vit);
    
}
void spate(int vit)
{
  digitalWrite(M1,LOW);   
    digitalWrite(M2, LOW);       
    analogWrite(E1, vit);  
    analogWrite(E2, vit);
    delay(30);  
}
void stoop()
{
  digitalWrite(M1,LOW);   
    digitalWrite(M2, LOW);       
    analogWrite(E1, 0);  
    analogWrite(E2, 0);
    delay(30);  
}
void spate()
{
  digitalWrite(M1,LOW);   
    digitalWrite(M2, LOW);       
    analogWrite(E1, 100);  
    analogWrite(E2, 100);
    delay(30);  
}
void dreapta(int vit)
{
  digitalWrite(M1,LOW);   
    digitalWrite(M2, HIGH);       
    analogWrite(E1, 0);  
    analogWrite(E2, vit);
    
}
void stanga(int vit)
{
  digitalWrite(M1,HIGH);   
    digitalWrite(M2, LOW);       
    analogWrite(E1, vit);  
    analogWrite(E2, 0);
    
}

void senzori()
{
  pirValue = digitalRead(pirPin);
  FlameF = digitalRead(FlamePinF);
  pirValue = digitalRead(pirPin);
  FlameD = digitalRead(FlamePinD);
  FlameS = digitalRead(FlamePinS);
  digitalWrite(trigPinF, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinF, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinF, LOW);
  durationF = pulseIn(echoPinF, HIGH);
  distanceF= durationF*0.034/2;
  digitalWrite(trigPinS, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinS, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinS, LOW);
  durationS = pulseIn(echoPinS, HIGH);
  distanceS= durationS*0.034/2;
  digitalWrite(trigPinD, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinD, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinD, LOW);
  durationD = pulseIn(echoPinD, HIGH);
  distanceD= durationD*0.034/2;
}

void suna()
{
  tone(buzzer, 1500); 
  delay(50);      
  noTone(buzzer);    
  delay(50);  
  tone(buzzer, 1400); 
  delay(50);        
  noTone(buzzer);     
  delay(50);  
  tone(buzzer, 1500); 
  delay(50);       
  noTone(buzzer);     
  delay(50);  
  tone(buzzer, 1400); 
  delay(50);        
  noTone(buzzer);  
}

