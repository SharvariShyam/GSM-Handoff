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
        glTranslatef(0,-5,0);
        glScalef(0.7,0.7,0.7);
        glRotatef(-15,-1,0,0);

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

void tower() {
    glPushMatrix();
    glTranslatef(0,0,0);
    glRotatef(75,-1,0,0);
    glScalef(0.75,0.75,0.75);
    glutWireCone(2,8,6,10);
    glPopMatrix();
}
