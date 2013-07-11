#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>

#include "include/House3D.h"
#include "include/Image.h"

#define TEXTURE_FLOOR "images/lantai.rgb"

using namespace std;

GLfloat ctf[4][2] = { {-2,-2}, { 2,-2}, { 2, 2}, {-2, 2} };
GLfloat ctw[4][2] = { {-1,-1}, { 1,-1}, { 1, 1}, {-1, 1} };

GLuint textureFloor;

GLfloat angle, aspect;
GLfloat rx, ry, rxo, ryo;
GLfloat cx, cy, cz, cxo, cyo, czo;

int xo, yo, button;

House3D house;


void loadTextureFloor(void) {
     IMAGE *img;
     GLenum gluerr;

     glGenTextures(1, &textureFloor);
     glBindTexture(GL_TEXTURE_2D, textureFloor);
  
     img = ImageLoad(TEXTURE_FLOOR);
     gluerr = gluBuild2DMipmaps(GL_TEXTURE_2D, 3, img->sizeX, img->sizeY, GL_RGB, GL_UNSIGNED_BYTE, (GLvoid *)(img->data));
  
     if (gluerr) {
          exit(-1);
     }

     glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
     glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
     glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
     glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
     glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
}

void loadTexture(void) {
     loadTextureFloor();
          
}

void display(void){
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     
     glColor3f(0.0f, 0.0f, 0.0f);
     
     glEnable(GL_TEXTURE_2D);     
     
     glBindTexture(GL_TEXTURE_2D, textureFloor);
     glBegin(GL_QUADS);
     glTexCoord2fv(ctf[0]); glVertex3f(-100, 0,  100);
     glTexCoord2fv(ctf[1]); glVertex3f( 100, 0,  100);
     glTexCoord2fv(ctf[2]); glVertex3f( 100, 0, -100);
     glTexCoord2fv(ctf[3]); glVertex3f(-100, 0, -100);
     glEnd();
     
     
    
    glDisable(GL_TEXTURE_2D);
    
    house.drawCreateHouse();

	glFlush();
}

void cam(void) {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(-cx, -cy, -cz);
	glRotatef(rx, 1, 0, 0);
	glRotatef(ry, 0, 1, 0);
}

void view(void) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(angle, aspect, 0.1, 1200);

	cam();
}

void reshape(GLsizei width, GLsizei height) {
	height = (height == 0 ? 1 : height);
	aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);

	view();
}

void keyboard(unsigned char key, int x, int y) {
	if(key == 27) {
		exit(EXIT_SUCCESS);
	}
}

void special(int key, int x, int y) {
	switch (key) {
		case GLUT_KEY_HOME:
			if(angle >= 10) {
                angle -=5;
			}
		    break;
		case GLUT_KEY_END:
		    if(angle <= 150) {
                angle +=5;
			}
		    break;
	}
	view();
	glutPostRedisplay();
}

void mouse(int btn, int state, int x, int y) {
	if(state == GLUT_DOWN) {
		xo     = x;
		yo     = y;
		cxo    = cx;
		cyo    = cy;
		czo    = cz;
		rxo    = rx;
		ryo    = ry;
		button = btn;
	}
	else {
        button = -1;
	}
}

void motion(int x, int y) {
	if(button == GLUT_LEFT_BUTTON) {
        
		rx = rxo - (yo - y) / 5;
		ry = ryo - (xo - x) / 5;
	} else if(button == GLUT_RIGHT_BUTTON) {
        
		cz = czo + (yo - y) / 15;
	} else if(button == GLUT_MIDDLE_BUTTON) {
        
		cx = cxo + (xo - x) / 30;
		cy = cyo - (yo - y) / 30;
	}
	cam();
	glutPostRedisplay();
}

void init(void) {	
	glClearColor(0.0, 0.0, 0.0, 0.0);

    loadTexture();

	
	glEnable(GL_CULL_FACE);

	
	glCullFace(GL_BACK);

	
	glEnable(GL_DEPTH_TEST);

	
	glShadeModel(GL_SMOOTH);

	
	glEnable(GL_COLOR_MATERIAL);

	
	glEnable(GL_LIGHTING);

	
	glEnable(GL_LIGHT0);

	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	
	glEnable(GL_NORMALIZE);

	angle = 60;
	cz    = 50;
	
	rx = ry = cx = cy = 0;
}

int main(int argc, char *argv[])
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    
    glutCreateWindow("Rumah 3D");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special);
    
    init();
    
    glutMainLoop();
     
    return EXIT_SUCCESS;
}
