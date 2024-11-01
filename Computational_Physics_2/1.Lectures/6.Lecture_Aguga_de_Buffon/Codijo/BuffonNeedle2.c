// http://fracton.khu.ac.kr/~syook/Lectures/ComputPhys/
//http://fracton.khu.ac.kr/~syook/Lectures/ComputPhys/C/NumCalculus/BuffonNeedle2.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
//#include <GLUT/GLUT.h>

#include <GL/gl.h>    // for windows dep. on the configuration of OpenGL
#include <GL/glu.h>
#include <GL/glut.h>

#define PI 3.141592
#define WWIDTH 640
#define WHEIGHT 480
#define RDX 20.0
#define LDX RDX
#define UDY 30.0
#define LDY 100.0
#define BBDX 10.0
#define B1HEIGHT (WHEIGHT-(UDY+LDY))
#define B2HEIGHT B1HEIGHT
#define B1WIDTH ((WWIDTH-(RDX+BBDX+LDX))/2.0)
#define B2WIDTH B1WIDTH

#define ADX (20.0)
#define ADY (20.0)
#define DN 200

int myInit(void);
void myDisplay(void);
void myDisplay2(void);
void drawString (void *, char *);
void drawXAxies(double,double,double,double,double);
void drawYAxies(double,double,double,double,double);
void drawLine(double,double,double,double,double);
void myKey(unsigned char,int,int);
void myReshape(int,int);
int throw_needles();

int gnneedles,gncross,gi;
int gchkflag;
double gell;

int main (int argc,char * argv[])
{
	glutInit(&argc,argv);  // initialize the glut toolkit
	//glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);  // set display mode
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // set display mode
	glutInitWindowSize(WWIDTH,WHEIGHT);  // set the size of a window
	glutInitWindowPosition(100,150);  // set the position of the window
	glutCreateWindow("Bisection Method");  // create the window
	
	myInit();
	
	glutDisplayFunc(myDisplay);  //register redraw function
	//glutReshapeFunc(myReshape); // For reshaping...changing the height and/or width
	glutKeyboardFunc(myKey);
	glutMainLoop();  // go into a perpetual loop
	return 0;
}

