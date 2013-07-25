#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>

#include "include/House3D.h"
#include "include/Image.h"
#include "include/imageloader.h"
#include "include/vec3f.h"

#define TEXTURE_FLOOR "images/lantai.rgb"

using namespace std;

GLfloat ctf[4][2] = { {-2,-2}, { 2,-2}, { 2, 2}, {-2, 2} };
GLfloat ctw[4][2] = { {-1,-1}, { 1,-1}, { 1, 1}, {-1, 1} };

GLuint textureFloor;

GLfloat angle, aspect,draw;
GLfloat rx, ry, rxo, ryo;
GLfloat cx, cy, cz, cxo, cyo, czo;


int xo, yo, button;

House3D house;

//train 2D
//class untuk terain 2D
class Terrain {
private:
	int w; //Width
	int l; //Length
	float** hs; //Heights
	Vec3f** normals;
	bool computedNormals; //Whether normals is up-to-date
public:
	Terrain(int w2, int l2) {
		w = w2;
		l = l2;

		hs = new float*[l];
		for (int i = 0; i < l; i++) {
			hs[i] = new float[w];
		}

		normals = new Vec3f*[l];
		for (int i = 0; i < l; i++) {
			normals[i] = new Vec3f[w];
		}

		computedNormals = false;
	}

	~Terrain() {
		for (int i = 0; i < l; i++) {
			delete[] hs[i];
		}
		delete[] hs;

		for (int i = 0; i < l; i++) {
			delete[] normals[i];
		}
		delete[] normals;
	}

	int width() {
		return w;
	}

	int length() {
		return l;
	}

	//Sets the height at (x, z) to y
	void setHeight(int x, int z, float y) {
		hs[z][x] = y;
		computedNormals = false;
	}

	//Returns the height at (x, z)
	float getHeight(int x, int z) {
		return hs[z][x];
	}

	//Computes the normals, if they haven't been computed yet
	void computeNormals() {
		if (computedNormals) {
			return;
		}

		//Compute the rough version of the normals
		Vec3f** normals2 = new Vec3f*[l];
		for (int i = 0; i < l; i++) {
			normals2[i] = new Vec3f[w];
		}

		for (int z = 0; z < l; z++) {
			for (int x = 0; x < w; x++) {
				Vec3f sum(0.0f, 0.0f, 0.0f);

				Vec3f out;
				if (z > 0) {
					out = Vec3f(0.0f, hs[z - 1][x] - hs[z][x], -1.0f);
				}
				Vec3f in;
				if (z < l - 1) {
					in = Vec3f(0.0f, hs[z + 1][x] - hs[z][x], 1.0f);
				}
				Vec3f left;
				if (x > 0) {
					left = Vec3f(-1.0f, hs[z][x - 1] - hs[z][x], 0.0f);
				}
				Vec3f right;
				if (x < w - 1) {
					right = Vec3f(1.0f, hs[z][x + 1] - hs[z][x], 0.0f);
				}

				if (x > 0 && z > 0) {
					sum += out.cross(left).normalize();
				}
				if (x > 0 && z < l - 1) {
					sum += left.cross(in).normalize();
				}
				if (x < w - 1 && z < l - 1) {
					sum += in.cross(right).normalize();
				}
				if (x < w - 1 && z > 0) {
					sum += right.cross(out).normalize();
				}

				normals2[z][x] = sum;
			}
		}

		//Smooth out the normals
		const float FALLOUT_RATIO = 0.5f;
		for (int z = 0; z < l; z++) {
			for (int x = 0; x < w; x++) {
				Vec3f sum = normals2[z][x];

				if (x > 0) {
					sum += normals2[z][x - 1] * FALLOUT_RATIO;
				}
				if (x < w - 1) {
					sum += normals2[z][x + 1] * FALLOUT_RATIO;
				}
				if (z > 0) {
					sum += normals2[z - 1][x] * FALLOUT_RATIO;
				}
				if (z < l - 1) {
					sum += normals2[z + 1][x] * FALLOUT_RATIO;
				}

				if (sum.magnitude() == 0) {
					sum = Vec3f(0.0f, 1.0f, 0.0f);
				}
				normals[z][x] = sum;
			}
		}

		for (int i = 0; i < l; i++) {
			delete[] normals2[i];
		}
		delete[] normals2;

		computedNormals = true;
	}

