#include "Arduino.h"
#include "globals.h"
#include "methods.h"

/*
Polls relaxation oscillator input and returns state of LEDs. 
Should really use hardware interrupts. But I got lazy.
INPUTS: none
RETURNS: int, ledState, range 0-2. 
ledState = 0, all LEDs off
ledState = 1, visible light LED on
ledState = 2, near IR LED on

Note: 
There are three variables being incremented throughout this code.
samples: number of samples made by the oscillator poll (and by the photodiode read). Multiple will happen in one cycle.
cycle: number of oscillator-based cycles. Increments each time we change ledState.
readings: number of actual readings, i.e. estimates of SaO2. 
*/

int sampleTimer(){
    int oscillator = digitalRead(23);
    int ledState = 0;
    if (cycle !=2){
        if(oscillator == HIGH){
            ledState = 1;
        }
        else if (oscillator == LOW){
            ledState = 2;
        }
    }
    else{
        ledState = 0;
    }
    cycle++;
    return ledState;
}