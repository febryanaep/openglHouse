#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

#include "../include/House3D.h"
#include "../include/Point.h"
#include "../include/Vector.h"

House3D::House3D() {
	this->white.setColor(242, 243, 242);
	this->brickYellow.setColor(215, 197, 153);
	this->brightRed.setColor(196, 40, 27);
	this->brightYellow.setColor(245, 205, 47);
	this->black.setColor(27, 42, 52);
	this->darkGreen.setColor(40, 127, 70);
	this->brightYellowishGreen.setColor(164, 189, 70);
	this->reddishBrown.setColor(105, 64, 39);
	this->mediumGrey.setColor(163, 162, 164);
	this->darkGrey.setColor(99, 95, 97);
	this->darkBlue.setColor(3, 15, 137);
	
}

void House3D::drawCreateHouse() {
     glPushMatrix();
     glTranslated(-16, 0, -16);
     drawBasePlate(32, 29, this->darkGreen);
     draw1();
     draw2();
     draw3();
	 draw4();
     draw5();
	 
     glPopMatrix();    
}

void House3D::draw1(){
     for(int x = 0; x < 25; x += 8) {
		glPushMatrix();
		glTranslated(x, 0, 29);
		drawPlate(8, 1, this->darkGrey);
		glPopMatrix();
	}
	for(int x = 0; x < 25; x += 8) {
		glPushMatrix();
		glTranslated(x, 0, 30);
		drawLine(8, 0.35, this->darkGrey);
		glPopMatrix();
	}  
	for(int x = 0; x < 32; x += 4) {
		glPushMatrix();
		glTranslated(x, 0, 30.35);
		drawLine(1, 0.3, this->white);
		glPopMatrix();
	}
    for(int x = 1; x < 32; x += 4) {
		glPushMatrix();
		glTranslated(x, 0, 30.35);
		drawLine(3, 0.3, this->darkGrey);
		glPopMatrix();
	}    
    for(int x = 0; x < 25; x += 8) {
		glPushMatrix();
		glTranslated(x, 0, 30.65);
		drawLine(8, 0.35, this->darkGrey);
		glPopMatrix();
	}  
    for(int x = 0; x < 25; x += 8) {
		glPushMatrix();
		glTranslated(x, 0, 31);
		drawPlate(8, 1, this->darkGrey);
		glPopMatrix();
	}
     
     for(int x = 0; x < 25; x += 8) {
		glPushMatrix();
		glTranslated(x, 0.4, 29);
		drawPlate(8, 1, this->darkGrey);
		glPopMatrix();
	}
	for(int x = 0; x < 25; x += 8) {
		glPushMatrix();
		glTranslated(x, 0.4, 30);
		drawLine(8, 0.35, this->darkGrey);
		glPopMatrix();
	}  
	for(int x = 0; x < 32; x += 4) {
		glPushMatrix();
		glTranslated(x, 0.4, 30.35);
		drawLine(1, 0.3, this->white);
		glPopMatrix();
	}
    for(int x = 1; x < 32; x += 4) {
		glPushMatrix();
		glTranslated(x, 0.4, 30.35);
		drawLine(3, 0.3, this->darkGrey);
		glPopMatrix();
	}    
    for(int x = 0; x < 25; x += 8) {
		glPushMatrix();
		glTranslated(x, 0.4, 30.65);
		drawLine(8, 0.35, this->darkGrey);
		glPopMatrix();
	}  
    for(int x = 0; x < 25; x += 8) {
		glPushMatrix();
		glTranslated(x, 0.4, 31);
		drawPlate(8, 1, this->darkGrey);
		glPopMatrix();
	}
    
    
		glPushMatrix();
		glTranslated(20, 0.4, 13);
		drawPlate(8, 16, this->darkGrey);
		glPopMatrix();
		
		glPushMatrix();
		glTranslated(3, 0.4, 3);
		drawPlate(12, 8, this->darkBlue);
		glPopMatrix();
		
		glPushMatrix();
		glTranslated(15, 0.4, 5);
		drawPlate(2, 6, this->darkBlue);
		glPopMatrix();
		
		glPushMatrix();
		glTranslated(17, 0.4, 5);
		drawPlate(10, 8, this->darkBlue);
		glPopMatrix();
	
}

