#include<string.h>

void findPoints(float x1, float y1, float x2, float y2, float points[20][2]) {
    //float points[30][2];
    int k=0;
    float dx, dy, i, e;
    float incx, incy, inc1, inc2;
    float x,y;
    dy = y2 - y1;
    dx = x2 - x1;
    if(dx < 0)
        dx = -dx;
    if(dy < 0)
        dy = -dy;
    incx = 0.5;
    if(x2 < x1)
        incx = -0.5;
    incy = 0.5;
    if(y2 < y1)
        incy = -0.5;
    x = x1; y = y1;
    if(dx > dy)
    {
        //drawPixel(x, y);
        points[k][0] = x;
        points[k++][1] = y;
        e = 2 * dy - dx;
        inc1 = 2 * (dy - dx);
        inc2 = 2 * dy;
        for(i=0;i<20 && k<20;i++)
        {
            if(e > 0)
            {
                y += incy;
                e += inc1;
            } else
                e += inc2;
            x += incx;
            //drawPixel(x, y);
            points[k][0] = x;
            points[k++][1] = y;
        }
    } else {
        //drawPixel(x, y);
        points[k][0] = x;
        points[k++][1] = y;
        e = 2 * dx - dy;
        inc1 = 2 * (dx - dy);
        inc2 = 2 * dx;
        for(i=0;i<20 && k<20;i++)
        {
            if(e>=0)
            {
                x += incx;
                e += inc1;
            } else
                e += inc2;
            y += incy;
            //drawPixel(x, y);
            points[k][0] = x;
            points[k++][1] = y;
        }
    }
}

void drawpixel(float x, float y) {
    glPointSize(10.0);
    glBegin(GL_POINTS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(x,y,0.0);
    glEnd();
    //printf("%.6f\t%.6f\n",x,y);
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



