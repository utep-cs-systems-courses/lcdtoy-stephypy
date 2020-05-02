#include <msp430.h>
#include "switches.h"
#include "song.h"

int state = 0;
char sw1_state_down, sw2_state_down, sw3_state_down, sw4_state_down;

static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE = SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();

  // Determine which button is pressed down
   sw1_state_down = (p2val & SW1) ? 0 : 1; /* 0 when SW1 is up */
   sw2_state_down = (p2val & SW2) ? 0 : 1; /* 0 when SW2 is up */
   sw3_state_down = (p2val & SW3) ? 0 : 1; /* 0 when SW3 is up */
   sw4_state_down = (p2val & SW4) ? 0 : 1; /* 0 when SW4 is up */

   // Determine the state for the state machine
   // STATE 1
   if(sw1_state_down) {          /* SW1 = Play Song */
     state = 1;                  // Define state number
     curr_verse = 0;             // Restart values to begin
   }

   // STATE 2
   if(sw2_state_down) {          /* SW2 = Cat Two */
     state = 2;                  // Define state number
   }

   // STATE 3
   if(sw3_state_down) {          /* SW3 = Cat Three */
     state = 3;                  // Define state number
   }

   /// STATE 4
   if(sw4_state_down) {          /* SW4 = Cat Four */
     state = 4;                  // Define state number
   }
}
