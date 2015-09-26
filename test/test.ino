#include "cubeplex.h"
 
void setup() {
  // initilize the cube display
  initCube();
  // set the number of seconds each animation should run for
  animationMax = 10;
}
void loop() {
  LEDcycle();
}
void LEDcycle() {
  continuePattern = true;
  int animationSpeed = 10;
  drawLed(blue, 0, 0, 0);
  flushBuffer();
  clearBuffer();
  delay(animationSpeed);
}