void House3D::draw2(){
     
    glPushMatrix();
	glTranslated(10, 0.4, 27);
	drawPlate(10, 1, this->white);
	glPopMatrix();
     
     glPushMatrix();
	glTranslated(0, 0.4, 27);
	drawPlate(5, 1, this->white);
	glPopMatrix();

     glPushMatrix();
	glTranslated(0, 0.4, 1);
	drawPlate(30, 1, this->white);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0.4, 2);
	drawPlate(1, 25, this->white);
	glPopMatrix();

    glPushMatrix();
	glTranslated(29, 0.4, 2);
	drawPlate(1, 26, this->white);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(1, 0.8, 27);
	drawFence(0);
	glPopMatrix();

    glPushMatrix();
	glTranslated(11, 0.8, 27);
	drawFence(0);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(15, 0.8, 27);
	drawFence(0);
	glPopMatrix();

    glPushMatrix();
	glTranslated(0, 0.8, 2);
    drawFence(90);
	glPopMatrix();
	
    for(int x = 3; x < 24; x += 4) {
		glPushMatrix();
		glTranslated(0, 0.8, x);
        drawFence(90);
		glPopMatrix();
	} 
	
	for(int x = 1; x < 28; x += 4) {
		glPushMatrix();
		glTranslated(x, 0.8, 1);
	    drawFence(0);
		glPopMatrix();
	} 
	
    for(int x = 3; x < 24; x += 4) {
		glPushMatrix();
		glTranslated(29, 0.8, x);
        drawFence(90);
		glPopMatrix();
	}
    
	glPushMatrix();
	glTranslated(29, 0.8, 2);
    drawFence(90);
	glPopMatrix();
    
    glPushMatrix();
	glTranslated(0, 0.8, 27);
	drawBrick(1, 1, this->white);
	glPopMatrix();
	
    glPushMatrix();
	glTranslated(0, 2, 27);
	drawBrick(1, 1, this->white);
	glPopMatrix(); 
	
	glPushMatrix();
	glTranslated(0, 0.8, 1);
	drawBrick(1, 1, this->white);
	glPopMatrix();
	
    glPushMatrix();
	glTranslated(0, 2, 1);
	drawBrick(1, 1, this->white);
	glPopMatrix(); 
	
	glPushMatrix();
	glTranslated(29, 0.8, 1);
	drawBrick(1, 1, this->white);
	glPopMatrix();
	
    glPushMatrix();
	glTranslated(29, 2, 1);
	drawBrick(1, 1, this->white);
	glPopMatrix(); 
	
	glPushMatrix();
	glTranslated(29, 0.8, 27);
	drawBrick(1, 1, this->white);
	glPopMatrix();
	
    glPushMatrix();
	glTranslated(29, 2, 27);
	drawBrick(1, 1, this->white);
	glPopMatrix(); 
	
	glPushMatrix();
	glTranslated(10, 0.8, 27);
	drawBrick(1, 1, this->white);
	glPopMatrix();
	
    glPushMatrix();
	glTranslated(10, 2, 27);
	drawBrick(1, 1, this->white);
	glPopMatrix(); 
	
	glPushMatrix();
	glTranslated(19, 0.8, 27);
	drawBrick(1, 1, this->white);
	glPopMatrix();
	
    glPushMatrix();
	glTranslated(19, 2, 27);
	drawBrick(1, 1, this->white);
	glPopMatrix(); 
}

void House3D::draw3() {
	glPushMatrix();
	glTranslated(16, 0.4, 4);
	drawPlate2(8, 1, this->white);
	glPopMatrix();

	glPushMatrix();
	glTranslated(24, 0.4, 4);
	drawPlate2(4, 1, this->white);
	glPopMatrix();

	/*glPushMatrix();
	glTranslated(16, 0.4, 5);
	drawPlate2(1, 8, this->white);
	glPopMatrix();*/

	glPushMatrix();
	glTranslated(27, 0.4, 5);
	drawPlate2(1, 8, this->white);
	glPopMatrix();

	glPushMatrix();
	glTranslated(16, 0.4, 13);
	drawPlate2(7, 1, this->white);
	glPopMatrix();

    glPushMatrix();
	glTranslated(23, 0.4, 13);
	drawPlate2(4, 1, this->mediumGrey);
	glPopMatrix();

	glPushMatrix();
	glTranslated(27, 0.4, 13);
	drawPlate2(1, 1, this->white);
	glPopMatrix();
    
	glPushMatrix();
	glTranslated(5, 0.4, 26);
	drawPlate2(2, 2, this->white);
	glPopMatrix();

}

void House3D::draw4() {
    

	glPushMatrix();
	glTranslated(19, 0.4, 14);
	drawPlate2(1, 13, this->white);
	glPopMatrix();

	glPushMatrix();
	glTranslated(28, 0.4, 13);
	drawPlate2(1, 15, this->white);
	glPopMatrix();

	
	
    /*glPushMatrix();
	glTranslated(27, 0.4, 21);
	drawPlate(2, 6, this->reddishBrown);
		/*glPushMatrix();
		glTranslated(1, 0.4, 0);
		drawSolidRoundPlate(this->reddishBrown);
		glPopMatrix();

		glPushMatrix();
		glTranslated(1, 0.8, 0);
		drawSolidRoundPlate(this->reddishBrown);
		glPopMatrix();

		glPushMatrix();
		glTranslated(1, 0.4, 2);
		drawSolidRoundPlate(this->reddishBrown);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0, 0.4, 3);
		drawSolidRoundPlate(this->reddishBrown);
		glPopMatrix();

		glPushMatrix();
		glTranslated(1, 0.4, 4);
		drawSolidRoundPlate(this->reddishBrown);
		glPopMatrix();

		glPushMatrix();
		glTranslated(1, 0.4, 5);
		drawSolidRoundPlate(this->reddishBrown);
		glPopMatrix();

		glPushMatrix();
		glTranslated(1, 1, 0);
		drawSolidRoundPlate(this->darkGreen);
		glPopMatrix();

		glPushMatrix();
		glTranslated(1, 0.4, 1);
		drawSolidRoundPlate(this->darkGreen);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0, 0.4, 2);
		drawSolidRoundPlate(this->darkGreen);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0, 0.8, 3);
		drawSolidRoundPlate(this->darkGreen);
		glPopMatrix();

		glPushMatrix();
		glTranslated(1, 0.8, 5);
		drawSolidRoundPlate(this->darkGreen);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0, 0.4, 1);
		drawSolidRoundPlate(this->brightRed);
		glPopMatrix();

		glPushMatrix();
		glTranslated(1, 0.8, 4);
		drawSolidRoundPlate(this->brightRed);
		glPopMatrix();*/
	//glPopMatrix();
    glPushMatrix();
	glTranslated(15, 0.4, 13);
	drawPlate(1, 1, this->mediumGrey);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(15, 0.4, 14);
	drawRadiatorGrile(90, this->mediumGrey);
	glPopMatrix();
}

