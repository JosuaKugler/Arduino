#include "Wire.h"
#include "Adafruit_GFX.h"
#include "Adafruit_LEDBackpack.h"
Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();
// Color definitions

#define BLACK    0x0000
#define BLUE     0x001F
#define RED      0xF800
#define GREEN    0x07E0
#define CYAN     0x07FF
#define MAGENTA  0xF81F
#define YELLOW   0xFFE0 
#define WHITE    0xFFFF

int buttonstate=0;
int ledstate= 0;
boolean matrixleucht=false;
boolean dazwischenlosgelassen=true;
void setRotation(uint8_t rotation);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");
  matrix.begin(0x70);  // pass in the address
  pinMode(2,INPUT);
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(13,OUTPUT);
  //matrix.setRotation(0);
  matrix.writeDisplay();
}

static const uint8_t PROGMEM
  smile_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10100101,
    B10011001,
    B01000010,
    B00111100 },
  neutral_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10111101,
    B10000001,
    B01000010,
    B00111100 },
  frown_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10011001,
    B10100101,
    B01000010,
    B00111100 },
  kerze[] =
  { B00011000,
    B00111100,
    B00000000,
    B00011000,
    B00011000,
    B00011000,
    B00011000,
    B00011000 };


void loop() {
  
  matrix.clear();
  matrix.writeDisplay();
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
      if (matrixleucht==false){
        matrixleucht=true;
      }
      else{
        matrixleucht=false;
      }
    }
    dazwischenlosgelassen=false;
    }
  
  
  if (matrixleucht==true){
    matrix.setTextWrap(false);
    matrix.setTextSize(1);
    matrix.setTextColor(LED_YELLOW);
    for(int8_t x=7; x>=-110; x--){
      buttonstate=digitalRead(2);
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
          if (matrixleucht==false){
            matrixleucht=true;
          }
          else{
            matrixleucht=false;
            }
          }
        dazwischenlosgelassen=false;
        }
      if (matrixleucht==true){
        matrix.clear();
        if(x==7){
          matrix.setTextColor(LED_GREEN);
        }
        else if(x==-29){
          matrix.setTextColor(LED_YELLOW);
        }
        else if(x==-83){
          matrix.setTextColor(LED_RED);
        }
        matrix.setCursor(x,0);
        matrix.print("Happy Birthday JAN!   ");
        matrix.writeDisplay();
        delay(100);
        }
      else{
        matrix.clear();
        matrix.writeDisplay();
        x=7;
        delay(10);
      }
    
    }
    matrix.clear();
    matrix.drawBitmap(0,0,smile_bmp, 8,8,LED_RED);
    matrix.drawPixel(3,5,LED_YELLOW);
    matrix.drawPixel(4,5,LED_YELLOW);
    matrix.writeDisplay();
    while(matrixleucht==true){
      delay(50);
    }
    matrix.clear();
}
}
