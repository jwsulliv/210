#include "Arduino.h"
#include "globals.h"
#include "methods.h"

int samples;
int cycle;
int readings; 
int NIR [250];
int RED [250];
float SaO2_array [250];

void setup()
{
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(15,OUTPUT); //IR
  pinMode(16,OUTPUT); //VL
  pinMode(A0, INPUT_PULLUP); //PD In
  pinMode(23,INPUT_PULLUP);
  Serial.begin(9600);
  delay(500);
}

void loop()
{
  int ledState = sampleTimer();
  updateLED(ledState);
  readPhoto(ledState); //updates globals. Why global vars? ItS aN eMbEdDeD sYsTeM or something..
  getSaturation();
  float SaO2 = averageSaO2();
  
  Serial.println("--BEGIN NEW READING--");
  Serial.println("SaO2 (%):");
  Serial.println(SaO2*100);
}