void House3D::draw5() {
     
	glPushMatrix();
	glTranslated(2, 0.4, 2);
	drawPlate2(4, 1, this->white);
	glPopMatrix();

	glPushMatrix();
	glTranslated(6, 0.4, 2);
	drawPlate2(10, 1, this->white);
	glPopMatrix();

    glPushMatrix();
	glTranslated(15, 0.4, 3);
	drawPlate2(1, 2, this->white);
	glPopMatrix();

	/*glPushMatrix();
	glTranslated(13, 0.4, 4);
	drawBrick(1, 8, this->white);
	glPopMatrix();*/

	glPushMatrix();
	glTranslated(2, 0.4, 3);
	drawPlate2(1, 8, this->white);
	glPopMatrix();

	glPushMatrix();
	glTranslated(2, 0.4, 11);
	drawPlate2(4, 1, this->white);
	glPopMatrix();

	glPushMatrix();
	glTranslated(6, 0.4, 11);
	drawPlate2(3, 1, this->white);
	glPopMatrix();

	glPushMatrix();
	glTranslated(9, 0.4, 11);
	drawPlate2(4, 1, this->mediumGrey);
	glPopMatrix();

	glPushMatrix();
	glTranslated(13, 0.4, 11);
	drawPlate2(3, 1, this->white);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(16, 0.4, 11);
	drawPlate2(1, 2, this->white);
	glPopMatrix();
	
}


void House3D::drawMailBox(GLint angle) {
	GLdouble pi = 3.14159265;
    GLdouble k  = pi / 15;

	GLdouble r = (GLdouble) brightYellow.getColorRed()   / 255;
	GLdouble g = (GLdouble) brightYellow.getColorGreen() / 255;
	GLdouble b = (GLdouble) brightYellow.getColorBlue()  / 255;

	Point  A, B, C, D;
	Vector P, Q, N;

	glColor3d(r, g, b);

	if(angle == 90) {
		glTranslated(0, 0, 2);
		glRotated(angle, 0, 1, 0);
	}

	glPushMatrix();
	glTranslated(1, 1, 0.5);
	drawRound(0.2, 0.3);
	glPopMatrix();

	glPushMatrix();
	glTranslated(1, 0, 0);
    for(GLdouble a = 0.0; a < pi; a += k) {
		

		A = Point(cos(a)  , sin(a)  , 0);
		B = Point(cos(a+k), sin(a+k), 0);
		C = Point(cos(a+k), sin(a+k), 2);
		D = Point(cos(a)  , sin(a)  , 2);

		P = Vector(A, B);
		Q = Vector(A, C);
		N = Vector().getNormal(P, Q);

		glNormal3d(N.getX(), N.getY(), N.getZ());

        glBegin(GL_POLYGON);
		glVertex3d(A.getX(), A.getY(), A.getZ());
        glVertex3d(B.getX(), B.getY(), B.getZ());
        glVertex3d(C.getX(), C.getY(), C.getZ());
        glVertex3d(D.getX(), D.getY(), D.getZ());
        glEnd();
        
		

		A = Point(0       , 0       , 0);
		B = Point(cos(a+k), sin(a+k), 0);
		C = Point(cos(a)  , sin(a)  , 0);

		P = Vector(A, B);
		Q = Vector(A, C);
		N = Vector().getNormal(P, Q);

		glNormal3d(N.getX(), N.getY(), N.getZ());

        glBegin(GL_POLYGON);
        glVertex3d(A.getX(), A.getY(), A.getZ());
        glVertex3d(B.getX(), B.getY(), B.getZ());
        glVertex3d(C.getX(), C.getY(), C.getZ());
        glEnd();

	

		A = Point(0       , 0       , 2);
		B = Point(cos(a)  , sin(a)  , 2);
		C = Point(cos(a+k), sin(a+k), 2);

		P = Vector(A, B);
		Q = Vector(A, C);
		N = Vector().getNormal(P, Q);

		glNormal3d(N.getX(), N.getY(), N.getZ());
        
        glBegin(GL_POLYGON);
        glVertex3d(A.getX(), A.getY(), A.getZ());
        glVertex3d(B.getX(), B.getY(), B.getZ());
        glVertex3d(C.getX(), C.getY(), C.getZ());
        glEnd();
    }
	glPopMatrix();

    GLdouble vert[8][3] = {
        { 1,   0, 1 }, // 0
        { 1, 0.2, 1 }, // 1
        { 1, 0.6, 0 }, // 2
		{ 1,   0, 0 }, // 3
		{ 0,   0, 0 }, // 4
		{ 0, 0.6, 0 }, // 5
		{ 0, 0.2, 1 }, // 6
		{ 0,   0, 1 }  // 7
    };

    GLint face[6][4] = {
        { 0, 3, 2, 1 }, // 0-3-2-1
		{ 3, 4, 5, 2 }, // 3-4-5-2
		{ 4, 7, 6, 5 }, // 4-7-6-5
		{ 7, 0, 1, 6 }, // 7-0-1-6
		{ 6, 1, 2, 5 }, // 6-1-2-5
		{ 0, 7, 4, 3 }  // 0-7-4-3
    };

	glPushMatrix();
	glTranslated(0.5, 1, 1);
    for(int i = 0; i < 6; i++) {
        glBegin(GL_POLYGON);

		Point A = Point(
			vert[face[i][0]][0],
			vert[face[i][0]][1],
			vert[face[i][0]][2]
		);

		Point B = Point(
			vert[face[i][1]][0],
			vert[face[i][1]][1],
			vert[face[i][1]][2]
		);

		Point C = Point(
			vert[face[i][2]][0],
			vert[face[i][2]][1],
			vert[face[i][2]][2]
		);

		Vector P = Vector(A, B);
		Vector Q = Vector(A, C);

		Vector N = Vector().getNormal(P, Q);

		glNormal3d(N.getX(), N.getY(), N.getZ());

        for(int j = 0; j < 4; j++) {
            GLint v = face[i][j];
            if(v >= 0) {
                GLdouble x = vert[v][0];
                GLdouble y = vert[v][1];
                GLdouble z = vert[v][2];
                glVertex3d(x, y, z);
            }
        }
        glEnd();
    }
	glPopMatrix();
}

