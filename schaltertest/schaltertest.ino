int buttonstate=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT);
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonstate=digitalRead(2);
  if(buttonstate==1){
    digitalWrite(LED_BUILTIN,HIGH);
  }
  else{
    digitalWrite(LED_BUILTIN,LOW);
  }
  delay(5);
}
