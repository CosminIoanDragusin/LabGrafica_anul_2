/*
Programul afiseaza un patrat pe care il translateaza
pe axa x la apasarea sagetilor stanga, dreapta
*/
#include "glos.h"
#include <glaux.h>
#include <gl.h>
#include <glu.h>
#include <glaux.h>
#include<math.h>


void myinit(void);
void CALLBACK display(void);
void CALLBACK myReshape(GLsizei w, GLsizei h);
void CALLBACK MutaStanga(void);
void CALLBACK MutaSus(void);
void CALLBACK MutaDreapta(void);
void CALLBACK MutaJos(void);
void CALLBACK rot_z_down(void);
void CALLBACK rot_z_up(void);


static GLfloat x = 0;
static GLfloat y = 0;
static GLfloat z = 0;
static GLfloat alfa = 27;
static GLdouble r = 100;
static GLdouble L = 100;
static GLdouble l = 100;
static GLdouble h = 100;
GLUquadricObj* obj;
GLUquadricObj* obj2;
GLUquadricObj* obj3;
static GLdouble slices = 100;
static GLdouble stacks = 100;


void myinit(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

void CALLBACK MutaStanga(void)
{
    x = x - 10;
}
void CALLBACK rot_z_up(void)
{
    x = x + 20;
    alfa = alfa + 50;
    y = y + 30;
}
void CALLBACK rot_z_down(void)
{
    x = x - 20;
    alfa = alfa - 50;
    y = y - 30;
}
void CALLBACK MutaSus(void)
{
    y = y + 10;
}
void CALLBACK MutaJos(void)
{
    y = y - 10;
}

void CALLBACK MutaDreapta(void)
{
    x = x + 10;
}
void CALLBACK display(void)
{

    //deseneaza un punct
    // glPointSize(10);
    //glBegin(GL_POINTS);
   // glColor3f(1.0, 1.0, 0.0);
    //glVertex2f(0, 0);

   // glEnd();


    //glRotatef(alfa, alfa+20, alfa+10, alfa+10);

    //glBegin(GL_QUADS);
    //PATRAT	
    //glColor3f (1.0, 0.0, 0.0); 
    //glVertex2f(100,100);
    //glVertex2f(150.0,100.0);
    //glVertex2f(150.0,150.0);
    //glVertex2f(100.0,150.0);
    //glEnd();
   /// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
   // glBegin(GL_TRIANGLE_FAN);
   // glColor3d(1.0, 0.0, 0.0);
  //  glVertex3d(100, 100, 100);
  //  for (int i = 0; i <= 50; i += 10) {

      //  glVertex3d(50 * cos(i * 3.14 / 180), 50 * sin(i * 3.14 / 180), 100);
     //   glVertex3d(50 * cos(i * 3.14 / 180), 50 * sin(i * 3.14 / 180), -100);
   // }
  //  glEnd();
   // glFlush();
  //  auxSwapBuffers();

   // glBegin(GL_POLYGON);    
       // glColor3f(0.0, 1.0, 0.0);
       // glVertex2f(150, 0);
       // glColor3f(0.0, 1.0, 0.0);
       // glVertex2f(250, 0);
       // glVertex2f(200, 100);
       // glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
   // glEnd();

    //glBegin(GL_TRIANGLE_FAN);
     //  glColor3f(1.0, 1.0, 1.0);
      //  glVertex2f(-125, 75);
     //   glVertex2f(-150, 0);
     //   glVertex2f(-100, 0);
    //glVertex2f(-75, 30);

   //glEnd();
    //UN PARALELIPIPED
    //   glColor3f(1, 0, 0);
  // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  // glBegin(GL_QUAD_STRIP);

  // for (int i = 0; i <= 360; i += 90) {

    //  glVertex3d(50 * cos(i * 3.14 / 180), 50 * sin(i * 3.14 / 180), 200);
   //   glVertex3d(50 * cos(i * 3.14 / 180), 50 * sin(i * 3.14 / 180), -200);
   //}
  // glEnd();


    //glBegin(GL_TRIANGLE_FAN);
     //   glColor3f(1.0, 0.5, 0.0);
     //   glVertex2f(100, 250, 0);
     //  glVertex2f(100, 0, 0);
      //  glVertex2f(300, 100, 0);
     //   glVertex2f(150, 0, 50);

  //  glEnd();

  //  glFlush();

       // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
     //  glBegin(GL_TRIANGLE_FAN);
     //   glColor3f(1.0, 1.0, 1.0);
    //    glVertex3f(0, 0, 100);
    //    for (int i = 0; i <= 360; i += 90) {
       //    glVertex3f(50 * cos(i * 3.14 / 180), 50 * sin(i * 3.14 / 180), -100);
//
     //   }

    //   glEnd();
     //   auxSwapBuffers();
    //    glFlush();
    //UN Con   
   //  glColor3f(1, 0, 0); 
  //  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  //  glBegin(GL_TRIANGLE_FAN);


   // glVertex3d(0, 0, 0);
   // for (int i = 0; i <= 360; i += 10) {

    //    glVertex3d(50 * cos(i * 3.14 / 180), 50 * sin(i * 3.14 / 180), 100);
    //    glVertex3d(50 * cos(i * 3.14 / 180), 50 * sin(i * 3.14 / 180), -100);
  //  }
  //  glEnd();
   // auxSwapBuffers();
  //  glTranslatef(x, y, 0.0);
  //  glRotatef(alfa, alfa + 20, alfa + 10, alfa + 30);
  //  glTranslatef(100, 0, 0.0);
//glColor3f(1, 0, 0);
//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//glBegin(GL_TRIANGLE_FAN);

//Un con pentru mine
//glVertex3d(0, 0, 0);
//for (int i = 0; i <= 360; i += 10) {

    //glVertex3d(50 * cos(i * 3.14 / 180), 50 * sin(i * 3.14 / 180), 100);
    //glVertex3d(50 * cos(i * 3.14 / 180), 50 * sin(i * 3.14 / 180), -100);
//}
//glEnd();
//auxSwapBuffers();

/*glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
glBegin(GL_LINE_LOOP);

glColor3d(10, 40, 50);
glVertex3d(10, 40, 50);
/*for (int i = 0; i <= 360; i += 10) {

    /*glVertex3d(50 * cos(i * 3.14 / 180), 50 * sin(i * 3.14 / 180), 100);
    glVertex3d(50 * cos(i * 3.14 / 180), 50 * sin(i * 3.14 / 180), -100);
}
glEnd();
/*auxSwapBuffers();

    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    glTranslatef(x, y, 0.0);
    glRotatef(alfa, alfa + 20, alfa + 10, alfa + 30);
    glTranslatef(100, 0, 0.0);

    /*UN PARALELIPIPED
    glColor3f(1, 0, 0);

    glBegin(GL_TRIANGLE_FAN);


    glVertex3d(0, 0, 0);
    for (int i = 0; i <= 360; i += 10) {

        glVertex3d(50 * cos(i * 3.14 / 180), 50 * sin(i * 3.14 / 180), 100);
        glVertex3d(50 * cos(i * 3.14 / 180), 50 * sin(i * 3.14 / 180), -100);
    }
    glEnd();*/

    //PIRAMIDA

    /*glColor3f(1, 0, 0);

    glBegin(GL_QUAD_STRIP);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glVertex2f(30.0, 300.0);//v1
    glVertex2f(30.0, 300.0);
    glVertex2f(0.0, 0.0);//v2
    glVertex2f(60.0,20.0);//v3   TRIANGLES

    glVertex2f(30.0,45.0);//v4
    glVertex2f(90.0,60.0);//v5

    glVertex2f(30, 300.0);//v1
    glVertex2f(30.0, 300.0);

    glEnd();*/


    /* auxSolidSphere(r);
     glTranslatef(-50, 0, 0);
     auxSolidBox(L,l,h);
     auxWireDodecahedron(l);
     auxWireTeapot(h);
     auxWireOctahedron(L);*/

     /* obj=gluNewQuadric();
      glPushMatrix();
      gluQuadricDrawStyle(obj,GLU_LINE);
      gluSphere(obj,r,slices,70);

      glTranslatef(x, y, alfa);
      glPopMatrix();*/

      //Paralelipiped bun

      /*glBegin(GL_LINE_LOOP);
      glColor3f(1.0, 0.0, 0.0);
      for (int i = 0; i <= 50; i++) {
              glVertex3f(100,20,i+10);
              glVertex3f(130, 20, i =+10);
              glVertex3f(130, 50, i =+10);
              glVertex3f(100, 50, i =+10);
              glVertex3f(100, 20, i =+10);
          }

      glEnd();*/



      //Cilindru

      /*glBegin(GL_LINE_LOOP);
      glColor3f(0.0, 0.0, 1.0);
      for (int j = 0; j <= 50; j++) {
          for (int i = 0; i <= 360; i += 10) {
              glVertex3f(25 * cos(i * 3.14 / 180), 25 * sin(i * 3.14 / 180), 100+j+10);
          }
      }

      glEnd();
      auxSwapBuffers();*/


    

    /*obj = gluNewQuadric();
    glPushMatrix();
    gluQuadricDrawStyle(obj, GLU_LINE);
    gluSphere(obj, 100, 12, 70);
    //glTranslatef(x, y, alfa);
    glPopMatrix(); */

    /*obj2 = gluNewQuadric();
    glPushMatrix();
    gluQuadricDrawStyle(obj, GLU_LINE);
    gluPartialDisk(obj, 40, 100, 100,100,60,50);
    glTranslatef(50, 50, alfa);
    glPopMatrix();*/

    //auxWireSphere();
    //glColor3f(1.0, 0.0, 0.0);
    //glTranslatef(50, 50, alfa);
    //auxWireCylinder(r, l);
    //auxWireCylinder(100, 80);

    //auxWireSphere(100);
  
   // auxWireCube(75);

glClear(GL_COLOR_BUFFER_BIT);
glRotatef(alfa, alfa + 20, alfa + 10, alfa + 10);
glLoadIdentity();

glColor3f(1.0, 1.0, 0.0);
obj2 = gluNewQuadric();

glPushMatrix();
//glTranslatef(x, y, alfa);
gluQuadricDrawStyle(obj2, GLU_LINE);
//gluCylinder(obj2, 100, 50, 170, 3, 20);
//gluSphere(obj2, 120, 30, 40);
gluCylinder(obj2, 100, 50, 170, 3, 20);
glPopMatrix();

auxSwapBuffers();



}



/*void CALLBACK myReshape(GLsizei w, GLsizei h)
{
    if (!h) return;			//transformare anizotropica, forma se modifica functie de forma(dimens) viewportului
    glViewport(0, 0, w, h);	//daca w>h stabilim ca baza inaltime, si stab unit logica de dimens in fct de h(h/320, 320 lungime lat patrat)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho (-160.0, 160.0, -160.0,
        160.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}*/

void CALLBACK myReshape(GLsizei w, GLsizei h)
{
    if (!h) return;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-320.0, 320.0, 320.0 * (GLfloat)h / (GLfloat)w,
            -320.0 * (GLfloat)h / (GLfloat)w, -100.0, 100.0);
    else
        glOrtho(-320.0 * (GLfloat)w / (GLfloat)h,
            320.0 * (GLfloat)w / (GLfloat)h, -320.0, 320.0, -100.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    auxInitDisplayMode(AUX_DOUBLE | AUX_RGB);
    auxInitPosition(0, 0, 300, 400);
    auxInitWindow("Un patrat care se translateaza pe axa x");
    myinit();
    auxKeyFunc(AUX_LEFT, MutaStanga);
    auxKeyFunc(AUX_UP, MutaSus);
    auxKeyFunc(AUX_RIGHT, MutaDreapta);
    auxKeyFunc(AUX_DOWN, MutaJos);
    auxMouseFunc(AUX_LEFTBUTTON, AUX_MOUSEDOWN, rot_z_up);
    auxMouseFunc(AUX_RIGHTBUTTON, AUX_MOUSEDOWN, rot_z_down);
    auxReshapeFunc(myReshape);
    auxMainLoop(display);
    return(0);
}
