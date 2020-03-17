int buttonstate=0;
int ledstate= 0;
int rgb=0;
boolean dazwischenlosgelassen=true;

void setup() {
  pinMode(2,INPUT);
  pinMode(9,OUTPUT);//Rot
  pinMode(10,OUTPUT);//Grün
  pinMode(11,OUTPUT);//Blau
  pinMode(LED_BUILTIN,OUTPUT);
  
//  digitalWrite(9,HIGH);
//  delay(1000);
//  digitalWrite(9,LOW);
//  digitalWrite(10,HIGH);
//  delay(1000);
//  digitalWrite(10,LOW);
//  digitalWrite(11,HIGH);
//  delay(1000);
//  digitalWrite(11,LOW);
}

void loop() {
  buttonstate=digitalRead(2);
  //test
  if(buttonstate==1){
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
      rgb=rgb+1;
    }
  dazwischenlosgelassen=false;
  }
  if(rgb==4){
    rgb=0;
  }
  switch(rgb) {
    case 0: digitalWrite(9,LOW);
            digitalWrite(10,LOW);
            digitalWrite(11,LOW);
            break;
    case 1: digitalWrite(9,HIGH);
            digitalWrite(10,LOW);
            digitalWrite(11,LOW);
            break;
    case 2: digitalWrite(9,LOW);
            digitalWrite(10,HIGH);
            digitalWrite(11,LOW);
            break;
    case 3: digitalWrite(9,LOW);
            digitalWrite(10,LOW);
            digitalWrite(11,HIGH);
            break;
    case 4: digitalWrite(9,LOW);
            digitalWrite(10,HIGH);
            digitalWrite(11,HIGH);
            break;
    case 5: digitalWrite(9,HIGH);
            digitalWrite(10,LOW);
            digitalWrite(11,HIGH);
            break;
    case 6: digitalWrite(9,HIGH);
            digitalWrite(10,HIGH);
            digitalWrite(11,LOW);
            break;
    case 7: digitalWrite(9,HIGH);
            digitalWrite(10,HIGH);
            digitalWrite(11,HIGH);
            break;
    case 8: digitalWrite(9,HIGH);
            digitalWrite(10,HIGH);
            digitalWrite(11,HIGH);
    default: digitalWrite() 
  }
  
  

  
 
    
    
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
  }
  delay(5);
}
