/*
Programul afiseaza un patrat pe care il translateaza
pe axa x la apasarea sagetilor stanga, dreapta
*/
#include "glos.h"
#include <glaux.h>
#include <gl.h>
#include <glu.h>
#include <glaux.h>
#include <math.h>
#include<stdio.h>

void myinit(void);
void CALLBACK display(void);
void CALLBACK myReshape(GLsizei w, GLsizei h);
void CALLBACK MutaStanga(void);
void CALLBACK MutaDreapta(void);
void CALLBACK MutaSus(void);
void CALLBACK MutaJos(void);
void CALLBACK rot_z_up(void);
void CALLBACK rot_z_down(void);
void makeStripeImage(void);
#define stripeImageWidth 32
GLubyte stripeImage[3 * stripeImageWidth];


static GLfloat x = 0;
static GLfloat y = 0;
static GLfloat z = 0;
static GLfloat alfa = 270;
GLUquadricObj* obj;
GLUquadricObj* obj2;
GLUquadricObj* obj3;


GLfloat sgenparams[] = { 1.0, 1.0, 1.0, 0.0 };//coeficientii planului fata
// de care se calculeazã directia texturii

void makeStripeImage(void)
{ //construieste o textura 1D cu 3 octeti pentru fiecare texel
    //din 32 texeli 5 sunt rosii si 27 sunt verzi
    int j;

    for (j = 0; j < stripeImageWidth; j++) {
        stripeImage[3 * j] = (j <= 4) ? 255 : 0; //rosu
        stripeImage[3 * j + 1] = (j > 4) ? 255 : 0; //verde
        stripeImage[3 * j + 2] = 0; //galben
    }
}

void myinit(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);

    makeStripeImage();
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    //incercati si parametrul GL_DECAL. Veti constata ca nu se tine seama 
    //de iluminare
    glTexParameterf(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    //incercati si cu GL_CLAMP. Nu se repeta texturarea. Se prelungec aceeiasi
    //texel-i
    glTexParameterf(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage1D(GL_TEXTURE_1D, 0, 3, stripeImageWidth, 0,
        GL_RGB, GL_UNSIGNED_BYTE, stripeImage); //specificare texturii

    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);//incercati si GL_OBJECT_PLANE
    glTexGenfv(GL_S, GL_OBJECT_PLANE, sgenparams);	//incercati si parametrul 
    //GL_EYE_PLANE
    //ascunderea suprafeþelor
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_TEXTURE_GEN_S);//se genereaza automat coordonatele texturii pe s
    glEnable(GL_TEXTURE_1D);//texturare 1D
    //tãierea feþelor spate
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CW);
    glCullFace(GL_BACK);
    //iluminarea
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    //calcularea automata a normalelor pentru coordonate generate cu GL_MAP1_VERTEX
    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE); //normalizarea normalelor

    glMaterialf(GL_FRONT, GL_SHININESS, 100.0);//exponentul pentru strãlucire
}


void CALLBACK MutaStanga(void)
{
    x = x - 10;
}

void CALLBACK MutaDreapta(void)
{
    x = x + 10;
}

void CALLBACK MutaSus(void)
{
    y = y + 10;
}

void CALLBACK MutaJos(void)
{
    y = y - 10;
}

void CALLBACK rot_z_up(void)
{
    alfa = alfa + 30;
}

void CALLBACK rot_z_down(void) {
    alfa = alfa - 30;
}

