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
            Color mediumGrey;
            Color darkGrey;
            
      public:
             House3D();                   
             void drawCreateHouse();
             
             void draw1();
             void draw2();
             void draw3();
             void draw4();
             void draw5();
             
             void drawBasePlate(GLint width, GLint length, Color color);
             void drawPlate(GLint width, GLint length, Color color);
             void drawLine(GLdouble width, GLdouble length, Color color);
             void drawBrick(GLint width, GLint length, Color color);
             void drawCube(GLdouble width, GLdouble length, GLdouble height, Color color);
             void drawCube2(GLdouble width, GLdouble length, GLdouble height, Color color);
             void drawRound(GLdouble height, GLdouble radius);
             void drawFence(GLint angle);
};
#endif
