/*
Useless Box Source Code.

Copyright Patrick Müller, 2017
Don`t copy, compile or share without permission of the copyright owner.
*/

#include <Servo.h>
#include <pitches.h>

#define Schalter 4
#define led 7
#define buzzer 10
#define MicroSchalter 3
#define PH 6
#define EN 5
#define LED_G 9
#define LED_Y 11
#define LED_R 12

Servo myservo;

const int S_On = 0;
const int S_Off = 1;

const int M_Up = 1;
const int M_Down = 0;
const int M_Speed = 150;
const int M_Speed_Servo = 100;
const int M_Speed_Slow = 50;

const int CaseNumber = 8;

int durchlauf=0;

long RandNumb;

int melody[] = {NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E4, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5};


void setup() {
  pinMode(led, OUTPUT);
  pinMode(PH, OUTPUT);
  
  pinMode(Schalter, INPUT);
  pinMode(MicroSchalter, INPUT);

  analogWrite(EN, 0);

  Serial.begin(9600);
  Serial.write("Useless Box Source Code. Copyright Patrick Müller, 2017. Don`t copy, compile or share without permission of the copyright owner.");

  myservo.attach(8);
  myservo.write(0);

  digitalWrite(LED_R, HIGH);
  delay(200);
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_Y, HIGH);
  delay(200);
  digitalWrite(LED_Y, LOW);
  digitalWrite(LED_G, HIGH);
  delay(200);
  digitalWrite(LED_G, LOW);
}


void SchalterUmlegen()
{
  digitalWrite(LED_R, HIGH);
  delay(500);
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_Y, HIGH);
  delay(500);
  digitalWrite(LED_Y, LOW);
  digitalWrite(LED_G, HIGH);
  digitalWrite(PH, M_Up);
  analogWrite(EN, M_Speed);
  while(digitalRead(Schalter)==S_On)
  {
    delay(50);
  }
  analogWrite(EN, 0);
  delay(50);
  
  digitalWrite(PH, M_Down);
  analogWrite(EN, M_Speed);
  while(digitalRead(MicroSchalter)==LOW)
  {
    delay(50);
  }
  analogWrite(EN, 0);
  delay(500);
  digitalWrite(LED_G, LOW);
}



void SchalterUmlegenServo()
{
  digitalWrite(PH, M_Up);
  analogWrite(EN, M_Speed_Servo);
  delay(140);
  analogWrite(EN, 0);

  for(int i=0; i<6; i++)
  {
    myservo.write(45);
    tone(buzzer, melody[7], 400);
    delay(500);
    myservo.write(135);
    tone(buzzer, melody[10], 400);
    delay(500);
  }
  myservo.write(0);
  delay(1000);

  analogWrite(EN, M_Speed);
  
  while(digitalRead(Schalter)==S_On)
  {
    delay(50);
  }
  analogWrite(EN, 0);
  delay(50);
  
  digitalWrite(PH, M_Down);
  analogWrite(EN, M_Speed);
  while(digitalRead(MicroSchalter)==LOW)
  {
    delay(50);
  }
  analogWrite(EN, 0);
}

void SchalterUmlegenServoSlow()
{
  digitalWrite(PH, M_Up);
  analogWrite(EN, M_Speed_Servo);
  digitalWrite(LED_Y, HIGH);
  delay(140);
  analogWrite(EN, 0);

  for(int i=0; i<30; i++)
  {
    myservo.write(i);
    delay(50);
  }
  digitalWrite(LED_Y, LOW);
  digitalWrite(LED_R, HIGH);
  delay(500);
  for(int y=0; y<7; y++)
  {
    tone(buzzer, melody[13], 200);
    delay(200);
    tone(buzzer, melody[10], 200);
    delay(200);
  }
  myservo.write(0);
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_Y, HIGH);
  delay(1000);
  digitalWrite(LED_Y, LOW);
  digitalWrite(LED_G, HIGH);

  analogWrite(EN, M_Speed);
  
  while(digitalRead(Schalter)==S_On)
  {
    delay(50);
  }
  analogWrite(EN, 0);
  delay(50);
  
  digitalWrite(PH, M_Down);
  analogWrite(EN, M_Speed);
  while(digitalRead(MicroSchalter)==LOW)
  {
    delay(50);
  }
  analogWrite(EN, 0);
  delay(500);
  digitalWrite(LED_G, LOW);
}

void SchalterUmlegenPause()
{
  digitalWrite(PH, M_Up);
  analogWrite(EN, M_Speed);
  delay(100);
  analogWrite(EN, 0);
  digitalWrite(LED_R, HIGH);
  delay(3000);
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_G, HIGH);
  analogWrite(EN,M_Speed);
  while(digitalRead(Schalter)==S_On)
  {
    delay(50);
  }
  analogWrite(EN, 0);
  delay(50);
  
  digitalWrite(PH, M_Down);
  analogWrite(EN, M_Speed);
  while(digitalRead(MicroSchalter)==LOW)
  {
    delay(50);
  }
  analogWrite(EN, 0);
  delay(500);
  digitalWrite(LED_G, LOW);
}

