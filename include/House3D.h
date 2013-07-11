#ifndef HOUSE3D_H
#define HOUSE3D_H

#include "Color.h"

class House3D{
      private:
            Color white;
            Color brickYellow;
            Color brightRed;
            Color brightYellow;
            Color black;
            Color darkGreen;
            Color brightYellowishGreen;
            Color reddishBrown;
            
            
      public:
             House3D();                   
             void drawCreateHouse();
             
             void drawBasePlate(GLint width, GLint length, Color color);
             void drawPlate(GLint width, GLint length, Color color);
             void drawCube(GLdouble width, GLdouble length, GLdouble height, Color color);
      
};
#endif