	//Returns the normal at (x, z)
	Vec3f getNormal(int x, int z) {
		if (!computedNormals) {
			computeNormals();
		}
		return normals[z][x];
	}
};
//end class
//Loads a terrain from a heightmap.  The heights of the terrain range from
//-height / 2 to height / 2.
//load terain di procedure inisialisasi
Terrain* loadTerrain(const char* filename, float height) {
	Image* image = loadBMP(filename);
	Terrain* t = new Terrain(image->width, image->height);
	for (int y = 0; y < image->height; y++) {
		for (int x = 0; x < image->width; x++) {
			unsigned char color = (unsigned char) image->pixels[3 * (y
					* image->width + x)];
			float h = height * ((color / 255.0f) - 0.5f);
			t->setHeight(x, y, h);
		}
	}

	delete image;
	t->computeNormals();
	return t;
}
//buat tipe data terain
Terrain* _terrain;
Terrain* _terrainAir;
//untuk di display
void drawSceneTanah(Terrain *terrain, GLfloat r, GLfloat g, GLfloat b) {
	//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/*
	 glMatrixMode(GL_MODELVIEW);
	 glLoadIdentity();
	 glTranslatef(0.0f, 0.0f, -10.0f);
	 glRotatef(30.0f, 1.0f, 0.0f, 0.0f);
	 glRotatef(-_angle, 0.0f, 1.0f, 0.0f);

	 GLfloat ambientColor[] = {0.4f, 0.4f, 0.4f, 1.0f};
	 glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

	 GLfloat lightColor0[] = {0.6f, 0.6f, 0.6f, 1.0f};
	 GLfloat lightPos0[] = {-0.5f, 0.8f, 0.1f, 0.0f};
	 glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	 glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
	 */
	float scale = 500.0f / max(terrain->width() - 1, terrain->length() - 1);
	glScalef(scale, scale, scale);
	glTranslatef(-(float) (terrain->width() - 1) / 2, 0.0f,
			-(float) (terrain->length() - 1) / 2);

	glColor3f(r, g, b);
	for (int z = 0; z < terrain->length() - 1; z++) {
		//Makes OpenGL draw a triangle at every three consecutive vertices
		glBegin(GL_TRIANGLE_STRIP);
		for (int x = 0; x < terrain->width(); x++) {
			Vec3f normal = terrain->getNormal(x, z);
			glNormal3f(normal[0], normal[1], normal[2]);
			glVertex3f(x, terrain->getHeight(x, z), z);
			normal = terrain->getNormal(x, z + 1);
			glNormal3f(normal[0], normal[1], normal[2]);
			glVertex3f(x, terrain->getHeight(x, z + 1), z + 1);
		}
		glEnd();
	}

}

void loadTextureFloor(void) {
     IMAGE *img;
     GLenum gluerr;

     //glGenTextures(1, &textureFloor);
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
     glTexCoord2fv(ctf[0]); glVertex3f(-13, 1,  -5);
     glTexCoord2fv(ctf[1]); glVertex3f( -1, 1,  -5);
     glTexCoord2fv(ctf[2]); glVertex3f( -1, 1, -13);
     glTexCoord2fv(ctf[3]); glVertex3f(-13, 1, -13);
     glEnd();
      glBegin(GL_QUADS);
     glTexCoord2fv(ctf[0]); glVertex3f(-1, 1,  -5);
     glTexCoord2fv(ctf[1]); glVertex3f( 1, 1,  -5);
     glTexCoord2fv(ctf[2]); glVertex3f( 1, 1, -11);
     glTexCoord2fv(ctf[3]); glVertex3f(-1, 1, -11);
     glEnd();
      glBegin(GL_QUADS);
     glTexCoord2fv(ctf[0]); glVertex3f(1, 1,  -3);
     glTexCoord2fv(ctf[1]); glVertex3f( 11, 1,  -3);
     glTexCoord2fv(ctf[2]); glVertex3f( 11, 1, -11);
     glTexCoord2fv(ctf[3]); glVertex3f(1, 1, -11);
     glEnd();     
    
    glDisable(GL_TEXTURE_2D);
    
    house.drawCreateHouse(draw);
    
    glPushMatrix();

	//glBindTexture(GL_TEXTURE_3D, texture[0]);
	drawSceneTanah(_terrain, 0.3f, 0.9f, 0.0f);
	glPopMatrix();

	glPushMatrix();

	//glBindTexture(GL_TEXTURE_3D, texture[0]);
	drawSceneTanah(_terrainAir, 0.0f, 0.2f, 0.5f);
	glPopMatrix();

	glutSwapBuffers();
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
         case GLUT_KEY_UP:
		    if(draw < 40) {
                draw +=1;
			}
		    break;
         case GLUT_KEY_DOWN:
		    if(draw > 0) {
                draw -=1;
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
	glClearColor(0.0, 0.6, 0.8, 1);

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

	glDepthFunc(GL_LESS);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glDepthFunc(GL_LEQUAL);
	
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	

	_terrain = loadTerrain("images/map.bmp", 20);
	_terrainAir = loadTerrain("images/mapAir.bmp", 20);	

	angle = 60;
	cz    = 60;
	draw  = 0;
	
	rx = ry = cx = cy = 0;
	cx = 0;
	cy = 10;
	rx = 20;
	ry = 20;
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

