Project 3: LCD Toy (aka kitty cat) <br>
Author: Stephanie Galvan
====================
# Description:

Implemented on a MSP430, the LCD toy creates sound and renders graphical
elements on the screen with the use of a state machine. There are a total of four states that will
accomplish the task with the addition of a default state that will serve as a welcome. 

# How To Compile & Run It

1. Download the folder 'lab3-project' from this repository
2. Access the 'timerLib' folder
3. Run 'make install'
4. Access the 'src' folder
5. Plug in the msp430 to your machine and make sure it's connected
6. Run 'make load'
7. Press any button to begin

To clean, you can access the 'src' folder and run 'make clean'

# How To Use It

- When the msp430 is first connected and run, it will play a short series of sounds as a welcome message.
- S1 Button will play a fragment of the song "fallen down" from Undertale
- S2 Button will display a cross eyed brown cat
- S3 Button will display a black cat sticking out its tongue
- S4 Button will display a long cat

# About the Files

### main

**catMain.c** <br>

The program begins here. Inside the file, the methods called allow the set up
for the graphic display, the speaker (buzzer), and the buttons
(switches). Interrupts will be used. It will first display a blank screen of
color firebrick with a silly greeting. 

### buzzer

**buzzer.h** <br>
**buzzer.c** <br>

These files contain information about the speaker. It allows the use of them
in order to create sound. The sound itself is created inside the song files
explained below.

### switches

**switches.h** <br>
**switches.c** <br>

Inside these files the switches from the expansion board of the msp430 are
used. A variable called 'state' is used to indicate what state the program
should run. Each switch (button) represents a different state:

- SW1 is state 1
- SW2 is state 2
- SW3 is state 3
- SW4 is state 4

Variable 'state' is initially defined as 0 in order to play a short
tone. State 0 or any number not within the range of 1-4 is considered the
default state. The default state will play the series of notes as a welcome
message at the beggining and as a warning message at any other point. This
allows for debugging in the case of some faulty state transitions (at the
moment states only transition from 1-2-3-4, but this is to make the program robust). 

### state machines

**stateMachines.h** <br>
**stateMachines.c** <br>

This project contains a total of 4 states each represented by a switch plus a
default state. Each state has a different function described below.

- State 1: It calls a method that plays a fragment of the song "Fallen Down"
from Undertale. The method [ play_fallen_down() ] is found in the song.c file

- State 2: It calls a method that displays a brown cross-eyed cat. The method
[ cat_two() ] is found in the cat.c file.

- State 3: It calls a method that displays a black cat sticking out its tongue. The method
[ cat_three() ] is found in the cat.c file.

- State 4: It calls a method that displays a long cat with whiskers. The method
[ cat_four() ] is found in the cat.c file.

### song

**song.h** <br>
**song.c** <br>

These files contain the notes for the song and functions that allow the music
to be played. The order of the notes are saved in an array and the machine is
able to play each note successfully. The function buzzer_set_period(#) allows
a sound to be made in which # represents a note (defined as a number).

### cat

**cat.h** <br>
**cat.c** <br>

These files contains the method to draw the three different cats described in
the state machines. Each cat is drawn by using the methods from font-5x7.c, lcdutils.c and
lcddraw.c

### draw

**lcdutils.h** <br>
**lcdutils.c** <br>
**lcddraw.h** <br>
**lcddraw.c** <br>
**font-5x7.c** <br>

lcddraw contains the fill rectangle, draw iso triangle, and draw down triangle
method which are used to create the cats.

### p2 interrupt handler

**p2_interrupt_handler.c** <br>

A simple file that checks whether a switch caused an interrupt. If so, it
would continue the program.

### wd interrupt handler

**wdInterruptHandlder.c** <br>

An interrupt happens every 68 blink count per second because 68 will represent
an eight note for the song.
