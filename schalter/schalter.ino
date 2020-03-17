int buttonstate = 0;
int ledstate= 0;
boolean dazwischenlosgelassen=true;
void setup() {
  pinMode(9,OUTPUT);
  pinMode(2,INPUT);
  pinMode(LED_BUILTIN,OUTPUT);
}
void loop() {
  buttonstate=digitalRead(2);
  if (buttonstate==1){
    digitalWrite(LED_BUILTIN,HIGH);
  }
  else{
    digitalWrite(LED_BUILTIN,LOW);  
  }
  if(buttonstate==0){
    dazwischenlosgelassen=true;
    }
  if(buttonstate==1){
    if(dazwischenlosgelassen==true){
      if (ledstate==0){
        ledstate=1;
        digitalWrite(9,HIGH);
      }  
      else{
        ledstate=0;
        digitalWrite(9,LOW);
      }
      dazwischenlosgelassen=false;
    }
  }
  delay(5);
}
