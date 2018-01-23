/*
 * Objective: Sumo 2 code
 * Tommy Ma, Lauryn Rodney, Joyce Song
 * Last Update: 11/28/2017
 */


//Rotation group
#define L_forward 180
#define R_forward 0
#define L_reverse 0
#define R_reverse 180

//Variable group
#include <Servo.h>
Servo R_mot;
Servo L_mot;
const int R_mot_pin = 4;
const int L_mot_pin = 3;
const int R_sen_pin = 11;
const int L_sen_pin = 12;
const int L_inf_pin = 0;
const int R_inf_pin = 2;

float VolR;
float VolL;

int L_sen_state=0;
int R_sen_state=0;

int i;
int n;
int j;
int k;

int v = 0;
int b = 0;
//Function group
void forward();
void reverse();
void R_turn();
void L_turn();
void hold();
void basic();
void check();
void adjustR();
void adjustL();
void TEST();

void setup() {
    pinMode(R_sen_pin, INPUT);
    pinMode(L_sen_pin, INPUT);
    R_mot.attach(R_mot_pin);
    L_mot.attach(L_mot_pin);
    Serial.begin(9600);

}

void loop() {
  R_sen_state = digitalRead(R_sen_pin);
  L_sen_state = digitalRead(L_sen_pin);
 
  if (R_sen_state == HIGH)
  {
    reverse();
    delay (300);  // TEST
    L_turn();
    forward();
    delay (1000); //TEST
  }
 
  else if (L_sen_state == HIGH)
  {
    reverse();
    delay (300);  // TEST
    R_turn();
    forward();
    delay (1000); //TEST
  }
  else 
  {
    basic();
  }

}

void forward()
{
  R_mot.write(R_forward);
  L_mot.write(L_forward);
}

void reverse()
{
  R_mot.write(R_reverse);
  L_mot.write(L_reverse);
}

void R_turn()
{
  R_mot.write(R_reverse);
  L_mot.write(L_forward);
}

void L_turn()
{
  R_mot.write(R_forward);
  L_mot.write(L_reverse);
}

void hold()
{
  R_mot.write(90);
  L_mot.write(90);
}

void basic()
{

  for (i = 0; i<8000; i++)
  {
  forward();
  delay(1);
  check();
  adjustR();
  adjustL();
  }

/*    for (j = 0; j<500; j++)
  {
  R_mot.write(90);
  L_mot.write(90);
  delay(1);
  check();
  }

   for (n = 0; n<8000; n++)
  {
  R_mot.write(180);
  L_mot.write(180);
  delay(1);
  check();
  }

    for (k = 0; k<500; k++)
  {
  R_mot.write(90);
  L_mot.write(90);
  delay(1);
  check();
  }
  */
}

void check()
{
  R_sen_state = digitalRead(R_sen_pin);
  L_sen_state = digitalRead(L_sen_pin);
   if (R_sen_state == HIGH)
  {
    reverse();
    delay (250);  // TEST
    L_turn();
    delay (500);
    R_turn ();
    delay (500);
    reverse();
    delay (250);
    L_turn();
    delay (500);
    R_turn ();
    delay (500);
    reverse();
    delay (250);
    L_turn();
    delay (500);
    R_turn ();
    delay (500);
    L_turn();
    delay (1400);
    forward();
    delay (1000); //TEST
  }
 
  else if (L_sen_state == HIGH)
  {
    reverse();
    delay (250);  // TEST
    L_turn();
    delay (500);
    R_turn ();
    delay (500);
    reverse();
    delay (250);
    L_turn();
    delay (500);
    R_turn ();
    delay (500);
    reverse();
    delay (250);
    L_turn();
    delay (500);
    R_turn ();
    delay (500);
    R_turn();
    delay (1400);
    forward();
    delay (1000); //TEST
  }
}

void adjustR()
{
    VolR = getVol(R_inf_pin);
    if (VolR >= 0.96)
    {
      R_turn();
      delay (1000);
    }
}

void adjustL()
{
  VolL = getVol(L_inf_pin);
  if (VolL >= 1.07)
  {
    L_turn();
    delay(1000);
  }
}

void TEST()
{
  R_mot.write(0);
  L_mot.write(0);
  delay(1000);
  R_mot.write(90);
  L_mot.write(90);
  delay(30000);

 }
 
 float getVol(int pin) {
  return (analogRead(pin) * 0.004882814);  
} 

