#include "linepoints.cpp"
#include<string.h>
int p=0;
int i=0;

float car_pos=-17;
float points[20][2];
float bs1msc[20][2];
float mscbs2[20][2];

void top_car(){
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);

  glVertex3f(-2,2,0.3);
  glVertex3f(-3,0,0);
  glVertex3f(3,0,0);
  glVertex3f(2,2,0.3);
    glEnd();

     glBegin(GL_POLYGON);

  glVertex3f(-2,2,1.8);
  glVertex3f(-3,0,2);
  glVertex3f(3,0,2);
  glVertex3f(2,2,1.8);
    glEnd();

    glBegin(GL_POLYGON);

    glVertex3f(2,2,0.3);
    glVertex3f(2,2,1.8);
    glVertex3f(3,0,2);
    glVertex3f(3,0,0);
    glEnd();

glBegin(GL_POLYGON);

    glVertex3f(-2,2,0.3);
    glVertex3f(-2,2,1.8);
    glVertex3f(-3,0,2);
    glVertex3f(-3,0,0);
    glEnd();

}

void car(){
    glPushMatrix();
        glTranslatef(0,-5.0,0);
        glScalef(0.7,0.7,0.7);
        glRotatef(-30,-1,0.15,0);

        //top

        top_car();

    // body
        glColor3f(1.0,0,0);
        glPushMatrix();
            glScalef(4.5,1,1);
            glTranslatef(0,-1,1);
            glutSolidCube(2);
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
            glColor3f(1.0,1.0,1.0);
            glutSolidSphere(0.5,8,8);
        glPopMatrix();
        glPushMatrix();

            glTranslatef(2,-2,2);
            glutSolidSphere(0.5,8,8);
            glColor3f(0.0,0.0,0.0);
            glutSolidTorus(0.3,0.8,8,8);
        glPopMatrix();
    glPopMatrix();

}

void towertemp() {
    glPushMatrix();
    glLineWidth(4);
    glColor3f(0,0,0);
    glTranslatef(0,-2,0);
    glRotatef(75,-1,0,0);
    glScalef(0.75,0.75,0.75);
    glutWireCone(2,8,6,10);
    glLineWidth(1);
    glPopMatrix();
}

void tower(){

    glPushMatrix();
    glTranslatef(-12,-1,0);
    towertemp();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(11,5,0);
    towertemp();
    glPopMatrix();

}

void treetemp(){
    glPushMatrix();
    glScalef(2,2,2);

    //bark
    glColor3f(0.64,0.16,0.16);
    glPushMatrix();
    glRotatef(-90,1,0,0);
    glutSolidCone(0.25,2,20,20);
    glPopMatrix();

    //branch
    glColor3f(0.64,0.16,0.16);
    glPushMatrix();
    glTranslatef(0,1,0);
    glRotatef(-75,1,1,0);
    glutSolidCone(0.05,1,20,20);
    glPopMatrix();

    //leaves
    glColor3f(0.2,0.59,0.2);
    glPushMatrix();
    glTranslatef(-0.7,2,0);
    glRotatef(-90,1,0,0);
    glutSolidSphere(0.5,10,10);
    glPopMatrix();

    glColor3f(0.2,0.65,0.2);
    glPushMatrix();
    glTranslatef(0,2.2,0);
    glRotatef(-90,1,0,0);
    glutSolidSphere(0.8,10,10);
    glPopMatrix();

    glColor3f(0.2,0.55,0.2);
    glPushMatrix();
    glTranslatef(0.4,1.9,-0.7);
    glRotatef(-90,1,0,0);
    glutSolidSphere(0.6,10,10);
    glPopMatrix();

    glPopMatrix();
}

void trees(){
    glPushMatrix();
    glScalef(0.7,0.7,0.7);
    //glTranslatef(-8,-6.5,0);
    glTranslatef(-20,7,0);
    treetemp();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7,0.7,0.7);
    //glTranslatef(-2,-6.5,0);
    glTranslatef(-15,7,0);
    treetemp();
    glPopMatrix();

}

