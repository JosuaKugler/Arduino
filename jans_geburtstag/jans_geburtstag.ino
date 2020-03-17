#include "Wire.h"
#include "Adafruit_GFX.h"
#include "Adafruit_LEDBackpack.h"
Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();
static const uint8_t PROGMEM
  smiley[]=
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10100101,
    B10011001,
    B01000010,
    B00111100};

int buttonPin = 2;
int currentbuttonstate=0;
int lastbuttonstate=0;
int sw=0;


int buttonpressed( int lbs){
  int currentbuttonstate=digitalRead(buttonPin);
  if(currentbuttonstate==1){
    if(lbs==0) return 1;
    else return 0;
  }
  else return 0;
}

int buttontest(){
  int buttonstate=digitalRead(buttonPin);
  if(buttonstate==1){
    digitalWrite(LED_BUILTIN,HIGH);
    matrix.clear();
    matrix.writeDisplay();
    return 1;
  }
  else{
    digitalWrite(LED_BUILTIN,LOW);
    return 0;
  }
}
void textcolor(int x){
  switch (x){
    case 7:
      matrix.setTextColor(LED_GREEN);
      break;
    case -29:
      matrix.setTextColor(LED_YELLOW);
      break;
    
    case -85:
      matrix.setTextColor(LED_RED);
      break;
  }
}
void setup() {
  // put your setup code here, to run once:
  matrix.begin(0x70);
  matrix.clear();
  matrix.writeDisplay();
  pinMode(buttonPin,INPUT);
  pinMode(LED_BUILTIN,OUTPUT); 
  sw=0;
}

void loop() {
  lastbuttonstate=currentbuttonstate;
  currentbuttonstate=buttontest();
  if(buttonpressed(lastbuttonstate)==1){
    sw+=1;
  }
  if(sw==2){
    sw=0;
  }
  if(sw==1){
      for(int i=7;i>-115;i--){
        if(i<7) lastbuttonstate=currentbuttonstate;
        currentbuttonstate=buttontest();
        if(buttonpressed(lastbuttonstate)==1){
          sw+=1;
          }
        if(sw==2) sw=0;
        if(sw==0){
          matrix.clear();
          textcolor(i);
          matrix.setTextWrap(false);
          matrix.setCursor(i,0);
          matrix.print("Happy Birthday Jan!  ");
          matrix.writeDisplay();
          delay(100);
        }
        else{
          matrix.clear();
          matrix.writeDisplay();
          i=7;
          break;
          
        }
      }
      currentbuttonstate=buttontest();
      if(buttontest()==0){
        matrix.clear();
        matrix.drawBitmap(0,0,smiley,8,8,LED_RED);
        matrix.drawPixel(3,5,LED_YELLOW);
        matrix.drawPixel(4,5,LED_YELLOW);
        matrix.writeDisplay();
        while(buttontest()==0){
          delay(50);
          }
        matrix.clear();
        matrix.writeDisplay();
        delay(70);
      }
  }
 
}
