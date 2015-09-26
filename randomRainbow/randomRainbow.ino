#include "cubeplex.h"
 
void setup() {
  // initilize the cube display
  initCube();
   
  // how many secconds until continuePattern is set to false
  animationMax = 10;
}
void loop() {
  randomRainbow();
}
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
