#include "Arduino.h"
#include "globals.h"
#include "methods.h"

/*
Reads photodiode. 
INPUTS: ledState from oscillator poll
ledState = 0, all LEDs off
ledState = 1, visible light LED on
ledState = 2, near IR LED on

RETURNS: void
UPDATES GLOBAL VARS
extern int NIR [250];
extern int RED [250];
extern int samples;

Note: 
There are three variables being incremented throughout this code.
samples: number of samples made by the oscillator poll (and by the photodiode read). Multiple will happen in one cycle.
cycle: number of oscillator-based cycles. Increments each time we change ledState.
readings: number of actual readings, i.e. estimates of SaO2. 
*/

void readPhoto(int ledState){
    switch(ledState){
        case 0: 
        break;
        case 1:
        RED[cycle] = analogRead(A0);  
        break;
        case 2:
        NIR[cycle] = analogRead(A0);
        break;
    }
    samples++;
}