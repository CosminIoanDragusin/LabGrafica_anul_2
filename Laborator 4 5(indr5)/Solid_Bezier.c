/*  Solid_Bezier.c
 *  Programul afiseaza o suprafata Bezier folosind 
 *  evaluatori bidimensionali
 */
#include "glos.h"

#include <gl.h>
#include <glu.h>
#include <glaux.h>

void myinit(void);
void initlights(void);
void CALLBACK myReshape(GLsizei w, GLsizei h);
void CALLBACK display(void);
// tabloul ctrlpoints defineste cele 16 puncte de control ale suprafetei
/*GLfloat ctrlpoints[4][4][3] = {
    {{-1.5, -1.5, 4.0}, {-0.5, -1.5, 2.0}, 
    {0.5, -1.5, -1.0}, {1.5, -1.5, 2.0}}, 
    {{-1.5, -0.5, 1.0}, {-0.5, -0.5, 3.0}, 
    {0.5, -0.5, 0.0}, {1.5, -0.5, -1.0}}, 
    {{-1.5, 0.5, 4.0}, {-0.5, 0.5, 0.0}, 
    {0.5, 0.5, 3.0}, {1.5, 0.5, 4.0}}, 
    {{-1.5, 1.5, -2.0}, {-0.5, 1.5, -2.0}, 
    {0.5, 1.5, 0.0}, {1.5, 1.5, -1.0}}
};*/
GLfloat ctrlpoints[4][4][3] = {
    { { 0.0, 0.0, 0.0 }, { 0.0, 1.0, 0.0 },
    { 0.0, 2.0, 0.0 }, { 0.0, 3.0, 0.0 } },
    { { 1.0, 0.0, 0.0 }, { 1.0, 1.0, 4.0 },
    { 1.0, 2.0, 4.0 }, { 1.0, 3.0, 0.0 } },
    { { 2.0, 0.0, 0.0 }, { 2.0, 1.0, 4.0 },
    { 2.0, 2.0, 4.0 }, { 2.0, 3.0, 0.0 } },
    { { 3.0, 0.0, 0.0 }, { 3.0, 1.0, 0.0 },
    { 3.0, 2.0, 0.0 }, { 3.0, 3.0, 0.0 } },
    
};
GLfloat ctrlpoints2[4][4][3] = {
    { { 0.0, 0.0, 0.0 }, { 0.0, 1.0, 0.0 },
    { 0.0, 2.0, 0.0 }, { 0.0, 3.0, 0.0 } },
    { { 1.0, 0.0, 0.0 }, { 1.0, 1.0, 4.0 },
    { 1.0, 2.0, 4.0 }, { 1.0, 3.0, 0.0 } },
    { { 2.0, 0.0, 0.0 }, { 2.0, 1.0, 4.0 },
    { 2.0, 2.0, 4.0 }, { 2.0, 3.0, 0.0 } },
    { { 3.0, 0.0, 0.0 }, { 3.0, 1.0, 0.0 },
    { 3.0, 2.0, 0.0 }, { 3.0, 3.0, 0.0 } },

};
// setari pentru iluminarea suprafetei
void initlights(void)
{
    GLfloat ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat position[] = { 0.0, 0.0, 2.0, 1.0 };
    GLfloat mat_diffuse[] = { 0.6, 0.6, 0.6, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void CALLBACK display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotatef(85.0, 1.0, 1.0, 1.0);
    glEvalMesh2(GL_FILL, 0, 20, 0, 20); // specifica modul
	// de redare al poligoanelor (GL_FILL, GL_POINT, GL_LINE, 
	// si intervalele de esantionare a suprafetei pentru u si v
    glPopMatrix();

    glPushMatrix();

    glEvalMesh2(GL_FILL, 0, 20, 0, 20);

    glPopMatrix();
    glFlush();
}

void myinit(void)
{
    glClearColor (0.0, 0.0, 0.0, 1.0);
    glEnable (GL_DEPTH_TEST); // se activeaza ascunderea suprafetelor
	/*	 functia glMap2f defineste caracteristicile suprafetei Bezier
	- tipul punctelor determinate de functia glEvalCoord2f
	- intervalul de variatie al parametrului u (0 -1 in acest caz)
	- intervalul valorilor in tabloul ctrlpoints intre doua puncte
	de control pe directia u
	- numarul punctelor de control pe directia u
	- intervalul de variatie al parametrului v (0 -1 in acest caz)
	- intervalul valorilor in tabloul ctrlpoints intre doua puncte
	de control pe directia v
	- numarul punctelor de control pe directia v
	-tabloul punctelor de control
*/
    


   
}

void CALLBACK myReshape(GLsizei w, GLsizei h)
{
    if (!h) return;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
    glOrtho(-4.0, 4.0, -4.0*(GLfloat)h/(GLfloat)w, 
        4.0*(GLfloat)h/(GLfloat)w, -4.0, 4.0);
    else
    glOrtho(-4.0*(GLfloat)w/(GLfloat)h, 
        4.0*(GLfloat)w/(GLfloat)h, -4.0, 4.0, -4.0, 4.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    auxInitDisplayMode (AUX_SINGLE | AUX_RGB | AUX_DEPTH16);
    auxInitPosition (0, 0, 500, 500);
    auxInitWindow ("Suprafata Bezier cu iluminare si atribut de umplere pe poligoane");
    myinit();
    auxReshapeFunc (myReshape);
    auxMainLoop(display);
    return(0);
}
