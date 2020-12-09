#include <algorithm>
#include <numeric>
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
const float epsilon_hb_NIR = 602.24;
const float epsilon_hb_RED = 3750.12;
const float epsilon_hbo2_NIR = 1204;
const float epsilon_hbo2_RED = 368;

void getSaturation(){
    float NIR_VDCVAC;
    float RED_VDCVAC;
    float NIR_VDC;
    float RED_VDC;
    float R;
    float SaO2;
    if(samples>249)
    {
        samples = 0;
        //Take readings and get relevant vars for processing
        NIR_VDCVAC = *std::max_element(NIR, NIR+(249));
        RED_VDCVAC = *std::max_element(RED, RED+(249));
        NIR_VDC = *std::min_element(NIR, NIR+(249));
        RED_VDC = *std::min_element(RED, RED+(249));
        

        //Processing now
        R = ((RED_VDCVAC-RED_VDC)/RED_VDC)/((NIR_VDCVAC-NIR_VDC)/NIR_VDC);
        SaO2 = (epsilon_hb_RED - epsilon_hb_NIR * R)/((epsilon_hb_RED - epsilon_hbo2_RED) - (epsilon_hb_NIR - epsilon_hbo2_NIR)*R);    
        SaO2_array[readings] = SaO2;
        readings++;
    }
}