void House3D::drawRidgedTile(GLint width, GLint angle, Color color) {
	GLdouble r = (GLdouble) color.getColorRed()   / 255;
	GLdouble g = (GLdouble) color.getColorGreen() / 255;
	GLdouble b = (GLdouble) color.getColorBlue()  / 255;

	glColor3d(r, g, b);

	GLint z = width;

    GLdouble vert[10][3] = {
        { 2,   0, z }, // 0
        { 2, 0.2, z }, // 1
        { 1, 1.2, z }, // 2
		{ 0, 0.2, z }, // 3
		{ 0,   0, z }, // 4
		{ 0,   0, 0 }, // 5
		{ 0, 0.2, 0 }, // 6
		{ 1, 1.2, 0 }, // 7
		{ 2, 0.2, 0 }, // 8
		{ 2,   0, 0 }  // 9
    };

    GLint face[7][5] = {
        { 4, 0, 1, 2,  3 }, // 4-0-1-2-3
		{ 5, 4, 3, 6, -1 }, // 5-4-3-6
		{ 9, 5, 6, 7,  8 }, // 9-5-6-7-8
		{ 0, 9, 8, 1, -1 }, // 0-9-8-1
		{ 6, 3, 2, 7, -1 }, // 6-3-2-7
		{ 1, 8, 7, 2, -1 }, // 1-8-7-2
		{ 4, 5, 9, 0, -1 }  // 4-5-9-0
    };

    glPushMatrix();
    if(angle == 90) {
        glTranslated(0, 0, 2);
        glRotated(angle, 0, 1, 0);
    }

    for(int i = 0; i < 7; i++) {
        glBegin(GL_POLYGON);

		Point A = Point(
			vert[face[i][0]][0],
			vert[face[i][0]][1],
			vert[face[i][0]][2]
		);

		Point B = Point(
			vert[face[i][1]][0],
			vert[face[i][1]][1],
			vert[face[i][1]][2]
		);

		Point C = Point(
			vert[face[i][2]][0],
			vert[face[i][2]][1],
			vert[face[i][2]][2]
		);

		Vector P = Vector(A, B);
		Vector Q = Vector(A, C);

		Vector N = Vector().getNormal(P, Q);

		glNormal3d(N.getX(), N.getY(), N.getZ());

        for(int j = 0; j < 5; j++) {
            GLint v = face[i][j];
            if(v >= 0) {
                GLdouble x = vert[v][0];
                GLdouble y = vert[v][1];
                GLdouble z = vert[v][2];
                glVertex3d(x, y, z);
            }
        }
        glEnd();
    }
    glPopMatrix();
}

void House3D::drawEndRidgedTile(GLint angle, Color color) {
	GLdouble r = (GLdouble) color.getColorRed()   / 255;
	GLdouble g = (GLdouble) color.getColorGreen() / 255;
	GLdouble b = (GLdouble) color.getColorBlue()  / 255;

	glColor3d(r, g, b);

    GLdouble vert[10][3] = {
        { 2,   0, 1 }, // 0
        { 2, 0.2, 1 }, // 1
        { 1, 1.2, 1 }, // 2
		{ 0, 0.2, 1 }, // 3
		{ 0,   0, 1 }, // 4
		{ 0,   0, 0 }, // 5
		{ 0, 0.2, 0 }, // 6
		{ 2, 0.2, 0 }, // 7
		{ 2,   0, 0 }  // 8
    };

    GLint face[8][5] = {
        { 4, 0, 1,  2,  3 }, // 4-0-1-2-3
		{ 8, 5, 6,  7, -1 }, // 8-5-6-7
		{ 5, 4, 3,  6, -1 }, // 5-4-3-6
		{ 0, 8, 7,  1, -1 }, // 0-8-7-1
		{ 2, 7, 6, -1, -1 }, // 6-2-7
		{ 2, 6, 3, -1, -1 }, // 3-6-2
		{ 2, 1, 7, -1, -1 }, // 7-1-2
		{ 0, 4, 5,  8, -1 }  // 0-4-5-8
    };

    glPushMatrix();
    if(angle == 90) {
        glTranslated(0, 0, 2);
        glRotated(angle, 0, 1, 0);
    } else if(angle == 180) {
        glTranslated(2, 0, 1);
        glRotated(angle, 0, 1, 0);
    } else if(angle == 270) {
        glTranslated(1, 0, 0);
        glRotated(angle, 0, 1, 0);
    }

    for(int i = 0; i < 8; i++) {
        glBegin(GL_POLYGON);

		Point A = Point(
			vert[face[i][0]][0],
			vert[face[i][0]][1],
			vert[face[i][0]][2]
		);

		Point B = Point(
			vert[face[i][1]][0],
			vert[face[i][1]][1],
			vert[face[i][1]][2]
		);

		Point C = Point(
			vert[face[i][2]][0],
			vert[face[i][2]][1],
			vert[face[i][2]][2]
		);

		Vector P = Vector(A, B);
		Vector Q = Vector(A, C);

		Vector N = Vector().getNormal(P, Q);

		glNormal3d(N.getX(), N.getY(), N.getZ());

        for(int j = 0; j < 5; j++) {
            GLint v = face[i][j];
            if(v >= 0) {
                GLdouble x = vert[v][0];
                GLdouble y = vert[v][1];
                GLdouble z = vert[v][2];
                glVertex3d(x, y, z);
            }
        }
        glEnd();
    }
	glPopMatrix();
}

