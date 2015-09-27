#include "cubeplex.h"

/******************************* RANDOM RAINBOW *******************************\
| Our very first program together. Presenting Random rainbow, a cube that is   |
| both beautiful and exciting and really really really really fun ;)           |
\******************************************************************************/

void randomRainbow(){
  continuePattern = true; 
  int animationSpeed = 80; 
  int color = red;
  int xpos, ypos, zpos;
  while (continuePattern) {
    for (int i = 0; i < 4; i++) {
      xpos = random(0,4);
      ypos = random(0,4);
      zpos = random(0,4);
      color = nextColor(color);
      drawLed(color,xpos,ypos,zpos);
    }
     
    flushBuffer();
    clearBuffer();
    delay(animationSpeed);
    color = nextColor(color);
  }
}

/********************************* RAIN DROPS *********************************\
| Programo numero dos, this beauty simulates the Amazon rainforsest, the       |
| monsoons of India, and the falls of Niagra. Not California.
\******************************************************************************/

void rainDrops(){
  continuePattern = true;
  int animationSpeed = 100;
  int color = blue;
  int xpos, ypos, zpos;
  while (continuePattern) {
    xpos = random(0,4);
    ypos = random(0,4);
    for (int i = 3; i >= 0; i--) {
      zpos = i;
      drawLed(xpos, ypos, zpos);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    color = nextColor(color);
    delay(random(300, 800))
  }
}