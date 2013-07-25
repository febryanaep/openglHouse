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
            Color darkBlue;
            
      public:
             House3D();                   
             void drawCreateHouse(GLfloat draw);
             
             void draw1();
             void draw2();             
             void draw3();
             void draw4();
             void draw5();
             void draw6();
             void draw7();
		     void draw8();
		     void draw9();
		     void draw10();
		     void draw11();
		     void draw12();
		     void draw13();
		     void draw14();
		     void draw15();
    		 void draw16();
    		 void draw17();
    		 void draw18();
    		 void draw19();
    		 void draw20();
    		 void draw21();
    		 void draw22();
    		 void draw23();
    		 void draw24();
    		 void draw25();
    		 void draw26();
    		 void draw27();
    		 void draw28();
    		 void draw29();
    		 void draw30();
    		 void draw31();
    		 void draw32();
    		 void draw33();
    		 void draw34();
    		 void draw35();
    		 void draw36();
    		 void draw37();
    		 void draw38();
    		 void draw39();
    		 void draw40();
             void draw41();             
             
             
             void drawBasePlate(GLint width, GLint length, Color color);
             void drawPlate(GLint width, GLint length, Color color);
             void drawPlate2(GLint width, GLint length, Color color);
             void drawLine(GLdouble width, GLdouble length, Color color);
             void drawBrick(GLint width, GLint length, Color color);
             void drawCube(GLdouble width, GLdouble length, GLdouble height, Color color);
             void drawCube2(GLdouble width, GLdouble length, GLdouble height, Color color);
             void drawRound(GLdouble height, GLdouble radius);
             void drawFence(GLint angle);
             void drawRadiatorGrile(GLdouble angle, Color color);
             void drawRoundPlate(Color color);
             void drawRoundPlate2(Color color);
             void drawAngularPlate(GLdouble angle, Color color);
             void drawFlatTile(GLint width, GLint length, Color color);
             void drawWindow(GLint angle);
             void drawDoor(GLint angle);
             void drawDoorGarage(GLint angle);
             void drawRoofTileInverted(GLint width, GLdouble angle, Color color);
             void drawRoofTile(GLint width, GLdouble angle, Color color);
             void drawPlateWithSlide(GLint angle, GLint length, Color color);
             void drawWallCorner(GLint angle, Color color);
             void drawAnglePlate(GLint, Color color);
             void drawRidgedTile(GLint width, GLint angle, Color color);
             void drawEndRidgedTile(GLint angle, Color color);
             void drawMailBox(GLint angle);
             void cloud();
             void sun();
};               
#endif
