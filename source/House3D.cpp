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
	
}

void House3D::drawCreateHouse() {
     glPushMatrix();
     glTranslated(-16, 0, -16);
     drawBasePlate(32, 29, this->darkGreen);
     draw1();
     draw2();
     //draw3();
     //draw4();
     //draw5();
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
}

void House3D::draw2(){
     
    glPushMatrix();
	glTranslated(11, 0.4, 27);
	drawPlate(10, 1, this->white);
	glPopMatrix();
     
     glPushMatrix();
	glTranslated(0, 0.4, 27);
	drawPlate(6, 1, this->white);
	glPopMatrix();

     glPushMatrix();
	glTranslated(0, 0.4, 2);
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
	glTranslated(12, 0.8, 27);
	drawFence(0);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(16, 0.8, 27);
	drawFence(0);
	glPopMatrix();
    
    for(int x = 3; x < 24; x += 4) {
		glPushMatrix();
		glTranslated(0, 0.8, x);
        drawFence(90);
		glPopMatrix();
	} 
	
	for(int x = 1; x < 28; x += 4) {
		glPushMatrix();
		glTranslated(x, 0.8, 2);
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
	glTranslated(0, 0.8, 27);
	drawBrick(1, 1, this->white);
	glPopMatrix();
	
    glPushMatrix();
	glTranslated(0, 2, 27);
	drawBrick(1, 1, this->white);
	glPopMatrix(); 
	
	glPushMatrix();
	glTranslated(0, 0.8, 2);
	drawBrick(1, 1, this->white);
	glPopMatrix();
	
    glPushMatrix();
	glTranslated(0, 2, 2);
	drawBrick(1, 1, this->white);
	glPopMatrix(); 
	
	glPushMatrix();
	glTranslated(29, 0.8, 2);
	drawBrick(1, 1, this->white);
	glPopMatrix();
	
    glPushMatrix();
	glTranslated(29, 2, 2);
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

void House3D::drawRound(GLdouble height, GLdouble radius) {
	GLdouble pi = 3.14159265;
	GLdouble h  = height;
    GLdouble r  = radius;
    GLdouble k  = 2 * pi / 10;
	
	Point  A, B, C, D;
	Vector P, Q, N;

    for(GLdouble a = 0.0; a < 2 * pi; a += k) {
		// Superfície lateral retângular

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
        
		// Superfície circular inferior

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

		// Superfície circular superior

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
