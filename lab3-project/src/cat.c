#include "lcdutils.h"
#include "lcddraw.h"

/* State 2 Cat */
/* Displays a cross eyed brown cat */
void cat_two() {
  clearScreen(COLOR_SIENNA);

  drawString5x7(20,40, "MEOW meowww", COLOR_GOLD, COLOR_SIENNA);
  int state = 0;

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
  drawIsoTriangle(35, 68, 22, 22, COLOR_BROWN);

  // Right cat ear
  drawIsoTriangle(74, 68, 22, 22, COLOR_BROWN);

  // Mouth
  drawIsoTriangle(59, 120, 12, 12, COLOR_BLACK);
}

/* State 3 Cat */
void cat_three() {
  clearScreen(COLOR_SIENNA);
  fillRectangle(60, 110, 10, 10, COLOR_HOT_PINK);
}

/* State 4 Cat */
void cat_four() {
  clearScreen(COLOR_SIENNA);
  fillRectangle(60, 110, 10, 10, COLOR_HOT_PINK);
}
