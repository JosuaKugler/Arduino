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

void int2str(int x){
  switch(x){
    case 33:
      matrix.print("!");
    case 35:
      matrix.print("#");
    case 36:
      matrix.print("$");
    case 37:
      matrix.print("%");
    case 38:
      matrix.print("&");
    case 40:
      matrix.print("(");
    case 41:
      matrix.print(")");
    case 42:
      matrix.print("*");
    case 43:
      matrix.print("+");
    case 44:
      matrix.print(",");
    case 45:
      matrix.print("_");
    case 46:
      matrix.print(".");
    case 47:
      matrix.print("/");
    case 48:
      matrix.print("0");
    case 49:
      matrix.print("1");
    case 50:
      matrix.print("2");
    case 51:
      matrix.print("3");
    case 52:
      matrix.print("4");
    case 53:
      matrix.print("5");
    case 54:
      matrix.print("6");
    case 55:
      matrix.print("7");
    case 56:
      matrix.print("8");
    case 57:
      matrix.print("9");
    case 58:
      matrix.print(":");
    case 59:
      matrix.print(";");
    case 60:
      matrix.print("<");
    case 61:
      matrix.print("=");
    case 62:
      matrix.print(">");
    case 63:
      matrix.print("?");
    case 64:
      matrix.print("@");
    case 65:
      matrix.print("A");
    case 66:
      matrix.print("B");
    case 67:
      matrix.print("C");
    case 68:
      matrix.print("D");
    case 69:
      matrix.print("E");
    case 70:
      matrix.print("F");
    case 71:
      matrix.print("G");
    case 72:
      matrix.print("H");
    case 73:
      matrix.print("I");
    case 74:
      matrix.print("J");
    case 75:
      matrix.print("K");
    case 76:
      matrix.print("L");
    case 77:
      matrix.print("M");
    case 78:
      matrix.print("N");
    case 79:
      matrix.print("O");
    case 80:
      matrix.print("P");
    case 81:
      matrix.print("Q");
    case 82:
      matrix.print("R");
    case 83:
      matrix.print("S");
    case 84:
      matrix.print("T");
    case 85:
      matrix.print("U");
    case 86:
      matrix.print("V");
    case 87:
      matrix.print("W");
    case 88:
      matrix.print("X");
    case 89:
      matrix.print("Y");
    case 90:
      matrix.print("Z");
    case 91:
      matrix.print("[");
    case 93:
      matrix.print("]");
    case 94:
      matrix.print("^");
    case 95:
      matrix.print("_");
    case 96:
      matrix.print("`");
    case 97:
      matrix.print("a");
    case 98:
      matrix.print("b");
    case 99:
      matrix.print("c");
    case 100:
      matrix.print("d");
    case 101:
      matrix.print("e");
    case 102:
      matrix.print("f");
    case 103:
      matrix.print("g");
    case 104:
      matrix.print("h");
    case 105:
      matrix.print("i");
    case 106:
      matrix.print("j");
    case 107:
      matrix.print("k");
    case 108:
      matrix.print("l");
    case 109:
      matrix.print("m");
    case 110:
      matrix.print("n");
    case 111:
      matrix.print("o");
    case 112:
      matrix.print("p");
    case 113:
      matrix.print("q");
    case 114:
      matrix.print("r");
    case 115:
      matrix.print("s");
    case 116:
      matrix.print("t");
    case 117:
      matrix.print("u");
    case 118:
      matrix.print("v");
    case 119:
      matrix.print("w");
    case 120:
      matrix.print("x");
    case 121:
      matrix.print("y");
    case 122:
      matrix.print("z");
    case 123:
      matrix.print("{");
    case 124:
      matrix.print("|");
    case 125:
      matrix.print("}");
    case 126:
      matrix.print("~");
    
    
  }
}



boolean c=true;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN,OUTPUT);
  Serial.begin(9600);
  matrix.begin(0x70);
  
}

void loop() {
  //matrix.drawBitmap(0,0,smiley,8,8,LED_YELLOW);
  matrix.clear();
  matrix.writeDisplay();
  while(Serial.available()==0);
  int val = Serial.read();
  if(val==49){
    //int val = Serial.read();
    Serial.println(val);
    matrix.clear();
    matrix.setCursor(0,2);
    //matrix.print("!");
    matrix.drawBitmap(0,0,smiley,8,8,LED_YELLOW);
    //int2str(val);
    matrix.writeDisplay();
    delay(1000);
  }
}