void hill(){
    glPushMatrix();
    glColor3f(0.75,0.16,0.16);
    glTranslatef(0,0,-3);
    glScalef(3,4,1);
    glutSolidSphere(2,30,30);
    glPopMatrix();
}

void road(){
    glColor3f(0.4,0.4,0.4);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glVertex2f(-20,-9);
    glVertex2f(20,-9);
    glVertex2f(20,-6.8);
    glVertex2f(-20,-6.8);
    glEnd();
    glPopMatrix();

    glColor3f(1.0,1.0,1.0);
    glPushMatrix();
    glEnable (GL_LINE_STIPPLE);
    glLineStipple (5, 0x07FF);
    glLineWidth (5.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(-20,-7.9,1);
    glVertex3f(20,-7.9,1);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
    glPopMatrix();
    glLineWidth(1.0);

}

void msc() {
    glPushMatrix();
    glColor3f(0.7,0.7,0.7);
    glTranslatef(-3.4,5,0);
    glRotatef(45,1,1,0);
    glutSolidCube(2);
    glPopMatrix();
}

void range() {
    glPushMatrix();
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1,0x00FF);

    glTranslatef(-4,5,-2);
    glScalef(0.65,0.65,0.65);

    glColor3f(0.0,0.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(-20.0,0,0);
    glVertex3f(0,0,0);
    glVertex3f(10.0,-17.32,0);
    glVertex3f(0.0,-34.64,0);
    glVertex3f(-20.0,-34.64,0);
    glVertex3f(-30.0,-17.32,0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3f(10.0,17.32,0);
    glVertex3f(0,0,0);
    glVertex3f(10.0,-17.32,0);
    glVertex3f(30.0,-17.32,0);
    glVertex3f(40.0,0,0);
    glVertex3f(30.0,17.32,0);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(-20.0,0,0);
    glVertex3f(-30.0,17.32,0);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(30.0,-17.32,0);
    glVertex3f(40.0,-34.64,0);
    glEnd();

    glDisable(GL_LINE_STIPPLE);
    glPopMatrix();
}

void drawlines() {
    //int i=0;
    if(car_pos<1) {

        findPoints((float)car_pos,(float)-5.0,(float)-12.0,(float)-1.0,points);
        if(points[p+4][1] < -1.0){
            drawpixel(points[p][0],points[p][1]);
            drawpixel(points[p+4][0],points[p+4][1]);
        }
        p++;
        if(p+4>=20)
            p=0;
        points[20][2] = {0};
    }
    else {

        findPoints((float)car_pos,(float)-5.0,(float)11.0,(float)5.0,points);
        if(points[p][1] < 5.0){
            drawpixel(points[p][0],points[p][1]);
            drawpixel(points[p+7][0],points[p+7][1]);
        }
        p++;
        if(p+7>=20)
            p=0;
        points[20][2] = {0};
    }

    //float bs1msc[20][2];
    if(car_pos>=-3 && car_pos<=0) {
        findPoints(-12.0,-1.0,-3.4,5.0,bs1msc);
        drawpixel(bs1msc[i][0],bs1msc[i][1]);
        drawpixel(bs1msc[i+4][0],bs1msc[i+4][1]);
        i++;
        if(i+4>=20)
            i=0;
        bs1msc[20][2] = {0};
    }

    if(car_pos>=0 && car_pos<=3) {
        findPoints(-3.4,5.0,11.0,5.0,mscbs2);
        drawpixel(mscbs2[i][0],mscbs2[i][1]);
        drawpixel(mscbs2[i+4][0],mscbs2[i+4][1]);
        i++;
        if(i+4>=20)
            i=0;
        mscbs2[20][2] = {0};
    }
}


void display_string(int x, int y, char *string, int font)
{
	int len,i;
	glRasterPos2f(x, y);
	len = (int) strlen(string);
	for (i = 0; i < len; i++) {
		if(font==1)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
		else if(font==2)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
		else if(font==3)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,string[i]);
		else if(font==4)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,string[i]);
	}

}
