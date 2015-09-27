/**************************************************************************************\
|                                                                                      |
|     ___      U  ___ u   U  ___ u _____   ___      U  ___ u   U  ___ u   ____    _    |
|    / " \      \/"_ \/    \/"_ \/|_ " _| / " \      \/"_ \/    \/"_ \/U | __")uU|"|u  |
|   | |"| |     | | | |    | | | |  | |  | |"| |     | | | |    | | | | \|  _ \/\| |/  |
|  /| |_| |\.-,_| |_| |.-,_| |_| | /| |\/| |_| |\.-,_| |_| |.-,_| |_| |  | |_) | |_|   |
|  U \__\_\u \_)-\___/  \_)-\___/ u |_|UU \__\_\u \_)-\___/  \_)-\___/   |____/  (_)   |
|     \\//        \\         \\   _// \\_  \\//        \\         \\    _|| \\_  |||_  | 
|    (_(__)      (__)       (__) (__) (__)(_(__)      (__)       (__)  (__) (__)(__)_) |
|                                                                                      |
\**************************************************************************************/

#include "cubeplex.h"
#include "rainbows.h"
#include "stock_animations.h"

int TYPE = 2;

void setup() {
  initCube();
  
}

void loop() {

  int type = TYPE;
  switch (type) {

    case 1:
      // how many secconds until the animation is told to progress
      animationMax = 10;

      planarSpin();
      fountian();
      trifade();
      shiftSquares();
      tunnel();
      chaseTheDot();
      planarFlop3D();
      raindrops();
      randomRainbow();
      break;

    case 2:
      animationMax = 20;
      
      raindrops();
      randomRainbow();
      break;
  }
}
