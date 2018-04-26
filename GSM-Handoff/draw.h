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
    glColor3f(0,0,0);
    glTranslatef(0,-2,0);
    glRotatef(75,-1,0,0);
    glScalef(0.75,0.75,0.75);
    glutWireCone(2,8,6,10);
    glPopMatrix();
}

void tower(){

glPushMatrix();
    glTranslatef(-15,0,0);
    towertemp();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(15,0,0);
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
    glTranslatef(-8,-6.5,0);
    treetemp();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.95,0.95,0.95);
    glTranslatef(-2,-6.5,0);
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
    glLineStipple (1, 0x03FF);
    glLineWidth (5.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(-20,-7.9,1);
    glVertex3f(20,-7.9,1);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
    glPopMatrix();
    glLineWidth(1.0);

}
