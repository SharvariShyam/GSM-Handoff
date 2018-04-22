#include <iostream>
#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
using namespace std;


void top_car(){
glColor3f(1.0,1.0,0.0);
glBegin(GL_LINE_LOOP);

  glVertex3f(-2,2,0.3);
  glVertex3f(-3,0,0);
  glVertex3f(3,0,0);
  glVertex3f(2,2,0.3);
    glEnd();

     glBegin(GL_LINE_LOOP);

  glVertex3f(-2,2,1.8);
  glVertex3f(-3,0,2);
  glVertex3f(3,0,2);
  glVertex3f(2,2,1.8);
    glEnd();

    glBegin(GL_LINE_LOOP);

    glVertex3f(2,2,0.3);
    glVertex3f(2,2,1.8);
    glVertex3f(3,0,2);
    glVertex3f(3,0,0);
    glEnd();

glBegin(GL_LINE_LOOP);

    glVertex3f(-2,2,0.3);
    glVertex3f(-2,2,1.8);
    glVertex3f(-3,0,2);
    glVertex3f(-3,0,0);
    glEnd();

}

void car(){
    glPushMatrix();
        glTranslatef(-3,-3,0);
        glScalef(0.7,0.7,0.7);
        glRotatef(45,1,0,0);

        //top

        top_car();

    // body
        glColor3f(1.0,0,0);
        glPushMatrix();
            glScalef(4.5,1,1);
            glTranslatef(0,-1,1);
            glutWireCube(2);
        glPopMatrix();

    // wheels
        glColor3f(0.0,0.0,0.0);
        glPushMatrix();

            glTranslatef(-2,-2,0);
            glutSolidTorus(0.3,0.8,8,8);
        glPopMatrix();
        glPushMatrix();

            glTranslatef(2,-2,0);
            glutSolidTorus(0.3,0.8,8,8);
        glPopMatrix();
        glPushMatrix();

            glTranslatef(-2,-2,2);
            glutSolidTorus(0.3,0.8,8,8);
        glPopMatrix();
        glPushMatrix();

            glTranslatef(2,-2,2);
            glutSolidTorus(0.3,0.8,8,8);
        glPopMatrix();
    glPopMatrix();

}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
int i,x=0;
for(i=0;i<10;i++){
    glPushMatrix();
    glTranslatef(x+i,0,0);
    car();
    glPopMatrix();
    }
    glFlush();
    glutSwapBuffers();
}

void myinit(){
glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
glClearColor(1.0,1.0,1.0,1.0);
glOrtho(-10.0,10.0,-10.0,10.0,-10.0,10.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(750,750);
    glutCreateWindow("GSM");
//glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
  //  glutIdleFunc(spincube);
   // glutMouseFunc(mouse);

 /*  GLfloat lightpos[]={0,0,9};
   GLfloat lightcol[]={0.5,0.5,0.5};
GLfloat amcol[]={0,0,1};

  glEnable(GL_LIGHTING);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,amcol);

   glEnable(GL_LIGHT0);
   glLightfv(GL_LIGHT0,GL_POSITION,lightpos);           // config light source
    glLightfv(GL_LIGHT0,GL_AMBIENT,lightcol);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,lightcol);
    glLightfv(GL_LIGHT0,GL_SPECULAR,lightcol);
*/
   gluLookAt(5.0,5.0,5.0,2.0,2.0,2.0,0,1,0);
   myinit();
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}