void House3D::drawAnglePlate(GLint angle, Color color) {
	glPushMatrix();
	if(angle == 90) {
        glTranslated(0, 0, 1.4);
        glRotated(angle, 0, 1, 0);
    } else if(angle == 180) {
        glTranslated(1.4, 0, 1.4);
        glRotated(angle, 0, 1, 0);
    } else if(angle == 270) {
        glTranslated(2, 0, 0);
        glRotated(angle, 0, 1, 0);
    }

		glPushMatrix();
		glTranslated(0.4, 1.6, 0);
		drawPlate(1, 2, color);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0.4, 0, 0);
		glRotated(90, 0, 0, 1);
		drawPlate(2, 2, color);
		glPopMatrix();
	glPopMatrix();
}

void House3D::drawWallCorner(GLint angle, Color color) {
	GLdouble r = (GLdouble) color.getColorRed()   / 255;
	GLdouble g = (GLdouble) color.getColorGreen() / 255;
	GLdouble b = (GLdouble) color.getColorBlue()  / 255;

	glColor3d(r, g, b);

	glPushMatrix();
	if(angle == 90) {
        glTranslated(0, 0, 1);
        glRotated(angle, 0, 1, 0);
    } else if(angle == 180) {
        glTranslated(1, 0, 1);
        glRotated(angle, 0, 1, 0);
    } else if(angle == 270) {
        glTranslated(1, 0, 0);
        glRotated(angle, 0, 1, 0);
    }
		glPushMatrix();
		glTranslated(0.5, 0.2, 0.5);
		glScaled(1, 0.4, 1);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0.1, 0.8, 0.5);
		glScaled(0.2, 0.8, 1);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0.6, 0.8, 0.1);
		glScaled(0.8, 0.8, 0.2);
		glutSolidCube(1.0);
		glPopMatrix();
	glPopMatrix();
}

void House3D::drawRoofTile(GLint width, GLdouble angle, Color color) {
	GLdouble r = (GLdouble) color.getColorRed()   / 255;
	GLdouble g = (GLdouble) color.getColorGreen() / 255;
	GLdouble b = (GLdouble) color.getColorBlue()  / 255;

	glColor3d(r, g, b);

	GLdouble z = (GLdouble) width;

    GLdouble vert[10][3] = {
        { 2,   0, z }, // 0
        { 2, 1.2, z }, // 1
        { 1, 1.2, z }, // 2
        { 0, 0.2, z }, // 3
        { 0,   0, z }, // 4
        { 0,   0, 0 }, // 5
        { 0, 0.2, 0 }, // 6
        { 1, 1.2, 0 }, // 7
        { 2, 1.2, 0 }, // 8
        { 2,   0, 0 }  // 9
    };

    GLint face[7][5] = {
        { 4, 0, 1, 2,  3 }, // 4-0-1-2-3
        { 5, 4, 3, 6, -1 }, // 5-4-3-6
        { 9, 5, 6, 7,  8 }, // 9-5-6-7-8
        { 0, 9, 8, 1, -1 }, // 0-9-8-1
        { 7, 2, 1, 8, -1 }, // 7-2-1-8
        { 6, 3, 2, 7, -1 }, // 6-3-2-7
        { 4, 5, 9, 0, -1 }  // 4-5-9-0
    };

    glPushMatrix();
    if(angle == 90) {
        glTranslated(0, 0, 2);
        glRotated(angle, 0, 1, 0);
    } else if(angle == 180) {
        glTranslated(2, 0, z);
        glRotated(angle, 0, 1, 0);
    } else if(angle == 270) {
        glTranslated(z, 0, 0);
        glRotated(angle, 0, 1, 0);
    }

	

    for(int i = 0; i < 7; i++) {
        glBegin(GL_POLYGON);

		Point A = Point(
			vert[face[i][0]][0],
			vert[face[i][0]][1],
			vert[face[i][0]][2]
		);

		Point B = Point(
			vert[face[i][1]][0],
			vert[face[i][1]][1],
			vert[face[i][1]][2]
		);

		Point C = Point(
			vert[face[i][2]][0],
			vert[face[i][2]][1],
			vert[face[i][2]][2]
		);

		Vector P = Vector(A, B);
		Vector Q = Vector(A, C);

		Vector N = Vector().getNormal(P, Q);

		glNormal3d(N.getX(), N.getY(), N.getZ());

        for(int j = 0; j < 5; j++) {
            GLint v = face[i][j];
            if(v >= 0) {
                GLdouble x = vert[v][0];
                GLdouble y = vert[v][1];
                GLdouble z = vert[v][2];
                glVertex3d(x, y, z);
            }
        }
        glEnd();
    }
    glPopMatrix();
}

void House3D::drawPlateWithSlide(GLint angle, GLint length, Color color) {
	glPushMatrix();
	if(angle == 90) {
        glTranslated(0, 0, 1.45);
        glRotated(angle, 0, 1, 0);
    } else if(angle == 180) {
        glTranslated(1.45, 0, length);
        glRotated(angle, 0, 1, 0);
    } else if(angle == 270) {
        glTranslated(length, 0, 0);
        glRotated(angle, 0, 1, 0);
    }
		glPushMatrix();
		glTranslated(0.45, 0, 0);
		drawPlate(1, length, color);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0.3, 0.2, length / 2);
		glScaled(0.3, 0.1, length);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0.075, 0.2, length / 2);
		glScaled(0.15, 0.4, length);
		glutSolidCube(1.0);
		glPopMatrix();
	glPopMatrix();
}

