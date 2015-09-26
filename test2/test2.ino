#include "cubeplex.h"
 
int color = red;
  
void setup() {
  // initilize the cube display
  initCube();
  // set the number of seconds each animation should run for
  animationMax = 10;
}
void loop() {
  fountian();
}
void fountian() {
  continuePattern = true;
  int animationSpeed = 100;
  while (continuePattern) {
    for (int z = 0; z <= 3; z++) {
      drawBoxWalls(color,1,1,z,2,2,z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    for (int z = 3; z >= 0; z--) {
      drawBoxWalls(color,0,0,z,3,3,z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    color=nextColor(color);
  }
}
