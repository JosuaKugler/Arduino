#include "LedControlMS.h"
#define NBR_MTX 1
//Drei anschlusspins 12:DIN,10:CLK,11:CS außerdem ground & 5v anschließen
LedControl matrix=LedControl(12,10,11,NBR_MTX);
void setup() {
  // put your setup code here, to run once:
  matrix.shutdown(0,false);
  matrix.setIntensity(0,8);
  matrix.clearDisplay(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  matrix.setLed(0,1,1,true);
}
