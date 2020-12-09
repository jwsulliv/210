#include "Arduino.h"
#include "globals.h"
#include "methods.h"


/*
Periodically calculates oxygen saturation.  
INPUTS: ledState from oscillator poll
ledState = 0, all LEDs off
ledState = 1, visible light LED on
ledState = 2, near IR LED on

RETURNS: void
UPDATES GLOBAL VARS
extern float SaO2_array [250];
extern int readings;

Note: 
There are three variables being incremented throughout this code.
samples: number of samples made by the oscillator poll (and by the photodiode read). Multiple will happen in one cycle.
cycle: number of oscillator-based cycles. Increments each time we change ledState.
readings: number of actual readings, i.e. estimates of SaO2. 
*/
float averageSaO2(){
    float SaO2 = 0;
    if(readings == 250){
     readings = 0;
     int sum = 0;
     for(int i = 0; i<250;i++){
       sum = sum+SaO2_array[i];
     }
     SaO2 = sum/250;
     Serial.println("--BEGIN NEW READING--");
     Serial.println("SaO2 (%):");
     Serial.println(SaO2*100);
    }
    return SaO2;
}
