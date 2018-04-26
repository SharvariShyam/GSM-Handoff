#include <iostream>
#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include "draw.h"


#define FPS 10

using namespace std;

void timer_call(int);
void move_car();
void car_navigation(int,int,int);
//static GLdouble viewer[] = {0.0,0.0,15.0};

int car_pos=-17;


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
    //gluLookAt(viewer[0], viewer[1], viewer[2], 0.0,0.0,0.0,0.0,1.0,0.0);
    move_car();

     move_car();
    trees();
    road();
    hill();

    tower();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(car_pos,-5.0,0.0);
    glVertex3f(-15.0,0.0,0.0);
    glEnd();

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
////////////////////////////////////////////////lighting////////////////////
    /*GLfloat lightpos[]={1,2,3,1};
    GLfloat amb[]={0.0,0.0,0.0,1};
    GLfloat diff[]={1.0,0,0,1};
    GLfloat spec[]={1,1,1,1};

    glEnable(GL_LIGHTING);

    //glLightModelfv(GL_LIGHT_MODEL_AMBIENT,amb);

    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0,GL_POSITION,lightpos);           // config light source
    glLightfv(GL_LIGHT0,GL_AMBIENT,amb);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,diff);
    glLightfv(GL_LIGHT0,GL_SPECULAR,spec);

    const GLfloat fortyfive = 45.0;
    const GLfloat twenty = 20.0;
    GLfloat sd[] = {-1.0,-1.0,0.0};
    glLightfv(GL_LIGHT0,GL_SPOT_DIRECTION,sd);
    glLightfv(GL_LIGHT0,GL_SPOT_CUTOFF,fortyfive);
    glLightfv(GL_LIGHT0,GL_SPOT_EXPONENT,twenty);*/
///////////////////end of lighting//////////////////////////////////////////
   gluLookAt(0.0,0.0,-10.0,0.0,0.0,0.0,0,1,0);

  /*  glEnable (GL_LIGHTING);
    glEnable (GL_LIGHT0);
    glShadeModel (GL_SMOOTH);
    GLfloat mat_ambient[] = {0.4f, 0.4f, 0.4f, 1.0f}; // gray
    GLfloat mat_diffuse[] = {.5f, .5f, .5f, 1.0f};
    GLfloat mat_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat mat_shininess[] = {50.0f};
    glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv (GL_FRONT, GL_SHININESS, mat_shininess);

            //set the light source properties
    GLfloat lightIntensity[] = {0.7f, 0.7f, 0.7f, 1.0f};
    GLfloat light_position[] = {2.0f, 6.0f, 3.0f, 0.0f};
    glLightfv (GL_LIGHT0, GL_POSITION, light_position);
    glLightfv (GL_LIGHT0, GL_DIFFUSE, lightIntensity);
*/
    myinit();
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}
