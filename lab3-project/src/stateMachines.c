#include <msp430.h>
#include "stateMachines.h"
#include "song.h"
#include "switches.h"
#include "cat.h"
#include "lcdutils.h"

char catState2 = 0;
char catState3 = 0;
char catState4 = 0;

/* Advance between states */
void stateAdvance() {
  switch(state) {
  case 1:
    if(curr_verse == 0) {
      clearScreen(COLOR_SEA_BASS);
    }
    play_fallen_down(); // Found in song.c
    break;
    
  case 2:
    //Restart values for state 1
    curr_verse = 0;
    buzzer_set_period(0);

    // Restarting cat values
    catState3 = 0;
    catState4 = 0;
    
    if(catState2 == 0) {
     cat_two(); // Found in cat.c
    }
    break;
    
  case 3:
    //Restart values for state 1
    curr_verse = 0;
    buzzer_set_period(0);

    // Restarting cat values
    catState2 = 0;
    catState4 = 0;
    
    if(catState3 == 0) {
      cat_three(); // Found in cat.c
    }
    break;

  case 4:
    //Restart values for state 1
    curr_verse = 0;
    buzzer_set_period(0);

    // Restarting cat values
    catState2 = 0;
    catState3 = 0;
    
    if(catState4 == 0) {
      cat_four(); // Found in cat.c
    }
    break;

  default:
    welcome(); // Found in song.c
  }
}
