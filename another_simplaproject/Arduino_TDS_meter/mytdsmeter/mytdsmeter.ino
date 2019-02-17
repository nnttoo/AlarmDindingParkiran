void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A0,INPUT);
}


bool b;
int analogresult;
void loop() {
   b ^= true;
  digitalWrite(13,b);
  digitalWrite(A1,HIGH);


  analogresult = analogRead(A0);
  
  Serial.println(analogresult); 
  digitalWrite(A1,LOW);

  delay(200);
}
