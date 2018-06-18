//motor A digitalWrite:12 analogWrite:10
//motor B digitalWrite:13 analogWrite:11

void setup() {
  pinMode(12,OUTPUT);     //Channel A Direction Pin Initialize
  pinMode(13,OUTPUT);     //Channel B Direction Pin Initialize
}

void loop() {
  
 
  digitalWrite(12, LOW); //Channel A Direction Forward
  analogWrite(10, 255);    //Channel A Speed 100%

  digitalWrite(13, HIGH);  //Channel B Direction Reverse
  analogWrite(11, 255);    //Channel B Speed 100%
  
  
}

