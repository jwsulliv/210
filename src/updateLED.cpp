#include "Arduino.h"
#include "globals.h"
#include "methods.h"

/*
Updates LED states. 
INPUTS: ledState from oscillator poll
RETURNS: void
ledState = 0, all LEDs off
ledState = 1, visible light LED on
ledState = 2, near IR LED on
*/

void updateLED(int ledState){
    switch(ledState){
        case 0: 
            digitalWrite(15, LOW);
            digitalWrite(16, LOW);
        break;
        case 1:
            digitalWrite(15, HIGH);
            digitalWrite(16, LOW);
        break;
        case 2:
            digitalWrite(15, LOW);
            digitalWrite(16, HIGH);
        break;
    }
}