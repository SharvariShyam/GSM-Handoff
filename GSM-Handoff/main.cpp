#include <iostream>
#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include "draw.h"
#include <string.h>
#include  "SOIL.h"
//#include "linepoints.cpp"


#define FPS 10
int dis=0;

using namespace std;
void addImage();
void timer_call(int);
void move_car();
void car_navigation(int,int,int);
//static GLdouble viewer[] = {0.0,0.0,15.0};

//int car_pos=-17;


void move_car(){
    glPushMatrix();
    glTranslatef(0+car_pos,0,0);
    car();
    if(car_pos>20){
        car_pos=-18;
    }
    if(car_pos<-18) {
        car_pos = 20;
    }
    glPopMatrix();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  //  if(dis == 0) {
    //    frontpage();
    //}

    //if(dis == 1){

    addImage();
    move_car();
        trees();
        road();
        tower();
        msc();
        range();
        horizon();
        sky();
        cloudy();
        drawlines();
    //}
    glFlush();
    glutSwapBuffers();
}

void timer_call(int){
    glutPostRedisplay(); //call display after every time lapse
    glutTimerFunc(1000/FPS,timer_call,0);
}

void myinit(){
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glClearColor(1.0,1.0,1.0,1.0);
    glOrtho(-20.0,20.0,-10.0,10.0,-10.0,10.0);
}

void car_navigation(int key,int,int){
    switch(key){
        case GLUT_KEY_RIGHT:
            car_pos++;
            break;
        case GLUT_KEY_LEFT:
            car_pos--;
            break;
    }


}

void myReshape(int w, int h) {
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w <= h)
        glFrustum(-10.0,10.0,-10.0*(GLfloat)h/(GLfloat)w,10.0*(GLfloat)h/(GLfloat)w,10.0,40.0);
    else
        glFrustum(-10.0*(GLfloat)w/(GLfloat)h,10.0*(GLfloat)w/(GLfloat)h,-10.0,10.0,10.0,40.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    if(key=='m')
        dis++;
    if(key=='n')
        dis--;
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1500,750);
    glutCreateWindow("GSM");
    //glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glutTimerFunc(0,timer_call,0);
    glutSpecialFunc(car_navigation);
    //glutReshapeFunc(myReshape);
    glutKeyboardFunc(keyboard);
   //gluLookAt(0.0,0.0,-10.0,0.0,0.0,0.0,0,1,0);

    glEnable (GL_LIGHTING);
    glEnable (GL_LIGHT0);


    //glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    glShadeModel (GL_SMOOTH);
    GLfloat mat_ambient[] = {0.4f, 0.4f, 0.4f, 1.0f}; // gray
    GLfloat mat_diffuse[] = {.5f, .5f, .5f, 1.0f};
    GLfloat mat_specular[] = {0.5f, 0.5f, 0.5f, 1.0f};
    GLfloat mat_shininess[] = {50.0f};
    glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv (GL_FRONT, GL_SHININESS, mat_shininess);

            //set the light source properties
    GLfloat lightIntensity[] = {1.0f, 1.0f, 1.0f, 1.0f};
   // GLfloat light_position[] = {-7.0f, -3.0f, -7.0f, 0.0f};
    // Create light components
GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat diffuseLight[] = { 0.8f, 0.8f, 0.8, 1.0f };
GLfloat specularLight[] = { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat position[] = { 1.5f, 1.0f, 4.0f, 1.0f };

// Assign created components to GL_LIGHT0
glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
glLightfv(GL_LIGHT0, GL_POSITION, position);

    //glLightfv (GL_LIGHT0, GL_POSITION, light_position);
    glLightfv (GL_LIGHT0, GL_DIFFUSE, lightIntensity);

    myinit();
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}

void addImage() {

	glEnable(GL_TEXTURE_2D);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	GLuint tex_2d1 = SOIL_load_OGL_texture
	(
		"sc6.jpeg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_COMPRESS_TO_DXT
	);
	//change vertex co-ordinates accordingly
	glBindTexture(GL_TEXTURE_2D, tex_2d1);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(-20, 2);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(20, 2);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(20, 10);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(-20, 10);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glFlush();
}
