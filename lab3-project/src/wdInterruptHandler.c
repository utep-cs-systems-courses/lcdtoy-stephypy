#include <msp430.h>
#include "song.h"
#include "stateAdvance_assembly.h"

void
__interrupt_vec(WDT_VECTOR) WDT() {	/* 250 interrupts/sec */
  static char blink_count = 0;
  char beat = 68; // Represents the needed interrupts for an eighth note
  
  if(++blink_count == beat) {
    state_advance();
    blink_count = 0;
  }
}
