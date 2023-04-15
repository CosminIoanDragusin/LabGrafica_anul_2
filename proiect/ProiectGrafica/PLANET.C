/*
 *  planet.c
 *  Programul arata cum se compun transformarile de rotatie si de translatie
 *  pentru desenarea obiectelor rotite sau translatate.
 *  Interactiune:  left, right, up, down 
 *  
 */
#include "glos.h"

#include <gl.h>
#include <glu.h>
#include <glaux.h>

void myinit(void);
void drawPlane(void);
void CALLBACK dayAdd (void);
void CALLBACK daySubtract (void);
void CALLBACK yearAdd (void);
void CALLBACK yearSubtract (void);
void CALLBACK lunaDayAdd(void);
void CALLBACK lunaDaySubtract(void);
void CALLBACK lunaYearAdd(void);
void CALLBACK lunaYearSubtract(void);
void CALLBACK display(void);
void CALLBACK myReshape(GLsizei w, GLsizei h);

static int year = 0, day = 0;
static int lunayear = 0, lunaday = 0;

void CALLBACK dayAdd (void)
{
    day = (day + 10) % 360;
}

void CALLBACK daySubtract (void)
{
    day = (day - 10) % 360;
}

void CALLBACK yearAdd (void)
{
    year = (year + 5) % 360;
}

void CALLBACK yearSubtract (void)
{
    year = (year - 5) % 360;
}

//pentru luna

void CALLBACK lunaDayAdd(void)
{
    
    lunaday = (lunaday + 20) % 360;
}

void CALLBACK lunaDaySubtract(void)
{
    lunaday = (lunaday - 20) % 360;
}

void CALLBACK lunaYearAdd(void)
{
    lunayear = (lunayear + 25) % 360;
}

void CALLBACK lunaYearSubtract(void)
{
    lunayear = (lunayear - 25) % 360;
}


void CALLBACK display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f (1.0, 1.0, 1.0);
    glPushMatrix();//pentru a nu iesi obiectele din fereastra la reapelarea functiei display()

/*  SOARELE    */
    auxWireSphere(1.0);

/*  Pamantul */
    glRotatef ((GLfloat) year, 0.0, 1.0, 0.0);
    glTranslatef (2.0, 0.0, 0.0);
    glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
    auxWireSphere(0.2);
    
    /*Luna    */
    
    glRotatef((GLfloat)lunayear, 0.0, 1.0, 0.0);
    glTranslatef(0.5, 0.0, 0.0);
    glRotatef((GLfloat)lunaday, 0.0, 1.0, 0.0);
    auxWireSphere(0.1);
    glPopMatrix();
   
    glFlush();
}

void myinit (void) {
    glShadeModel (GL_FLAT);
}

void CALLBACK myReshape(GLsizei w, GLsizei h)
{
    if (!h) return;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef (0.0, 0.0, -5.0);
}


int main(int argc, char** argv)
{
    auxInitDisplayMode (AUX_SINGLE | AUX_RGB);
    auxInitPosition (0, 0, 500, 500);
    auxInitWindow ("Composite Modeling Transformations");
    myinit ();
    auxKeyFunc (AUX_LEFT, yearSubtract);
    auxKeyFunc (AUX_RIGHT, yearAdd);
    auxKeyFunc (AUX_UP, dayAdd);
    auxKeyFunc (AUX_DOWN, daySubtract);
    auxKeyFunc(AUX_a, lunaYearSubtract);
    auxKeyFunc(AUX_d, lunaYearAdd);
    auxKeyFunc(AUX_w, lunaDayAdd);
    auxKeyFunc(AUX_s, lunaDaySubtract);
    auxReshapeFunc (myReshape);
    auxMainLoop(display);
    return(0);
}
