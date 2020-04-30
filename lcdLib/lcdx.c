#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"


/** Initializes everything, clears the screen, draws "hello" and a square */

int main() {

  configureClocks();
  lcd_init();

  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_SIENNA);

  drawString5x7(20,40, "meow meow", COLOR_HOT_PINK, COLOR_SIENNA);

  fillRectangle(3,3, 6, 6, COLOR_GOLD);

  // Body cat
  fillRectangle(35, 90, 60, 60, COLOR_BROWN);

  // Left eye
  fillRectangle(40, 100, 20, 10, COLOR_WHITE);

  // Left pupil
  fillRectangle(50, 100, 10, 10, COLOR_BLACK);
  
  // Right eye
  fillRectangle(70, 100, 20, 10, COLOR_WHITE);

  // Right pupil
  fillRectangle(70, 100, 10, 10, COLOR_BLACK);

  // Nose
  fillRectangle(60, 110, 10, 10, COLOR_HOT_PINK);

  // Left cat ear
  drawIsoTriangle(35, 68, 22, 22, COLOR_BLUE);

  // Right cat ear
  drawIsoTriangle(74, 68, 22, 22, COLOR_BLUE);

  // Mouth
  drawIsoTriangle(59, 120, 12, 12, COLOR_BLACK);

}
