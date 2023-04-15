 #include<stdio.h>
#include<math.h>
#include<glut.h>
int m; int p, q, r;
GLint x = 50, y = 50, xx = 0, theta = 0;
int i, j;
int s = 0; void test();
void* currentfont;
void draw_pixel(GLint cx, GLint cy) { glColor3f(0.45, 0.45, 0.45);
glBegin(GL_POINTS); glVertex2i(cx, cy);
glEnd(); 
}
void plotpixels(GLint h, GLint k, GLint x, GLint y) { draw_pixel(x + h, y + k);
draw_pixel(-x + h, y + k);
draw_pixel(x + h, -y + k);
draw_pixel(-x + h, -y + k);
draw_pixel(y + h, x + k);
draw_pixel(-y + h, x + k);
draw_pixel(y + h, -x + k);
draw_pixel(-y + h, -x + k); }
void circle_draw(GLint h, GLint k, GLint r) { GLint d = 1 - r, x = 0, y = r;
while (y > x) { plotpixels(h, k, x, y); 
if (d < 0) d += 2 * x + 3; 
else { d += 2 * (x - y) + 5; --y; }
++x; } 
plotpixels(h, k, x, y); } 
void cylinder_draw(GLint xc) { GLint r = 15, yc = 50;
circle_draw(xc, yc, r); 
circle_draw(xc + 115, yc, r);
circle_draw(xc + 185, yc, r); 
circle_draw(xc + 225, yc, r); 
circle_draw(xc + 310, yc, r); 
circle_draw(xc + 350, yc, r); 
circle_draw(xc + 57, yc, r); } 
void train(int x)
	  { glBegin(GL_POLYGON);
/* ENGINE */ 
glColor3f(1.0,0.0,0.0); 
glVertex2f(x,y); 
glVertex2f(x+165,y); 
glVertex2f(x+165,y+100);
glVertex2f(x+25,y+100); 
glVertex2f(x,y+50); 
glEnd(); glBegin(GL_POLYGON);
/*COACH 1*/
glColor3f(1.0,0.0,0.0); 
glVertex2f(x+175,y);
glVertex2f(x+282,y);
glVertex2f(x+282,y+100);
glVertex2f(x+175,y+100);
glEnd(); glBegin(GL_POLYGON); 
/*COACH 1 WINDOW */
glColor3f(0,1,1);
glVertex2f(x+245,y+60);
glVertex2f(x+270,y+60);
glVertex2f(x+270,y+85); 
glVertex2f(x+245,y+85);
glEnd(); glBegin(GL_POLYGON);
glColor3f(0,1,1);
glVertex2f(x+215,y+60);
glVertex2f(x+240,y+60);
glVertex2f(x+240,y+85);
glVertex2f(x+215,y+85); 
glEnd(); glBegin(GL_POLYGON);
/*ENGINE WINDOW */
glColor3f(0,1,1);
glVertex2f(x+25,y+50);
glVertex2f(x+50,y+50); 
glVertex2f(x+50,y+85);
glVertex2f(x+25,y+85);
glEnd(); glLineWidth(16);
glBegin(GL_LINES); 
/*FIRST JOINT*/
glColor3f(0.0,0.0,0.0);
glVertex2f(x+165,y+25);
glVertex2f(x+175,y+25);
glEnd();
glBegin(GL_LINES);
glVertex2f(x+165,y+75);
glVertex2f(x+175,y+75); 
glEnd();
glBegin(GL_POLYGON);
/*COACH 2*/
glColor3f(1.0,0.0,0.0);
glVertex2f(x+293,y);
glVertex2f(x+400,y); 
glVertex2f(x+400,y+100);
glVertex2f(x+293,y+100); 
glEnd(); glBegin(GL_LINES);
/*SECOND JOINT */
glColor3f(0.0,0.0,0.0); 
glVertex2f(x+282,y+25);
glVertex2f(x+293,y+25);
glEnd();
glBegin(GL_LINES);
glVertex2f(x+282,y+75);
glVertex2f(x+293,y+75);
glEnd();
 glBegin(GL_POLYGON);
 /*COACH2 WINDOW */
 glColor3f(0,1,1);
 glVertex2f(x+340,y+60);
 glVertex2f(x+365,y+60);
 glVertex2f(x+365,y+85); 
 glVertex2f(x+340,y+85); 
 glEnd();
 glBegin(GL_POLYGON); 
 glColor3f(0,1,1);
 glVertex2f(x+370,y+60);
 glVertex2f(x+395,y+60);
 glVertex2f(x+395,y+85); 
 glVertex2f(x+370,y+85); 
 glEnd();
 glBegin(GL_POLYGON);
 /*DOOR 1*/ 
 glColor3f(1,1,1);
 glVertex2f(x+180,y+20);
 glVertex2f(x+200,y+20); 
 glVertex2f(x+200,y+70); 
 glVertex2f(x+180,y+70); 
 glEnd();
 glBegin(GL_POLYGON);
 /*DOOR 2*/
 glColor3f(1,1,1);
 glVertex2f(x+300,y+20);
 glVertex2f(x+320,y+20); 
 glVertex2f(x+320,y+70); 
 glVertex2f(x+300,y+70);
 glEnd(); 
 glLineWidth(3.5); 
 glBegin(GL_LINES);
 /*FRONT*/
 glColor3f(0,0,0);
 glVertex2f(x,y+20); 
 glVertex2f(x-10,y+20);
 glEnd();
 glBegin(GL_LINES);
 glColor3f(0,0,0);
 glVertex2f(x,y+35);
 glVertex2f(x-10,y+35);
 glEnd(); 
 glBegin(GL_LINES);
 glColor3f(0,0,0);
 glVertex2f(x-10,y+20);
 glVertex2f(x-10,y+40); 
 glEnd();
 glBegin(GL_POLYGON); 
 /* ELECTRIC STORER*/
 glColor3f(0.0,0.0,0.0); 
 glVertex2f(x+50,y+100);
 glVertex2f(x+60,y+110); 
 glVertex2f(x+90,y+110);
 glVertex2f(x+100,y+100);
 glEnd(); 
 glFlush(); 
 glLineWidth(3.0); 
 glBegin(GL_LINE_LOOP); 
 glColor3f(0,0,0);
 glVertex2f(x+75,y+110); 
 glVertex2f(x+75,y+130);
 glVertex2f(x+130,y+180); 
 glVertex2f(x+125,y+150);
 glVertex2f(x+75,y+130); 
 glEnd();
 /*wheels spokes*/
 glLineWidth(3.0);
 /*engine 1st wheel spokes*/
 glPushMatrix();
 glTranslatef(x+25,y,0);
 glRotatef(theta,0,0,1); 
 glTranslatef(-x-25,-y,0); 
 glBegin(GL_LINES); 
 glColor3f(0.0,0.0,0.0);
 glVertex2f(x+25,y+15);
 glVertex2f(x+25,y-15); 
 glEnd(); 
 glPopMatrix(); 
 glLineWidth(3.0);
 glPushMatrix(); 
 glTranslatef(x+25,y,0);
 glRotatef(theta,0,0,1);
 glTranslatef(-x-25,-y,0); 
 glBegin(GL_LINES);
 glColor3f(0.0,0.0,0.0);
 glVertex2f(x+40,y); 
 glVertex2f(x+10,y);
 glEnd();
 glPopMatrix(); 
 glLineWidth(3.0); 
 glPushMatrix();
 glTranslatef(x+25,y,0);
 glRotatef(theta,0,0,1);
 glTranslatef(-x-25,-y,0);
 glBegin(GL_LINES);
 glColor3f(0.0,0.0,0.0);
 glVertex2f(x+16,y-12);
 glVertex2f(x+33,y+12);
 glEnd();
 glPopMatrix();
 glLineWidth(3.0);
 /*engine 2nd wheel spokes*/
 glPushMatrix(); 
 glTranslatef(x+82,y,0);
 glRotatef(theta,0,0,1);
 glTranslatef(-x-82,-y,0);
 glBegin(GL_LINES);
 glColor3f(0.0,0.0,0.0);
 glVertex2f(x+82,y+15); 
 glVertex2f(x+82,y-15);
 glEnd(); 
 glPopMatrix();
 glLineWidth(3.0);
 glPushMatrix(); 
 glTranslatef(x+82,y,0);
 glRotatef(theta,0,0,1);
 glTranslatef(-x-82,-y,0);
 glBegin(GL_LINES);
 glColor3f(0.0,0.0,0.0);
 glVertex2f(x+97,y);
 glVertex2f(x+67,y);
 glEnd(); glPopMatrix();
 glLineWidth(3.0); 
 glPushMatrix(); 
 glTranslatef(x+82,y,0);
 glRotatef(theta,0,0,1);
 glTranslatef(-x-82,-y,0); 
 glBegin(GL_LINES);
 glColor3f(0.0,0.0,0.0);
 glVertex2f(x+90,y-12); 
 glVertex2f(x+72,y+12);
 glEnd();
 glPopMatrix();
 glLineWidth(3.0);
 /*engine 3rd wheel spokes*/
 glPushMatrix();
 glTranslatef(x+140,y,0);
 glRotatef(theta,0,0,1);
 glTranslatef(-x-140,-y,0);
 glBegin(GL_LINES);
 glColor3f(0.0,0.0,0.0); 
 glVertex2f(x+140,y+15);
 glVertex2f(x+140,y-15);
 glEnd();
 glPopMatrix();
 glLineWidth(3.0);
 glPushMatrix(); 
 glTranslatef(x+140,y,0);
 glRotatef(theta,0,0,1); 
 glTranslatef(-x-140,-y,0);
 glBegin(GL_LINES);
 glColor3f(0.0,0.0,0.0);
 glVertex2f(x+125,y); 
 glVertex2f(x+155,y);
 glEnd(); glPopMatrix(); 
 glLineWidth(3.0);
 glPushMatrix(); 
 glTranslatef(x+140,y,0);
 glRotatef(theta,0,0,1); 
 glTranslatef(-x-140,-y,0); 
 glBegin(GL_LINES); 
 glColor3f(0.0,0.0,0.0);
 glVertex2f(x+132,y-12);
 glVertex2f(x+148,y+12);
 glEnd();
 glPopMatrix();
 glLineWidth(3.0);
 /*coach1 1st wheel spokes*/
 glPushMatrix();
 glTranslatef(x+210,y,0);
 glRotatef(theta,0,0,1);
 glTranslatef(-x-210,-y,0);
 glBegin(GL_LINES);
 glColor3f(0.0,0.0,0.0);
 glVertex2f(x+210,y+15);
 glVertex2f(x+210,y-15);
 glEnd(); glPopMatrix();
 glLineWidth(3.0);
 glPushMatrix(); 
 glTranslatef(x+210,y,0);
 glRotatef(theta,0,0,1);
 glTranslatef(-x-210,-y,0);
 glBegin(GL_LINES); 
 glColor3f(0.0,0.0,0.0);
 glVertex2f(x+225,y);
 glVertex2f(x+195,y);
 glEnd();
 glPopMatrix();
 glLineWidth(3.0);
 glPushMatrix(); 
 glTranslatef(x+210,y,0);
 glRotatef(theta,0,0,1); 
 glTranslatef(-x-210,-y,0);
 glBegin(GL_LINES);
 glColor3f(0.0,0.0,0.0);
 glVertex2f(x + 217, y - 12);
 glVertex2f(x + 202, y + 12);
 glEnd(); glPopMatrix();
 glLineWidth(3.0);
 /*coach1 2nd wheel spokes */
 glPushMatrix();
 glTranslatef(x+250,y,0);
 glRotatef(theta,0,0,1);
 glTranslatef(-x-250,-y,0);
 glBegin(GL_LINES); 
 glColor3f(0.0,0.0,0.0); 
 glVertex2f(x+250,y+15);
 glVertex2f(x+250,y-15);
 glEnd();
 glPopMatrix();
 glLineWidth(3.0); 
 glPushMatrix(); 
 glTranslatef(x+250,y,0);
 glRotatef(theta,0,0,1); 
 glTranslatef(-x-250,-y,0);
 glBegin(GL_LINES); 
 glColor3f(0.0,0.0,0.0);
 glVertex2f(x+265,y); 
 glVertex2f(x+235,y);
 glEnd();
 glPopMatrix();
 glLineWidth(3.0); 
 glPushMatrix(); 
 glTranslatef(x+250,y,0); 
 glRotatef(theta,0,0,1);
 glTranslatef(-x-250,-y,0);
 glBegin(GL_LINES); 
 glColor3f(0.0,0.0,0.0); 
 glVertex2f(x+240,y-12); 
 glVertex2f(x+257,y+12); 
 glEnd(); glPopMatrix(); 
 glLineWidth(3.0); 
 /*coach2 1st wheel spokes*/
 glPushMatrix();
 glTranslatef(x+335,y,0);
 glRotatef(theta,0,0,1);
 glTranslatef(-x-335,-y,0);
 glBegin(GL_LINES);
 glColor3f(0.0,0.0,0.0);
 glVertex2f(x+335,y+15);
 glVertex2f(x+335,y-15);
 glEnd(); glPopMatrix();
 glLineWidth(3.0);
 glPushMatrix(); 
 glTranslatef(x+335,y,0);
 glRotatef(theta,0,0,1);
 glTranslatef(-x-335,-y,0);
 glBegin(GL_LINES);
 glColor3f(0.0,0.0,0.0);
 glVertex2f(x+320,y);
 glVertex2f(x+350,y);
 glEnd();
 glPopMatrix(); 
 glLineWidth(3.0); 
 glPushMatrix(); 
 glTranslatef(x+335,y,0);
 glRotatef(theta,0,0,1); 
 glTranslatef(-x-335,-y,0);
 glBegin(GL_LINES);
 glColor3f(0.0, 0.0, 0.0);
 glVertex2f(x + 340, y - 12);
 glVertex2f(x + 325, y + 12);
 glEnd();
 glPopMatrix();
 glLineWidth(3.0);
 /*coach 2nd 2nd wheel spokes*/
 glPushMatrix();
 glTranslatef(x+375,y,0);
 glRotatef(theta,0,0,1);
 glTranslatef(-x-375,-y,0); 
 glBegin(GL_LINES);
 glColor3f(0.0,0.0,0.0);
 glVertex2f(x+375,y+15);
 glVertex2f(x+375,y-15); 
 glEnd(); glPopMatrix();
 glLineWidth(3.0);
 glPushMatrix();
 glTranslatef(x+375,y,0); 
 glRotatef(theta,0,0,1); 
 glTranslatef(-x-375,-y,0);
 glBegin(GL_LINES); 
 glColor3f(0.0,0.0,0.0);
 glVertex2f(x+360,y);
 glVertex2f(x+390,y);
 glEnd();
 glPopMatrix();
 glLineWidth(3.0);
 glPushMatrix();
 glTranslatef(x+375,y,0);
 glRotatef(theta,0,0,1); 
 glTranslatef(-x-375,-y,0); 
 glBegin(GL_LINES);
 glColor3f(0.0,0.0,0.0);
 glVertex2f(x+365,y-12); 
 glVertex2f(x+380,y+12);
 glEnd(); glPopMatrix();
 glFlush(); } 
 void electricwire() { glBegin(GL_LINES);
 glColor3f(0,0,0);
 glVertex2f(-1000,200);
 glVertex2f(5000,200);
 glEnd();
 glBegin(GL_LINES);
 glColor3f(0,0,0); 
 glVertex2f(-1000,230); 
 glVertex2f(5000,230); 
 glEnd(); glFlush(); } 
 void track() { glBegin(GL_LINES);
 glColor3f(0,0,0); 
 glVertex2f(-1000,35);
 glVertex2f(5000,35); 
 glEnd();
 glBegin(GL_LINES); 
 glColor3f(0,0,0);
 glVertex2f(-1000, 45);
	  glVertex2f(5000,45);
	  glEnd();
 int i;
 glPointSize(8); 
 glBegin(GL_LINES);
 glColor3f(0, 0, 0);
 for (i = -3000; i <= 5000; i = i + 10)
 {
	 glVertex2f(i, 35); glVertex2f(i, 45); 

 }
 glEnd();
 }
 void sky()
 { glBegin(GL_POLYGON);
 glColor3f(0, 1, 1); 
 glVertex2f(0, 230); 
 glVertex2f(0, 700);
 glVertex2f(700, 700);
 glVertex2f(700, 230);
 glEnd(); 
 } 
 void road() 
 { glColor3f(0.0, 0.9, 0.0);
 glBegin(GL_POLYGON); 
 glVertex2f(0, 200);
 glVertex2f(0, 12);
 glVertex2f(10000, 12);
 glVertex2f(10000, 200); 
 glEnd(); }
 void myinit() 
 { glMatrixMode(GL_PROJECTION);
 glClearColor(1.0, 1.0, 1.0, 1.0);
 glColor3f(1.0, 0.0, 0.0);
 glLoadIdentity(); 
 gluOrtho2D(0, 499, 0, 499);
 } 
 void mykey(unsigned char key, int x, int y)
 { int i; if (key == 'M' || key == 'm') 
 { for (i = 0; i < 1000000000; i++);
 glutPostRedisplay();
 }
 }
 void setFont(void* font) 
 { currentfont = font; } 
 /*IT IS USED ACCEPT A STRING*/
 void drawstring(float p,float q,float r,char *string) 
 { char *c; glRasterPos3f(p,q,r);
 for(c=string;*c!='0';c++)
 { glColor3f(0.0,1.0,0.0);
 glutBitmapCharacter(currentfont,*c); }
 } void display()
 {
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); glPushMatrix(); test(); sky(); road(); track(); electricwire(); //stop(); glColor3f(1.0,0.0,0.0); glPointSize(3.0); glTranslated(-xx,0,0); train(50); train(750); train(1450); train(2150); train(2850); train(3550); cylinder_draw(75); cylinder_draw(775); cylinder_draw(1475); cylinder_draw(2175); cylinder_draw(2875); cylinder_draw(3575); glPopMatrix(); glutSwapBuffers(); } void test() { glColor3f(1,0,0); setFont(GLUT_BITMAP_TIMES_ROMAN_24); drawstring(5800,5300,0,"BIHARSHARIF STATION"); glFlush(); } void idle() { xx+=2; theta+=2; glutPostRedisplay(); } int main(int argc,char** argv) { glutInit(&argc,argv); glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB); glutInitWindowSize(700,700); glutInitWindowPosition(0,0); glutCreateWindow("The Running Train"); glutDisplayFunc(display); glutKeyboardFunc(mykey); glutIdleFunc(idle); myinit(); glutMainLoop(); return 0; }