void myReshape(int w,int h)
{
	glViewport (0, 0, w, h);
	glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluOrtho2D (0,w,0,h);
	glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void myKey(unsigned char key,int x,int y)
{
	switch(key){
		case 27:
		case 'q':
		case 'Q':
			exit(0);
			break;
		case 'n':
			gchkflag=1;
			throw_needles();
			//glutPostRedisplay();  // Location of this is very crucial!!!!
			break;
	}
}

int myInit(void)
{
 	//glClearColor(1.0,1.0,1.0,0.0);   // set white background color
	glClearColor(0.0,0.0,0.0,0.0);   // set balck background color
	//glColor3f(0.0f,0.0f,0.0f);  // set the color of drawing object
	glPointSize(3.0);
	glMatrixMode(GL_PROJECTION);   // set the matrix mode as a projection matrix
	glLoadIdentity();  // initialize the prjection matrix with identity matrix
	gluOrtho2D(0.0,640.0,0.0,480.0);  // create orthogonal projection matrix
	gnneedles=DN;
	gncross=0;
	gchkflag=0;
	gi=0;
	srand((unsigned)time(NULL));
	return 1;
}

void myDisplay(void)
{
	char label[100];
  int i;
	double bx,by;
	
	double hxl,hxr,hyl,hyr,vxt,vxb,vyt,vyb;
	double tdx,tdy;
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	// Draw Box for Needle: Box1
	bx=LDX;
	by=LDY;
	glColor3f(0.0,1.0,0.0);
	glLineWidth(3.0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(bx,by);
		glVertex2f(bx+B1WIDTH,by);
		glVertex2f(bx+B1WIDTH,by+B1HEIGHT);
		glVertex2f(bx,by+B1HEIGHT);
	glEnd();
	
	// Draw H-bars in Box1
	gell=B1HEIGHT/2.0;
	bx=LDX;
	by=LDY+gell/2.0;
	glColor3f(1.0,1.0,1.0);
	glLineWidth(3.0);
	glBegin(GL_LINES);
		glVertex2f(bx,by);
		glVertex2f(bx+B1WIDTH,by);
	glEnd();
	by+=gell;
	glBegin(GL_LINES);
		glVertex2f(bx,by);
		glVertex2f(bx+B1WIDTH,by);
	glEnd();
	
	// Draw Box for Graph: Box2
	bx=LDX+B1WIDTH+BBDX;
	by=LDY;
	glColor3f(0.0,1.0,0.0);
	glLineWidth(3.0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(bx,by);
		glVertex2f(bx+B2WIDTH,by);
		glVertex2f(bx+B2WIDTH,by+B2HEIGHT);
		glVertex2f(bx,by+B2HEIGHT);
	glEnd();
	
	// write down the given function on the window
	glColor3f(1.0,1.0,1.0);
	sprintf(label,"Buffon's needle");
	glRasterPos2f((double)WWIDTH/2.5,(double)WHEIGHT-UDY+10);
	drawString(GLUT_BITMAP_HELVETICA_18,label);
	
	glColor3f(0.0,1.0,1.0);
	sprintf(label,"press 'n' for the next step. / press 'Esc', 'q' or 'Q' to quit this program.");
	glRasterPos2f(0,0);
	drawString(GLUT_BITMAP_HELVETICA_10,label);
	
	glColor3f(1.0,1.0,0.0);
	sprintf(label,"(c) S.-H. Yook");
	glRasterPos2f(0,WHEIGHT-10);
	drawString(GLUT_BITMAP_HELVETICA_10,label);
	
	// Axis coordinates for horizontal line
	hxl=LDX+B1WIDTH+BBDX; 
	hxr=(hxl+B2WIDTH); 
	hyl=hyr=LDY+ADY; 
	// Axis cooridnates for vertical line
	vxt=vxb=LDX+B1WIDTH+BBDX+ADX;
	vyt=LDY+B2HEIGHT;
	vyb=LDY;
	tdx=(B2WIDTH-ADX)/(5.0);
	tdy=(B2HEIGHT-ADX)/(4.0);
	glColor3f(0.0f,1.0f,1.0);
	drawXAxies(hxl,hyl,hxr,hyr,tdx);
	drawYAxies(vxt,vyt,vxb,vyb,tdy);
	throw_needles();
	glFlush();
	//glutSwapBuffers();
}

int throw_needles()
{
	double x,y,theta;
	double pxl,pxr,pyl,pyr,pxc,pyc,pdx,pdy;
	double pbyt,pbyl;
	double pi,p;
	double px,py;
	char label[256];
	
	if(gchkflag){
		pbyl=LDY+gell/2.0;  //location of bars
		pbyt=pbyl+gell;
		glColor3f(1.0,1.0,0.5);
		for(;gi<gnneedles;gi++){
			// draw needles in Box1
			x=B1WIDTH/2.0;
			y=(double)rand()/(double)RAND_MAX;
			theta=PI*(double)rand()/(double)RAND_MAX;
			pdx=cos(theta)*gell/2.0;
			pdy=gell*sin(theta)/2.0;
			pxc=x+LDX;
			pyc=gell*y+LDY+gell/2.0;
			pxl=pxc-pdx;
			pyl=pyc-pdy;
			pxr=pxc+pdx;
			pyr=pyc+pdy;
			drawLine(pxl,pyl,pxr,pyr,1.0);
			if(pyl<=pbyl || pyl>=pbyt || pyr<=pbyl || pyr>=pbyt){
				gncross++;
			}
		}
		printf("[num. of crossed needles]/[tot. num. of needles]=%d / %d\n",gncross,gnneedles);
		p=(double)(gncross)/(double)gnneedles;
		pi=2.0/p;
		printf("pi=%lf\n",pi);
		px=gnneedles*(B2WIDTH-ADX)/20000.0+RDX+B1WIDTH+BBDX+ADX;
		py=pi*(B2HEIGHT-ADY)/4.0+LDY+ADY;
		glColor3f(1.0,0.0,0.0);
		glBegin(GL_POINTS);
			glVertex2f(px,py);
		glEnd();
		gnneedles+=DN;
		gchkflag=0;
		if(gnneedles>20000) exit(1);
		//glutPostRedisplay();
		glFlush();
	}
	return 1;
}

void drawXAxies(double x1,double y1,double x2,double y2,double tdx)
{
	int i,nticks;
	double tx1,tx2,ty1,ty2,tdy;
	char label[100];
	
	drawLine(x1,y1,x2,y2,3.0);
	//draw ticks
	nticks=6;   // 0~10000, separated by 2000
	tdy=5.0;
	for(i=0;i<nticks;i++){
		tx2=tx1=(double)i*tdx+LDX+B1WIDTH+BBDX+ADX;
		ty1=y1-tdy;
		ty2=y1+tdy;
		drawLine(tx1,ty1,tx2,ty2,3.0);
		glRasterPos2f(tx1-10,ty1-12.0);
		sprintf(label,"%.0lf",4000*(double)i);
		drawString(GLUT_BITMAP_HELVETICA_12,label);
	}
}

void drawYAxies(double x1,double y1,double x2,double y2,double tdy)
{
	int i,nticks;
	double tx1,tx2,ty1,ty2,tdx;
	double pixl,pixr,piy;
	char label[100];
	
	drawLine(x1,y1,x2,y2,3.0);
	
	nticks=4+1;  // 0~4, separated by 1
	tdx=5.0;
	for(i=0;i<nticks;i++){
		tx1=x1-tdx;
		tx2=x1+tdx;
		ty2=ty1=(double)i*tdy+(ADY+LDY);
		drawLine(tx1,ty1,tx2,ty2,3.0);
		glRasterPos2f(tx1-15,ty1-4);
		sprintf(label,"%.1lf",(double)(i));
		drawString(GLUT_BITMAP_HELVETICA_12,label);
	}
	
	// draw a guide line for PI
	pixl=LDX+B1WIDTH+BBDX+ADX;
	pixr=pixl+B2WIDTH-ADX;
	piy=(B2HEIGHT-ADY)*PI/4.0+ADY+LDY;
	glLineWidth(2.0);
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_LINES);
		glVertex2f(pixl,piy);
		glVertex2f(pixr,piy);
	glEnd();
}

void drawLine(double x1,double y1,double x2,double y2,double lwidth)
{
	glLineWidth(lwidth);
	glBegin(GL_LINES);
		glVertex2f(x1,y1);
		glVertex2f(x2,y2);
	glEnd();
}

void drawString (void *font,char *s)
{
  unsigned int i;
	
	//glDisable(GL_TEXTURE_2D);
  for (i = 0; i < strlen (s); i++)
    glutBitmapCharacter (font, s[i]);
	//glEnable(GL_TEXTURE_2D);
}