void SchalterUmlegenPauseBack()
{
  digitalWrite(PH, M_Up);
  analogWrite(EN, M_Speed);
  delay(100);
  analogWrite(EN, 0);
  digitalWrite(LED_R, HIGH);
  delay(3000);
  digitalWrite(PH, M_Down);
  analogWrite(EN, M_Speed);
  while(digitalRead(MicroSchalter)==LOW)
  {
    delay(50);
  }
  analogWrite(EN, 0);
  digitalWrite(LED_R, LOW);
  for(int i=0; i<5; i++)
  {
    digitalWrite(LED_Y, HIGH);
    delay(500);
    digitalWrite(LED_Y, LOW);
    delay(500);
  }
  digitalWrite(LED_G, HIGH);
  digitalWrite(PH, M_Up);
  analogWrite(EN,M_Speed);
  while(digitalRead(Schalter)==S_On)
  {
    delay(50);
  }
  analogWrite(EN, 0);
  delay(50);
  
  digitalWrite(PH, M_Down);
  analogWrite(EN, M_Speed);
  while(digitalRead(MicroSchalter)==LOW)
  {
    delay(50);
  }
  analogWrite(EN, 0);
  delay(500);
  digitalWrite(LED_G, LOW);
}

void SchalterUmlegenPauseBackSlow()
{
  digitalWrite(PH, M_Up);
  analogWrite(EN, M_Speed_Slow);
  digitalWrite(LED_Y, HIGH);
  delay(700);
  analogWrite(EN, 0);
  digitalWrite(LED_Y, LOW);
  digitalWrite(LED_R, HIGH);
  delay(500);
  digitalWrite(PH, M_Down);
  analogWrite(EN, M_Speed);
  while(digitalRead(MicroSchalter)==LOW)
  {
    delay(50);
  }
  analogWrite(EN, 0);
  digitalWrite(LED_R, LOW);
  for(int i=0; i<5; i++)
  {
    digitalWrite(LED_Y, HIGH);
    delay(500);
    digitalWrite(LED_Y, LOW);
    delay(500);
  }
  digitalWrite(LED_G, HIGH);
  digitalWrite(PH, M_Up);
  analogWrite(EN,M_Speed);
  while(digitalRead(Schalter)==S_On)
  {
    delay(50);
  }
  analogWrite(EN, 0);
  delay(50);
  
  digitalWrite(PH, M_Down);
  analogWrite(EN, M_Speed);
  while(digitalRead(MicroSchalter)==LOW)
  {
    delay(50);
  }
  analogWrite(EN, 0);
  delay(500);
  digitalWrite(LED_G, LOW);
}

void SchalterUmlegenPauseBackTrap()
{
  digitalWrite(PH, M_Up);
  analogWrite(EN, M_Speed);
  delay(100);
  analogWrite(EN, 0);
  digitalWrite(LED_R, HIGH);
  delay(3000);
  digitalWrite(PH, M_Down);
  analogWrite(EN, M_Speed);
  while(digitalRead(MicroSchalter)==LOW)
  {
    delay(50);
  }
  analogWrite(EN, 0);
  digitalWrite(LED_R, LOW);
  while(digitalRead(Schalter)==S_On)
  {
    digitalWrite(LED_Y, HIGH);
    digitalWrite(LED_R, LOW);
    delay(500);
    digitalWrite(LED_Y, LOW);
    digitalWrite(LED_R, HIGH);
    delay(500);
  }
  digitalWrite(LED_Y, LOW);
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_G, HIGH);
  digitalWrite(PH, M_Up);
  analogWrite(EN,M_Speed);
  delay(200);
  analogWrite(EN, 0);
  delay(50);
  
  digitalWrite(PH, M_Down);
  analogWrite(EN, M_Speed);
  while(digitalRead(MicroSchalter)==LOW)
  {
    delay(50);
  }
  analogWrite(EN, 0);
  delay(500);
  digitalWrite(LED_G, LOW);
}


void loop() 
{

  if(digitalRead(Schalter)==S_On)
  {
    switch(durchlauf)
    {
      case 0:
        RandNumb=millis();
        Serial.println(RandNumb);
        randomSeed(RandNumb);
        durchlauf=random(1, CaseNumber);
//        durchlauf++;
        delay(500);
        SchalterUmlegen();
        Serial.println("0");
        break;

      case 1:
        durchlauf=random(1, CaseNumber);
//        durchlauf++;
        delay(500);
        SchalterUmlegen();
        Serial.println("1");
        break;

      case 2:
        durchlauf=random(1, CaseNumber);
//        durchlauf++;
        delay(500);
        SchalterUmlegenPause();
        Serial.println("2");
        break;

      case 3:
        durchlauf=random(1, CaseNumber);
//        durchlauf++;
        delay(500);
        SchalterUmlegenPauseBack();
        Serial.println("3");
        break;

      case 4:
        durchlauf=random(1, CaseNumber);
//        durchlauf++;
        delay(500);
        SchalterUmlegenPauseBackSlow();
        Serial.println("4");
        break;

      case 5:
        durchlauf=random(1, CaseNumber);
//        durchlauf++;
        delay(500);
        SchalterUmlegenPauseBackTrap();
        Serial.println("5");
        break;

      case 6:
        durchlauf=random(1, CaseNumber);
//        durchlauf++;
        delay(500);
        SchalterUmlegenServo();
        Serial.println("6");
        break;

     case 7:
        durchlauf=random(1, CaseNumber);
//        durchlauf=0;
        delay(500);
        SchalterUmlegenServoSlow();
        Serial.println("7");
        break;
    }
  }
}
