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
	this->black.setColor(27, 42, 52);*/
	this->darkGreen.setColor(40, 127, 70);
	this->brightYellowishGreen.setColor(164, 189, 70);
	this->reddishBrown.setColor(105, 64, 39);
	
	
}

void House3D::drawCreateHouse() {
     glPushMatrix();
     glTranslated(-16, 0, -16);
     drawBasePlate(32, 32, this->darkGreen);    
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