void CALLBACK display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    //deseneaza un punct 
/**
glBegin(GL_POINTS);

    glColor3f(1.0, 0, 0); // culoare rosie

    glVertex2f(0.0, 0.0);
glEnd();

//deseneaza un poligon
glBegin(GL_POLYGON);

glColor3f(0.0, 0, 5);

glVertex2f(20, 150);
glColor3f(0, 1.0, 0.0);
glVertex2f(-29.0, 70.0);
glColor3f(0.0, 0.0, 1.0);
glVertex2f(0.0, -20.0);
glColor3f(0.0, 1.0, 0.0);
glVertex2f(40.0, 30.0);
glVertex2f(51.0, 70.0);

glEnd();


*/
  /*  glTranslatef(x, y, 0.0);
    glRotatef(alfa, alfa + 20, alfa + 10, alfa + 30);
    glTranslatef(100, 0, 0.0);
    //UN PARALELIPIPED
    glColor3f(1, 0, 0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_TRIANGLE_FAN);


    glVertex3d(0, 0, 0);
    for (int i = 0; i <= 360; i += 10) {

        //glVertex3d(50 * cos(i * 3.14 / 180), 50 * sin(i * 3.14 / 180), 100);
        glVertex3d(50 * cos(i * 3.14 / 180), 50 * sin(i * 3.14 / 180), -100);
    }
    glEnd();

    /**
    glBegin(GL_QUADS);

        glColor3f (1.0, 0.0, 0.0);
        glVertex2f(100,100);
        glColor3f (1.0, 1.0, 0.0);
        glVertex2f(150.0,100.0);
        glColor3f (0.0, 0.0, 1.0);
        glVertex2f(150.0,150.0);
        glColor3f (0.0, 1.0, 0.0);
        glVertex2f(100.0,150.0);
        glEnd();
        */
    //Punct
    glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2f(0.0, 0.0);
    glEnd();
    glPointSize(6);

    
    glRotatef(alfa, 0, 1, 0);
    
    glColor3f(1.0, 0.0, 0.0);
    obj = gluNewQuadric();
    gluQuadricDrawStyle(obj, GLU_LINE);

    glTranslatef(25, 0, 0.0);

    //cilindru 1
    glPushMatrix();
    glTranslatef(30, 0, 0.0);
    glRotatef(90, 0, 1, 0);
    glColor3f(0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.0, 0.0);
    gluCylinder(obj, 10, 10, 100, 30, 30);
    glPopMatrix();

    //cilindru 2
    glPushMatrix();
    glTranslatef(30, 0, 0.0);
    glColor3f(0.0, 1.0, 1.0);
    glTranslatef(0.0, 0.0, 0.0);
    gluCylinder(obj, 10, 10, 100, 30, 30);
    glPopMatrix();

    //cilindru 3
    glPushMatrix();
    glTranslatef(125.0, 0.0, 0.0);
    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(0.0, 0.0, 0.0);
    gluCylinder(obj, 10, 10, 100, 30, 30);
    glPopMatrix();

    //Paralelipiped
    glPushMatrix();
    glTranslatef(75.0, 0.0, 100.0);
    glRotatef(90, 0, 0, 1);
    glColor3f(1.0, 0.0, 1.0);
    auxSolidBox(10, 100, 10);
    glPopMatrix();
   

   //gluCylinder(obj, 50, 1, 71, 360, 10);//este con
   // gluCylinder(obj, 50, 1, 71, 360, 10); //semi con
   // gluCylinder(obj, 50, 50, 71, 360, 10); //cilindru
    //gluCylinder(obj, 50, 50, 71, 6, 10); //hexagon...
    //gluCylinder(obj, 50, 50, 71, 4, 10);//quad..
    //gluCylinder(obj, 50, 20, 71, 6, 10);
     //gluCylinder(obj, 50, 1, 71, 3, 10);//piramida
    //gluDisk(obj, 30, 70, 40, 20);// 
    //gluSphere(obj,100,50,30);
    /*gluCylinder(obj, 20, 20, 100, 30, 30);
    glTranslatef(15.0, 0.0, 0.0);
    //glRotatef(-90, -100, 0.0, 0);
    gluCylinder(obj2, 20, 20, 200, 30, 30);
    
    //glRotatef(90, 100.0, 0.0, 0);
    
    
    glTranslatef(-30.0, 0.0, 0.0);
   //glRotatef(-90, 50.0, 0.0, 0);
    gluCylinder(obj3, 20, 20, 200, 30, 30);
    
    glPopMatrix();*/

    

    
   
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
    auxInitPosition(500, 0, 600, 500);
    auxInitWindow("Un patrat care se translateaza pe axa x");
    myinit();
    auxKeyFunc(AUX_LEFT, MutaStanga);
    auxKeyFunc(AUX_RIGHT, MutaDreapta);
    auxKeyFunc(AUX_UP, MutaSus);
    auxKeyFunc(AUX_DOWN, MutaJos);
    auxMouseFunc(AUX_LEFTBUTTON, AUX_MOUSEDOWN, rot_z_up);
    auxMouseFunc(AUX_RIGHTBUTTON, AUX_MOUSEDOWN, rot_z_down);


    auxReshapeFunc(myReshape);
    auxMainLoop(display);
    return(0);
}
