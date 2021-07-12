#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){
  static char blink_count = 0;
  char interruptTime = 250;                   // This is one second

  if(blink_count == interruptTime) {          // Change to zero to make brightest
    state_advance();                          // Turn on red
    blink_count=0;
    //state_advance_1();                      // Uncomment to make most dim
  }
  else if(blink_count <= interruptTime){
    state_advance_1();                        // Turn off red
    blink_count++;
  }
}
