#include <msp430.h>
#include "libTimer.h"
#include "switches.h"
#include "buzzer.h"
#include "lcdutils.h"

void main(void) 
{
  /* Voila my project bobeep!! */

  configureClocks();

  // Switch Setup
  switch_init();

  // Graphic Display Setup
  lcd_init();
  
  // Buzzer Setup
  buzzer_init(); 

  // Screen
  drawString5x7(60,40, "Hewwo :3", COLOR_NAVY, COLOR_FIREBRICK);
  clearScreen(COLOR_FIREBRICK);
  
  enableWDTInterrupts(); // handling interruptions

  or_sr(0x18);  // CPU off, GIE on
} 
