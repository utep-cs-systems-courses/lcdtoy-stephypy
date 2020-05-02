#include "lcdutils.h"
#include "lcddraw.h"
#include "stateMachines.h"

/* State 2 Cat */
/* Displays a cross eyed brown cat */
void cat_two() {
  catState2 = 1;
  
  clearScreen(COLOR_SIENNA);

  drawString5x7(20,40, "MEOW meowww", COLOR_GOLD, COLOR_SIENNA);

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
  catState3 = 1;
  
  clearScreen(COLOR_HOT_PINK);

  drawString5x7(20,40, "intense meoww", COLOR_FIREBRICK, COLOR_HOT_PINK);

  // Body cat
  fillRectangle(15, 70, 60, 60, COLOR_BLACK);

  // Left eye
  fillRectangle(10, 80, 20, 15, COLOR_GOLD);

  // Right eye
  fillRectangle(60, 75, 20, 15, COLOR_GOLD);

  // Nose
  fillRectangle(40, 90, 10, 10, COLOR_HOT_PINK);

  // Left cat ear
  drawIsoTriangle(14, 48, 22, 22, COLOR_BLACK);

  // Right cat ear
  drawIsoTriangle(54, 48, 22, 22, COLOR_BLACK);

  // Mouth
  drawDownTriangle(25, 110, 20, COLOR_RED);

}

/* State 4 Cat */
void cat_four() {
  catState4 = 1;

  clearScreen(COLOR_DARK_OLIVE_GREEN);

  drawString5x7(20,10, "M E O W m e o w", COLOR_SKY_BLUE, COLOR_DARK_OLIVE_GREEN);

  
  fillRectangle(80, 90, 60, 150, COLOR_KHAKI);
}
