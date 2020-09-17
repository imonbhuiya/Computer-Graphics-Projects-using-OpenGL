#include<stdio.h>
#include<GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>


float i=0.0,m=0.0,n=0.0,o=0.0,c=0.0,b=0.0;
float p=0.75,q=0.47,r=0.14;
float e=0.90,f=0.91,g=0.98;
int count=0;

int light=1,day=1,plane=0,comet=0,xm=900,bird=0;
char ch;

void declare(char *string)
{
    while(*string)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
}

void draw_pixel(GLint cx, GLint cy)
{

    glBegin(GL_POINTS);
    glVertex2i(cx,cy);
    glEnd();
}

void plotpixels(GLint h,GLint k, GLint x,GLint y)
{
    draw_pixel(x+h,y+k);
    draw_pixel(-x+h,y+k);
    draw_pixel(x+h,-y+k);
    draw_pixel(-x+h,-y+k);
    draw_pixel(y+h,x+k);
    draw_pixel(-y+h,x+k);
    draw_pixel(y+h,-x+k);
    draw_pixel(-y+h,-x+k);
}

void draw_circle(GLint h, GLint k, GLint r)
{
    GLint d=1-r, x=0, y=r;
    while(y>x)
    {
        plotpixels(h,k,x,y);
        if(d<0)
            d+=2*x+3;
        else
        {
            d+=2*(x-y)+5;
            --y;
        }
        ++x;
    }
    plotpixels(h,k,x,y);
}