void House3D::drawRoofTileInverted(GLint width, GLdouble angle, Color color) {
	GLdouble r = (GLdouble) color.getColorRed()   / 255;
	GLdouble g = (GLdouble) color.getColorGreen() / 255;
	GLdouble b = (GLdouble) color.getColorBlue()  / 255;

	glColor3d(r, g, b);
	
	GLdouble z = (GLdouble) width;

    GLdouble vert[10][3] = {
        { 2,   0, z }, // 0
        { 2, 1.2, z }, // 1
        { 1, 1.2, z }, // 2
        { 0, 0.2, z }, // 3
        { 0,   0, z }, // 4
        { 0,   0, 0 }, // 5
        { 0, 0.2, 0 }, // 6
        { 1, 1.2, 0 }, // 7
        { 2, 1.2, 0 }, // 8
        { 2,   0, 0 }  // 9
    };

    GLint face[7][5] = {
        { 4, 0, 1, 2,  3 }, // 4-0-1-2-3
        { 5, 4, 3, 6, -1 }, // 5-4-3-6
        { 9, 5, 6, 7,  8 }, // 9-5-6-7-8
        { 0, 9, 8, 1, -1 }, // 0-9-8-1
        { 7, 2, 1, 8, -1 }, // 7-2-1-8
        { 6, 3, 2, 7, -1 }, // 6-3-2-7
        { 4, 5, 9, 0, -1 }  // 4-5-9-0
    };

    glPushMatrix();
    if(angle == 90) {
        glTranslated(0, 0, 2);
        glRotated(angle, 0, 1, 0);
    } else if(angle == 180) {
        glTranslated(2, 0, z);
        glRotated(angle, 0, 1, 0);
    } else if(angle == 270) {
        glTranslated(z, 0, 0);
        glRotated(angle, 0, 1, 0);
    }

	for(int z = 0; z < width; z++) {
		glPushMatrix();
		glTranslated(1.5, 1.2, 0.5 + z);
		drawRound(0.2, 0.3);
		glPopMatrix();
	}

		glPushMatrix();
		glTranslated(0, 1.2, z);
		glRotated(180, 1, 0, 0);
		for(int i = 0; i < 7; i++) {
			glBegin(GL_POLYGON);

			Point A = Point(
				vert[face[i][0]][0],
				vert[face[i][0]][1],
				vert[face[i][0]][2]
			);

			Point B = Point(
				vert[face[i][1]][0],
				vert[face[i][1]][1],
				vert[face[i][1]][2]
			);

			Point C = Point(
				vert[face[i][2]][0],
				vert[face[i][2]][1],
				vert[face[i][2]][2]
			);

			Vector P = Vector(A, B);
			Vector Q = Vector(A, C);

			Vector N = Vector().getNormal(P, Q);

			glNormal3d(N.getX(), N.getY(), N.getZ());

			for(int j = 0; j < 5; j++) {
				GLint v = face[i][j];
				if(v >= 0) {
					GLdouble x = vert[v][0];
					GLdouble y = vert[v][1];
					GLdouble z = vert[v][2];
					glVertex3d(x, y, z);
				}
			}
			glEnd();
		}
		glPopMatrix();
    glPopMatrix();
}

void House3D::drawRound(GLdouble height, GLdouble radius) {
	GLdouble pi = 3.14159265;
	GLdouble h  = height;
    GLdouble r  = radius;
    GLdouble k  = 2 * pi / 10;
	
	Point  A, B, C, D;
	Vector P, Q, N;

    for(GLdouble a = 0.0; a < 2 * pi; a += k) {
		

		A = Point(r * cos(a)  , h, r * sin(a)  );
		B = Point(r * cos(a+k), h, r * sin(a+k));
		C = Point(r * cos(a+k), 0, r * sin(a+k));
		D = Point(r * cos(a)  , 0, r * sin(a)  );

		P = Vector(A, B);
		Q = Vector(A, C);
		N = Vector().getNormal(P, Q);

		glNormal3d(N.getX(), N.getY(), N.getZ());

        glBegin(GL_POLYGON);
		glVertex3d(A.getX(), A.getY(), A.getZ());
        glVertex3d(B.getX(), B.getY(), B.getZ());
        glVertex3d(C.getX(), C.getY(), C.getZ());
        glVertex3d(D.getX(), D.getY(), D.getZ());
        glEnd();
        
		

		A = Point(r * cos(a)  , 0, r * sin(a)  );
		B = Point(r * cos(a+k), 0, r * sin(a+k));
		C = Point(0           , 0, 0           );

		P = Vector(A, B);
		Q = Vector(A, C);
		N = Vector().getNormal(P, Q);

		glNormal3d(N.getX(), N.getY(), N.getZ());

        glBegin(GL_POLYGON);
        glVertex3d(A.getX(), A.getY(), A.getZ());
        glVertex3d(B.getX(), B.getY(), B.getZ());
        glVertex3d(C.getX(), C.getY(), C.getZ());
        glEnd();

		

		A = Point(r * cos(a+k), h, r * sin(a+k));
		B = Point(r * cos(a)  , h, r * sin(a)  );
		C = Point(0           , h, 0           );

		P = Vector(A, B);
		Q = Vector(A, C);
		N = Vector().getNormal(P, Q);

		glNormal3d(N.getX(), N.getY(), N.getZ());
        
        glBegin(GL_POLYGON);
        glVertex3d(A.getX(), A.getY(), A.getZ());
        glVertex3d(B.getX(), B.getY(), B.getZ());
        glVertex3d(C.getX(), C.getY(), C.getZ());
        glEnd();
    }
}

