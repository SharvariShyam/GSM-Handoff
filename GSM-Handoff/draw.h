#include "linepoints.cpp"

int p=0;
int i=0;

float car_pos=-17;
float points[20][2];
float bs1msc[20][2];
float mscbs2[20][2];

void drawlines();
void car();
void towertemp();
void tower();
void trees();
void treetemp();

void top_car(){
    glColor3f(0.9,0.9,0.9);
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


// outlining top car

glColor3f(1,0,0);
glLineWidth(5);
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

    glBegin(GL_LINE_LOOP);// right

    glVertex3f(2,2,0.3);
    glVertex3f(2,2,1.8);
    glVertex3f(3,0,2);
    glVertex3f(3,0,0);
    glEnd();

glBegin(GL_LINE_LOOP);// left

    glVertex3f(-2,2,0.3);
    glVertex3f(-2,2,1.8);
    glVertex3f(-3,0,2);
    glVertex3f(-3,0,0);
    glEnd();
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex3f(-2,2.1,0.3);
    glVertex3f(-2,2.1,1.8);
    glVertex3f(2,2.1,1.8);
    glVertex3f(2,2.1,0.3);
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

void towertemp(float x, float y, float z) {
    glPushMatrix();
    glLineWidth(4);
    glColor3f(0,0,0);
    glTranslatef(0,-2,0);
    glRotatef(75,-1,0,0);
    glScalef(x,y,z);
    glutWireCone(2,8,6,10);
    glLineWidth(1);
    glPopMatrix();
}

void tower(){

    glPushMatrix();
    glTranslatef(-12,-1,0);
    towertemp(0.75,0.75,0.75);
    glPopMatrix();
    display_string(-13,3,"Old BS",2);

    glPushMatrix();
    glTranslatef(11,3,0);
    towertemp(0.5,0.5,0.5);
    glPopMatrix();
    display_string(10,5.3,"New BS",2);

}

void treetemp(float x,float y,float z){
    glPushMatrix();
    glScalef(x,y,z);

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
    glTranslatef(-25,2,0);
    treetemp(1.7,1.7,1.7);
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7,0.7,0.7);
    glTranslatef(-20,2,0);
    treetemp(2,2,2);
    glPopMatrix();

    glPushMatrix();
    //glScalef(0.7,0.7,0.7);
    glTranslatef(15,-6,-2);
    treetemp(2.2,2.2,2.2);
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
    glTranslatef(-3,2.8,0);
    glScalef(1,1.2,1);
    glRotatef(45,0,1,0);
    glRotatef(5,1,0,0);
    //glTranslatef(15,0,0);
    //glutWireCube(2);
    glutSolidCube(2);
    glPopMatrix();
    display_string(-6,0.8,"Mobile Switching Center",2);
}

void range() {
    glPushMatrix();
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1,0x00FF);

    glTranslatef(-4,2.3,-2);
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

void horizon(){
glColor3f(0.3,0.7,0.3);
  glPushMatrix();
  //glRotatef(10,0,1,0);
  glTranslatef(0,-5,-5);
  glScalef(20,2.8,0.1);
  glutSolidCube(5);
  /*glBegin(GL_POLYGON);
  glVertex3f(-20,-10,-5);
  glVertex3f(20,-10,-5);
  glVertex3f(20,0,-5);
  glVertex3f(-20,0,-5);
  glEnd();
  */
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
        points[20][2] = {999};
    }
    else {

        findPoints((float)car_pos,(float)-5.0,(float)11.0,(float)2.8,points);
        if(points[p+7][1] < 5.0){
            drawpixel(points[p][0],points[p][1]);
            drawpixel(points[p+7][0],points[p+7][1]);
        }
        p++;
        if(p+7>=20)
            p=0;
        points[20][2] = {999};
    }

    //float bs1msc[20][2];
    if(car_pos>=-3 && car_pos<=0) {
        findPoints(-12.0,-1.0,-3,2.8,bs1msc);
        drawpixel(bs1msc[i][0],bs1msc[i][1]);
        //drawpixel(bs1msc[i+4][0],bs1msc[i+4][1]);
        i++;
        if(i>=20)
            i=0;
        bs1msc[20][2] = {999};
    }

    if(car_pos>=0 && car_pos<=3) {
        findPoints(-3,2.8,11.0,2.8,mscbs2);
        drawpixel(mscbs2[i][0],mscbs2[i][1]);
        drawpixel(mscbs2[i+4][0],mscbs2[i+4][1]);
        i++;
        if(i+4>=20)
            i=0;
        mscbs2[20][2] = {999};
    }
}

void frontpage() {
    //glClearColor(1.0,1.0,0.1,1.0);
    glColor3f(0.0,0.0,0.0);
    display_string(-9.5,8,"PES INSTITUTE OF TECHNOLOGY-BANGALORE SOUTH CAMPUS",2); //correct cordinate according to name
    display_string(-2.5,5,"GSM HANDOFF",1);
    display_string(-6.0,3.0,"Saumya Sachdev                     1PE15CS140",2);
    display_string(-6.0,2.0,"Sharvari                                    1PE15CS143",2);
    display_string(-2.5,0.0,"Press 'm' to continue!",2);
    /*display_string(215,500,"",1);
    display_string(390,470,"HELP",2);
    display_string(10,450,"MOUSE",2);
    display_string(10,410,"PRESS RIGHT BUTTON FOR MENU",3);
    display_string(10,370,"KEYBOARD",2);
    display_string(10,340,"X-Y-Z KEYS FOR CORRESPONDING ROTATION",3);
    display_string(10,310,"A-S-Q CAR CUSTOM SIZE SELECTION",3);
    display_string(10,280,"U-F FOR CAMERA VIEW SETTINGS",3);
    display_string(10,250,"USE LEFT ARROW(<-) AND RIGHT ARROW(->) TO MOVE CAR",3);
    display_string(10,220,"ESCAPE TO EXIT",3);
    display_string(250,150,"PRESS SPACE BAR TO ENTER",2);*/
    glutPostRedisplay();
    glutSwapBuffers();
}