void draw_object()
{
    int l;
    if(day==1)

    {

///sky
        glColor3f(0.0,0.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(0,380);
        glVertex2f(0,700);
        glVertex2f(1100,700);
        glVertex2f(1100,380);
        glEnd();

///moon
        int l;

        for(l=0; l<=35; l++)
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(100,625,l);
        }

///star1

        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(575,653);
        glVertex2f(570,645);
        glVertex2f(580,645);
        glVertex2f(575,642);
        glVertex2f(570,650);
        glVertex2f(580,650);
        glEnd();

///star2
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(975,643);
        glVertex2f(970,635);
        glVertex2f(980,635);
        glVertex2f(975,632);
        glVertex2f(970,640);
        glVertex2f(980,640);
        glEnd();

///star3
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(875,543);
        glVertex2f(870,535);
        glVertex2f(880,535);
        glVertex2f(875,532);
        glVertex2f(870,540);
        glVertex2f(880,540);
        glEnd();

///star4
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(375,598);
        glVertex2f(370,590);
        glVertex2f(380,590);
        glVertex2f(375,587);
        glVertex2f(370,595);
        glVertex2f(380,595);
        glEnd();

///star5
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(750,628);
        glVertex2f(745,620);
        glVertex2f(755,620);
        glVertex2f(750,618);
        glVertex2f(745,625);
        glVertex2f(755,625);
        glEnd();

///star6
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(200,628);
        glVertex2f(195,620);
        glVertex2f(205,620);
        glVertex2f(200,618);
        glVertex2f(195,625);
        glVertex2f(205,625);
        glEnd();

///star7
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(100,528);
        glVertex2f(95,520);
        glVertex2f(105,520);
        glVertex2f(100,518);
        glVertex2f(95,525);
        glVertex2f(105,525);
        glEnd();

///star8
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(300,468);
        glVertex2f(295,460);
        glVertex2f(305,460);
        glVertex2f(300,458);
        glVertex2f(295,465);
        glVertex2f(305,465);
        glEnd();

///star9
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(500,543);
        glVertex2f(495,535);
        glVertex2f(505,535);
        glVertex2f(500,532);
        glVertex2f(495,540);
        glVertex2f(505,540);
        glEnd();




//grass
        glColor3f(0.0,0.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(0,160);
        glVertex2f(0,380);
        glVertex2f(1100,380);
        glVertex2f(1100,160);
        glEnd();

    }

//Ground
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-600,0);
    glVertex2f(-600,185);
    glVertex2f(1100,185);
    glVertex2f(1100,0);
    glEnd();

///tree
    glColor3f(0.9,0.2,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(280,185);
    glVertex2f(280,255);
    glVertex2f(295,255);
    glVertex2f(295,185);
    glEnd();


    for(l=0; l<=30; l++)
    {
        glColor3f(0.0,0.5,0.0);
        draw_circle(270,250,l);
        draw_circle(310,250,l);
    }

    for(l=0; l<=25; l++)
    {
        glColor3f(0.0,0.5,0.0);
        draw_circle(280,290,l);
        draw_circle(300,290,l);
    }

    for(l=0; l<=20; l++)
    {
        glColor3f(0.0,0.5,0.0);
        draw_circle(290,315,l);
    }


///tree 1
    glColor3f(0.9,0.2,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(100,135);
    glVertex2f(100,285);
    glVertex2f(140,285);
    glVertex2f(140,135);
    glEnd();


    for(l=0; l<=40; l++)
    {
        glColor3f(0.0,0.5,0.0);
        draw_circle(40,280,l);
        draw_circle(90,280,l);
        draw_circle(150,280,l);
        draw_circle(210,280,l);
        draw_circle(65,340,l);
        draw_circle(115,340,l);
        draw_circle(175,340,l);

    }

    for(l=0; l<=55; l++)
    {
        glColor3f(0.0,0.5,0.0);
        draw_circle(115,360,l);


    }


    ///rooftop
   /// glColor3ub (241, 196, 15  );
    glColor3ub(82,157,255);
    glBegin(GL_TRIANGLES);
    glVertex2d (550, 330);
    glVertex2d (750, 475);
    glVertex2d (950, 330);
    glEnd();




    ///wall

    glColor3f(p,q,r);
    glBegin(GL_POLYGON);
    glVertex2d (550, 330);
    glVertex2d (950, 330);
    glVertex2d (950, 90);
    glVertex2d (550, 90);
    glEnd();

   ///center
glBegin(GL_POLYGON);
glColor3ub (88, 24, 69);
glVertex2d (500, 90);
glVertex2d (1000, 90);
glVertex2d (1000, 50);
glVertex2d (500, 50);
glEnd();



    ///window border

    glColor3f(0.35,0.0,0.0);
    glBegin(GL_POLYGON);

    glVertex2f(595,205);
    glVertex2f(595,285);
    glVertex2f(675,285);
    glVertex2f(675,205);

    glEnd();

    glBegin(GL_POLYGON);

    glVertex2f(825,205);
    glVertex2f(825,285);
    glVertex2f(905,285);
    glVertex2f(905,205);

    glEnd();

    glBegin(GL_POLYGON);

    glVertex2f(845,205);
    glVertex2f(845,285);
    glVertex2f(850,285);
    glVertex2f(850,205);

    glEnd();



    ///door
    glColor3f(e,f,g);
    glBegin(GL_POLYGON);

    glVertex2f(800,100);
    glVertex2f(800,220);
    glVertex2f(700,220);
    glVertex2f(700,100);

    glEnd();

    glColor3f(0.35,0.0,0.0);
    glBegin(GL_POLYGON);

    glVertex2f(760,120);
    glVertex2f(760,200);
    glVertex2f(700,220);
    glVertex2f(700,100);

    glEnd();



    ///window
    glColor3f(e,f,g);
    glBegin(GL_POLYGON);

    glVertex2f(600,210);
    glVertex2f(600,280);
    glVertex2f(670,280);
    glVertex2f(670,210);

    glEnd();

    glBegin(GL_POLYGON);

    glVertex2f(830,210);
    glVertex2f(830,280);
    glVertex2f(900,280);
    glVertex2f(900,210);

    glEnd();

    glColor3f(0.35,0.0,0.0);
    glBegin(GL_POLYGON);

    glVertex2f(620,210);
    glVertex2f(620,280);
    glVertex2f(625,280);
    glVertex2f(625,210);

    glEnd();

    glBegin(GL_POLYGON);

    glVertex2f(650,210);
    glVertex2f(650,280);
    glVertex2f(655,280);
    glVertex2f(655,210);

    glEnd();



    glColor3f(0.35,0.0,0.0);
    glBegin(GL_POLYGON);

    glVertex2f(850,205);
    glVertex2f(850,285);
    glVertex2f(855,285);
    glVertex2f(855,205);

    glEnd();

    glBegin(GL_POLYGON);

    glVertex2f(880,205);
    glVertex2f(880,285);
    glVertex2f(885,285);
    glVertex2f(885,205);

    glEnd();






}








void mouse(int btn,int state,int x,int y)
{
    if(btn==GLUT_LEFT_BUTTON && state==GLUT_UP)
        exit(0);
}




void main_menu(int index)
{
    switch(index)
    {
    case 1:
        if(index==1)
        {
            plane=1;
            o=n=0.0;
        }
        break;

    }
}



void myinit()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(0.0,0.0,1.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,1200.0,0.0,700.0);
}



void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
    draw_object();
    glFlush();
}


int main(int argc,char** argv)
{
    int c_menu;

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1200.0,700.0);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Simple Village");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    return 0;
}