void House3D::drawDoor(GLint angle) {
	GLdouble r = (GLdouble) mediumGrey.getColorRed()   / 255;
	GLdouble g = (GLdouble) mediumGrey.getColorGreen() / 255;
	GLdouble b = (GLdouble) mediumGrey.getColorBlue()  / 255;
	
	if(angle == 90) {
		glTranslated(0, 0, 4);
		glRotated(angle, 0, 1, 0);
	} else if(angle == 180) {
		glTranslated(4, 0, 1);
		glRotated(angle, 0, 1, 0);
	} else if(angle == 270) {
		glTranslated(1, 0, 0);
		glRotated(angle, 0, 1, 0);
	}

	glColor3d(r, g, b);

	glPushMatrix();
	glTranslated(0.5, 0, 0.5);
	drawRound(0.2, 0.5);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.2, 3.1, 0.5);
	glScaled(0.4, 5.8, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(3.8, 3.1, 0.5);
	glScaled(0.4, 5.8, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(2, 0.4, 0.5);
	glScaled(3.2, 0.4, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(2, 5.8, 0.5);
	glScaled(3.2, 0.4, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(3.5, 3.1, 0.8);
	glScaled(0.6, 0.6, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(3.5, 3.1, 0.2);
	glScaled(0.6, 0.6, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor4d(0.89, 0.97, 1, 0.6);

	glPushMatrix();
	glTranslated(2, 3.1, 0.5);
	glScaled(3.2, 5, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();
}

void House3D::drawDoorGarage(GLint angle) {
	GLdouble r = (GLdouble) mediumGrey.getColorRed()   / 255;
	GLdouble g = (GLdouble) mediumGrey.getColorGreen() / 255;
	GLdouble b = (GLdouble) mediumGrey.getColorBlue()  / 255;
	
	if(angle == 90) {
		glTranslated(0, 0, 4);
		glRotated(angle, 0, 1, 0);
	} else if(angle == 180) {
		glTranslated(4, 0, 1);
		glRotated(angle, 0, 1, 0);
	} else if(angle == 270) {
		glTranslated(1, 0, 0);
		glRotated(angle, 0, 1, 0);
	}

	glColor3d(r, g, b);

	glPushMatrix();
	glTranslated(0.2, 3, 0.5);
	glScaled(0.4, 6, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(7.8, 3, 0.5);
	glScaled(0.4, 6, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();

	/*glPushMatrix();
	glTranslated(4, 0.4, 0.5);
	glScaled(7.2, 0.4, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();*/

	glPushMatrix();
	glTranslated(4, 5.8, 0.5);
	glScaled(7.2, 0.4, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor4d(0.89, 0.97, 1, 0.6);

	glPushMatrix();
	glTranslated(4, 2.8, 0.5);
	glScaled(7.2, 5.6, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();
}

void House3D::drawWindow(GLint angle) {
	GLdouble r = (GLdouble) white.getColorRed()   / 255;
	GLdouble g = (GLdouble) white.getColorGreen() / 255;
	GLdouble b = (GLdouble) white.getColorBlue()  / 255;
	
	if(angle == 90) {
		glTranslated(0, 0, 4);
		glRotated(angle, 0, 1, 0);
	} else if(angle == 180) {
		glTranslated(4, 0, 1);
		glRotated(angle, 0, 1, 0);
	} else if(angle == 270) {
		glTranslated(1, 0, 0);
		glRotated(angle, 0, 1, 0);
	}
	
	glPushMatrix();
	glTranslated(0, 3.2, 0);
	drawPlate(4, 1, darkGrey);
	glPopMatrix();

	glPushMatrix();
	glTranslated(2, 0.2, 0.5);
	glScaled(4, 0.4, 1);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.2, 1.8, 0.5);
	glScaled(0.4, 2.8, 1);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(3.8, 1.8, 0.5);
	glScaled(0.4, 2.8, 1);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3d(r, g, b);

	glTranslated(0.4, 0.4, 0);
	glPushMatrix();
		glPushMatrix();
		glTranslated(0.1, 1.4, 0.1);
		glScaled(0.2, 2.8, 0.2);
		glutSolidCube(1.0);
		glPopMatrix();
		
		glPushMatrix();
		glTranslated(1.5, 1.4, 0.1);
		glScaled(0.2, 2.8, 0.2);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0.8, 0.1, 0.1);
		glScaled(1.2, 0.2, 0.2);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0.8, 1.4, 0.1);
		glScaled(1.2, 0.2, 0.2);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0.8, 2.7, 0.1);
		glScaled(1.2, 0.2, 0.2);
		glutSolidCube(1.0);
		glPopMatrix();
	glPopMatrix();

	glTranslated(1.6, 0, 0);
	glPushMatrix();
		glPushMatrix();
		glTranslated(0.1, 1.4, 0.1);
		glScaled(0.2, 2.8, 0.2);
		glutSolidCube(1.0);
		glPopMatrix();
		
		glPushMatrix();
		glTranslated(1.5, 1.4, 0.1);
		glScaled(0.2, 2.8, 0.2);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0.8, 0.1, 0.1);
		glScaled(1.2, 0.2, 0.2);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0.8, 1.4, 0.1);
		glScaled(1.2, 0.2, 0.2);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0.8, 2.7, 0.1);
		glScaled(1.2, 0.2, 0.2);
		glutSolidCube(1.0);
		glPopMatrix();
	glPopMatrix();
}

void House3D::drawFlatTile(GLint width, GLint length, Color color) {
	drawCube(width, length, 0.4, color );
}

void House3D::drawAngularPlate(GLdouble angle, Color color) {
	GLdouble r = (GLdouble) color.getColorRed()   / 255;
	GLdouble g = (GLdouble) color.getColorGreen() / 255;
	GLdouble b = (GLdouble) color.getColorBlue()  / 255;

	glColor3d(r, g, b);

	if(angle == 90) {
        glTranslated(0, 0, 1);
        glRotated(angle, 0, 1, 0);
    } else if(angle == 180) {
        glTranslated(1, 0, 1);
        glRotated(angle, 0, 1, 0);
    } else if(angle == 270) {
        glTranslated(1, 0, 0);
        glRotated(angle, 0, 1, 0);
    }

	glPushMatrix();
	glTranslated(0.5, 0.1, 0.5);
	glScaled(1, 0.2, 1);
	glutSolidCube(1.0);
    glPopMatrix();

	glPushMatrix();
	glTranslated(0.6, 0.7, 0.5);
	glScaled(0.8, 1, 1);
	glutSolidCube(1.0);
    glPopMatrix();

	/*glPushMatrix();
	glTranslated(0.5, 1.2, 0.5);
	drawRound(0.2, 0.3);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.2, 0.7, 0.5);
	glRotated(90, 0, 0, 1);
	drawRound(0.2, 0.3);
	glPopMatrix();*/
}

void House3D::drawRoundPlate(Color color) {
	GLdouble r = (GLdouble) color.getColorRed()   / 255;
	GLdouble g = (GLdouble) color.getColorGreen() / 255;
	GLdouble b = (GLdouble) color.getColorBlue()  / 255;

	glColor3d(r, g, b);

	glPushMatrix();
    glTranslated(0.5, 0.0, 0.5);
	drawRound(0.2, 0.4);
	glTranslated(0.0, 0.2, 0.0);
	drawRound(0.2, 0.5);
	glTranslated(0.0, 0.2, 0.0);
	drawRound(0.2, 0.3);
    glPopMatrix();
}

void House3D::drawRoundPlate2(Color color) {
	GLdouble r = (GLdouble) color.getColorRed()   / 255;
	GLdouble g = (GLdouble) color.getColorGreen() / 255;
	GLdouble b = (GLdouble) color.getColorBlue()  / 255;

	glColor3d(r, g, b);

	glPushMatrix();
    glTranslated(0.5, 0.0, 0.5);
	drawRound(1.0, 0.5);
	glTranslated(0.0, 0.2, 0.0);
	drawRound(1.0, 0.5);
	
    glPopMatrix();
}

void House3D::drawRadiatorGrile(GLdouble angle, Color color) {
	GLdouble r = (GLdouble) color.getColorRed()   / 255;
	GLdouble g = (GLdouble) color.getColorGreen() / 255;
	GLdouble b = (GLdouble) color.getColorBlue()  / 255;

	GLdouble w = 1;
	GLdouble l = 2;
	GLdouble h = 0.4;

	glColor3d(r, g, b);

	if(angle == 90) {
        glTranslated(0, 0, 1);
        glRotated(angle, 0, 1, 0);
    }

	glPushMatrix();
	glTranslated(0.1, h / 2, l / 2);
	glScaled(0.2, h, l);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.5, h - 0.1, l / 2);
	glScaled(0.2, 0.2, l);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.9, h / 2, l / 2);
	glScaled(0.2, h, l);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(w / 2, (h - 0.2) / 2, 0.1);
	glScaled(w - 0.4, h - 0.2, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(w / 2, (h - 0.2) / 2, l - 0.1);
	glScaled(w - 0.4, h - 0.2, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();
}

void House3D::drawPlate2(GLint width, GLint length, Color color) {
	drawCube(width, length, 1.2, color);
}

void House3D::drawBrick(GLint width, GLint length, Color color) {
	drawCube2(width, length, 1.2, color);
}
void House3D::drawFence(GLint angle) {
	GLdouble r = (GLdouble) black.getColorRed()   / 255;
	GLdouble g = (GLdouble) black.getColorGreen() / 255;
	GLdouble b = (GLdouble) black.getColorBlue()  / 255;

	if(angle == 90) {
		glTranslated(0, 0, 4);
		glRotated(angle, 0, 1, 0);
	}

	glColor3d(r, g, b);

	glPushMatrix();
	glTranslated(2, 0.2, 0.5);
	glScaled(4, 0.4, 1);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(2, 0.5, 0.5);
	glScaled(4, 0.2, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(2, 2.3, 0.5);
	glScaled(4, 0.2, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.1, 1.4, 0.5);
	glScaled(0.2, 1.6, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(3.9, 1.4, 0.5);
	glScaled(0.2, 1.6, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.2, 0.6, 0.3);

	for(double x = 0.45; x < 3.6; x += 0.45) {
		glPushMatrix();
		glTranslated(x, 0.8, 0.2);
		glScaled(0.05, 1.6, 0.4);
		glutSolidCube(1.0);
		glPopMatrix();
	}
}

void House3D::drawLine(GLdouble width, GLdouble length, Color color) {
	drawCube(width, length, 0.4, color);
}

void House3D::drawBasePlate(GLint width, GLint length, Color color) {
	drawPlate(width, length, color);
}

void House3D::drawPlate(GLint width, GLint length, Color color) {
	drawCube(width, length, 0.4, color);
}


void House3D::drawCube(GLdouble width, GLdouble length, GLdouble height, Color color) {
	GLdouble r = (GLdouble) color.getColorRed()   / 255;
	GLdouble g = (GLdouble) color.getColorGreen() / 255;
	GLdouble b = (GLdouble) color.getColorBlue()  / 255;

	glColor3d(r, g, b);

	glPushMatrix();
    glTranslated(width / 2, height / 2, length / 2);
    glScaled(width, height, length);
    glutSolidCube(1.0);
    glPopMatrix();
}

void House3D::drawCube2(GLdouble width, GLdouble length, GLdouble height, Color color) {
	GLdouble r = (GLdouble) color.getColorRed()   / 255;
	GLdouble g = (GLdouble) color.getColorGreen() / 255;
	GLdouble b = (GLdouble) color.getColorBlue()  / 255;

	glColor3d(r, g, b);

	glPushMatrix();
	
		for(int x = 0; x < width; x++) {
			for(int y = 0; y < length; y++) {
				glPushMatrix();
				glTranslated(0.5 + x, height, 0.5 + y);
				drawRound(0.2, 0.3);
				glPopMatrix();
			}
		}
	
    glTranslated(width / 2, height / 2, length / 2);
    glScaled(width, height, length);
    glutSolidCube(1.0);
    glPopMatrix();
}
