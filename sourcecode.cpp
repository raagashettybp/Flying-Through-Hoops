#include<stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include<string.h>
#include<bits/stdc++.h>  //Header file that includes all the standard library
#define rad (3.1416/180)
#define EN_SIZE 20
#include "RGBpixmap.cpp"
#pragma GCC diagnostic ignored "-Wwrite-strings" //to disable warnings

using namespace std;
RGBpixmap pix[6];
float zoom=4;
int tola[5000][5000];
float tX=0,tY=0,tZ=-8,rX=0,rY=0,rZ=4;
float tZ1=-20,tZ2=-40,tZ3=-60,tZ4=-80,tZ5=-100,tZ6=-120;
float rotX=0,rotY=0,rotZ=0;
float cosX=0,cosY=1,cosZ=0;
float angle=0;
float xEye=0.0f,yEye=5.0f,zEye=30.0f;
float cenX=0,cenY=0,cenZ=0,roll=0;
float radius=0;
float theta=0,slope=0;
float speed = 0.5;
float angleBackFrac = 0.2;
bool saheedMinarVisible = false;
float r[] = {0.1,0.4,0.0,0.9,0.2,0.5,0.0,0.7,0.5,0.0};
float g[] = {0.2,0.0,0.4,0.5,0.2,0.0,0.3,0.9,0.0,0.2};
float b[] = {0.4,0.5,0.0,0.7,0.9,0.0,0.1,0.2,0.5,0.0};
int TIME=0;
bool START = false;
float torusPosX[7] = {1,-2,3,-4,-2,0,2};
float torusPosY[7] = {2,3,10,6,7,4,1};
bool rot = false;
int i = 0,f=0;

void output(int x, int y, char *string,void *font)
{
	int len, i;
	glRasterPos2f(x, y);
	len = (int) strlen(string);
	for (i = 0; i < len; i++)
	{
		glutBitmapCharacter(font, string[i]);
	}
}

static void resize(int width, int height)
{
	const float ar = (float) width / (float) height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void drawPillar1()
{
	glColor3d(0.4,0.2,0.2);
	glPushMatrix();
	glTranslated(0,1.55,0);
	glScaled(2,0.05,1.5);
	glutSolidCube(1);
	glPopMatrix();
	
	glColor3d(0.4,0.2,0.2);
	glPushMatrix();
	glTranslated(0,1.6,0);
	glScaled(1.9,0.05,1.4);
	glutSolidCube(1);
	glPopMatrix();
	
	glColor3d(0.4,0.2,0.2);
	glPushMatrix();
	glTranslated(0,1.65,0);
	glScaled(1.8,0.05,1.3);
	glutSolidCube(1);
	glPopMatrix();
	
	/// pataton
	glColor3d(1,1,1);
	glPushMatrix();
	glTranslated(0,1.68,-0.4);
	glScaled(0.5,0.02,0.08);
	glutSolidCube(1);
	glPopMatrix();
	
	/// Piller
	glPushMatrix();
	glTranslated(0,1.99,-0.4);
	glScaled(0.06,0.7,0.04);
	glutSolidCube(1);
	glPopMatrix();
	
	/// ROD
	glColor3d(0,0,0);
	glPushMatrix();
	glTranslated(0.07,1.99,-0.4);
	glScaled(0.003,0.7,0.003);
	glutSolidCube(1);
	glPopMatrix();
	 
	glPushMatrix();
	glTranslated(0.11,1.99,-0.4);
	glScaled(0.003,0.7,0.003);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0.15,1.99,-0.4);
	glScaled(0.003,0.7,0.003);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.22,0,0);
	glPushMatrix();
	glTranslated(0.07,1.99,-0.4);
	glScaled(0.003,0.7,0.003);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0.11,1.99,-0.4);
	glScaled(0.003,0.7,0.003);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0.15,1.99,-0.4);
	glScaled(0.003,0.7,0.003);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
	
	///Horizontal rod
	glPushMatrix();
	glTranslated(2.2,0,-0.1);
	glScaled(4.2,1,1);
	glColor3d(0,0,0);
	glPushMatrix();
	glTranslated(-0.528,1.85,-0.3);
	glScaled(0.1,0.003,0.003);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.528,2.02,-0.3);
	glScaled(0.1,0.003,0.003);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.528,2.18,-0.3);
	glScaled(0.1,0.003,0.003);
	glutSolidCube(1);
	glPopMatrix();
	glColor3d(1,1,1);
	glPopMatrix();
	
	/// ROD END
	glColor3d(1,1,1);
	glPushMatrix();
	glTranslated(-0.22,1.99,-0.4);
	glScaled(0.06,0.7,0.04);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0.22,1.99,-0.4);
	glScaled(0.06,0.7,0.04);
	glutSolidCube(1);
	glPopMatrix();
	
	//pillar left 2
	glPushMatrix();
	glTranslated(0.65,0,0.3);
	glRotated(-45,0,1,0);
	glPushMatrix();
	glTranslated(-0.605,1.94,-0.3);
	glScaled(0.045,0.65,0.03);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.45,1.94,-0.3);
	glScaled(0.045,0.65,0.03);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.528,2.258,-0.3);
	glScaled(0.199,0.04,0.03);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.528,1.68,-0.3);
	glScaled(0.199,0.02,0.06);
	glutSolidCube(1);
	glPopMatrix();
	
	///ROD
	glColor3d(0,0,0);
	glPushMatrix();
	glTranslated(-0.64,-0.05,0.1);
	glScaled(1,1.02,1);
	glPushMatrix();
	glTranslated(0.078,1.99,-0.4);
	glScaled(0.003,0.56,0.003);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0.11,1.99,-0.4);
	glScaled(0.003,0.56,0.003);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0.145,1.99,-0.4);
	glScaled(0.003,0.56,0.003);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
	glColor3d(1,1,1);
	
	///Horizontal rod
	glColor3d(0,0,0);
	glPushMatrix();
	glTranslated(-0.528,1.85,-0.3);
	glScaled(0.1,0.003,0.003);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.528,2,-0.3);
	glScaled(0.1,0.003,0.003);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.528,2.15,-0.3);
	glScaled(0.1,0.003,0.003);
	glutSolidCube(1);
	glPopMatrix();
	glColor3d(1,1,1);
	glPopMatrix();
	
	///small pillars
	glPushMatrix();
	
	// pillar left 1
	glTranslated(0.06,0,0.14);
	glPushMatrix();
	glTranslated(-0.2,0,-0.31);
	glRotated(45,0,1,0);
	glPushMatrix();
	glTranslated(-0.605,1.88,-0.3);
	glScaled(0.045,0.4,0.03);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.45,1.88,-0.3);
	glScaled(0.045,0.4,0.03);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.528,2.08,-0.3);
	glScaled(0.2,0.04,0.03);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.528,1.68,-0.3);
	glScaled(0.199,0.02,0.06);
	glutSolidCube(1);
	glPopMatrix();
	
	///ROD
	glColor3d(0,0,0);
	glPushMatrix();
	glTranslated(-0.641,0.43,0.1);
	glScaled(1,0.73,1);
	glPushMatrix();
	glTranslated(0.078,1.99,-0.4);
	glScaled(0.003,0.56,0.003);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0.11,1.99,-0.4);
	glScaled(0.003,0.56,0.003);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0.145,1.99,-0.4);
	glScaled(0.003,0.56,0.003);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
	
	///Horizontal rod
	glColor3d(0,0,0);
	glPushMatrix();
	glTranslated(-0.528,1.8,-0.3);
	glScaled(0.1,0.003,0.003);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.528,1.96,-0.3);
	glScaled(0.1,0.003,0.003);
	glutSolidCube(1);
	glPopMatrix();
	glColor3d(1,1,1);
	
	///ROD
	glPopMatrix();
	
	/// Circle
	glColor3d(1,0,0);
	glPushMatrix();
	glTranslated(0,2.1,-0.44);
	glScaled(0.35,0.35,0.01);
	glutSolidSphere(1,50,50);
	glPopMatrix();
	glColor3d(0,0,0);
	glPushMatrix();
	glTranslated(-0.18,1.9,-0.45);
	glScaled(0.01,0.5,0.01);
	glutSolidCube(1);
	glPopMatrix();
	glColor3d(0,0,0);
	glPushMatrix();
	glTranslated(0.18,1.9,-0.45);
	glScaled(0.01,0.5,0.01);
	glutSolidCube(1);
	glPopMatrix();
}

void plane()
{
	const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
	double a = t*90.0;
	
	/// Main body
	glColor3d(0.5,1,0);
	glPushMatrix();
	glTranslated(0,0,0);
	glScaled(3,0.4,0.5);
	glutSolidSphere(1,30,30);
	glPopMatrix();
	glColor3d(0,0,0);
	glPushMatrix();
	glTranslated(1.7,0.1,0);
	glScaled(1.5,0.7,0.8);
	glRotated(40,0,1,0);
	glutSolidSphere(0.45,30,30);
	glPopMatrix();
	
	///Right
	glColor3d(0.8,1,0);
	glPushMatrix();
	glTranslated(0,0,1.2);
	glRotated(-50,0,1,0);
	glScaled(0.7,0.1,3);
	glRotated(25,0,1,0);
	glutSolidCube(1);
	glPopMatrix();
	glColor3d(0.8,1,0);
	glPushMatrix();
	glTranslated(-0.3,-0.15,1.5);
	glRotated(90,0,1,0);
	glScaled(0.1,0.1,0.9);
	glutSolidTorus(0.5,0.5,50,50);
	glPopMatrix();
	glColor3d(0.8,1,0);
	glPushMatrix();
	glTranslated(0.2,-0.15,0.9);
	glRotated(90,0,1,0);
	glScaled(0.1,0.1,0.9);
	glutSolidTorus(0.5,0.5,50,50);
	glPopMatrix();
	
	///Left
	glColor3d(0.8,1,0);
	glPushMatrix();
	glTranslated(0,0,-1.2);
	glRotated(50,0,1,0);
	glScaled(0.7,0.1,3);
	glRotated(-25,0,1,0);
	glutSolidCube(1);
	glPopMatrix();
	glColor3d(0.8,1,0);
	glPushMatrix();
	glTranslated(-0.3,-0.15,-1.5);
	glRotated(90,0,1,0);
	glScaled(0.1,0.1,0.9);
	glutSolidTorus(0.5,0.5,50,50);
	glPopMatrix();
	glColor3d(0.8,1,0);
	glPushMatrix();
	glTranslated(0.2,-0.15,-0.9);
	glRotated(90,0,1,0);
	glScaled(0.1,0.1,0.9);
	glutSolidTorus(0.5,0.5,50,50);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-2.8,0,0);
	glScaled(0.8,0.5,0.3);
	
	///Right
	glColor3d(0.8,1,0);
	glPushMatrix();
	glTranslated(0.4,0,1.5);
	glRotated(-30,0,1,0);
	glScaled(0.7,0.1,3);
	glRotated(10,0,1,0);
	glutSolidCube(1);
	glPopMatrix();
	
	///left
	glColor3d(0.8,1,0);
	glPushMatrix();
	glTranslated(0.4,0,-1.5);
	glRotated(30,0,1,0);
	glScaled(0.7,0.1,3);
	glRotated(-10,0,1,0);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
	
	/// upper
	glColor3d(0.8,1,0);
	glPushMatrix();
	glTranslated(-2.7,0.5,0);
	glRotated(45,0,0,1);
	glScaled(0.8,2,0.1);
	glRotated(-20,0,0,1);
	glutSolidCube(0.5);
	glPopMatrix();
}
	
void singleHouse(int R,int G,int B)
{
	glColor3d(r[R%11],g[G%11],b[B%11]);
	glPushMatrix();
	glTranslated(0,0,0);
	glutSolidCube(1);
	glPopMatrix();
	glColor3d(0,0,0);
	glPushMatrix();
	glTranslated(0.2,0,0);
	glScaled(0.3,0.3,1.001);
	glutSolidCube(1);
	glPopMatrix();
	glColor3d(0,0,0);
	glPushMatrix();
	glTranslated(-0.2,0,0);
	glScaled(0.3,0.3,1.001);
	glutSolidCube(1);
	glPopMatrix();
	glColor3d(0,0,0);
	glPushMatrix();
	glTranslated(0,0,0.2);
	glScaled(1.001,0.3,0.3);
	glutSolidCube(1);
	glPopMatrix();
	glColor3d(0,0,0);
	glPushMatrix();
	glTranslated(0,0,-0.2);
	glScaled(1.001,0.3,0.3);
	glutSolidCube(1);
	glPopMatrix();	
}
	
void house(int n,int R,int G)
{
	for(int i=0;i<n;i++)
	{
		glPushMatrix();
		glTranslated(0,0.8+i,0);
		singleHouse(G,R,i);
		glPopMatrix();
	}
}

void Pillar1Env()
{
	/// Ground
	glColor3d(0,0.5,0.1);
	glPushMatrix();
	glTranslated(0,0,0);
	glScaled(EN_SIZE*2,0.3,EN_SIZE*2);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-8,-2.7,-5);
	glRotated(65,0,1,0);
	glScaled(2,2,2);
	drawPillar1();
	glPopMatrix();
	glPushMatrix();
	glTranslated(8,-2.7,-5);
	glRotated(-65,0,1,0);
	glScaled(2,2,2);
	drawPillar1();
	glPopMatrix();
}

//For the hoops(rings)...for the rings..(torus) to automatically appear in the environment this function might be used.
void environment(int n)
{
	/// Ground
	glColor3d(0,0.5,0.1);
	glPushMatrix();
	glTranslated(0,0,0);
	glScaled(EN_SIZE*2,0.3,EN_SIZE*2);
	glutSolidCube(1);
	glPopMatrix();
	glColor3d(0,1,0.1);
	glPushMatrix();
	glTranslated(torusPosX[n],torusPosY[n],0);
	glScaled(0.3,0.3,0.3);
	glutSolidTorus(1,3,30,30);
	glPopMatrix();
	for(int i=-(EN_SIZE/2)+1;i<(EN_SIZE/2);i+=2)
	{
		for(int j=-(EN_SIZE/2)+1;j<(EN_SIZE/2);j+=2)
		{
			if(tola[i+(EN_SIZE/2)+1][j+(EN_SIZE/2)+1]!=0)
			{
				glPushMatrix();
				glTranslated(i,0,j);
				house(tola[i+(EN_SIZE/2)+1][j+(EN_SIZE/2)+1],i,j);
				glPopMatrix();
			}
			else if(i>=-5&&i<=5)
			{
			}
			else
			{
				tola[i+(EN_SIZE/2)+1][j+(EN_SIZE/2)+1]=(rand()%5)+1;
				glPushMatrix();
				glTranslated(i,0,j);
				house(tola[i+(EN_SIZE/2)+1][j+(EN_SIZE/2)+1],i,j);
				glPopMatrix();
			}
		}
	}
}

//For rotation of the plane along with the whole frame thta is along with the buildings .....
void draw()
{
	double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
	double a = t*90.0;
	TIME = t;

	///Plane
	if(rotX>11)rotX=11;
	if(rotX<-11)rotX=-11;
	if(rotZ>10)rotZ=10;
	if(rotZ<-15)rotZ=-15;
	glPushMatrix();
	glTranslated(0,1,0);
	glRotated(90,0,1,0);
	glRotated(5,0,0,1);
	glRotated(rotX,1,0,0);
	glRotated(rotY,0,1,0);
	glRotated(rotZ,0,0,1);
	glScaled(0.4,0.4,0.4);
	plane();
	glPopMatrix();
	
	///Environment
	if(tX>=4.1)tX=4.1;
	if(tX<=-4.1)tX=-4.1;
	if(tY>0.1)tY= 0.1;
	if(tY<-15)tY= -15;
	glPushMatrix();
	glTranslated(tX,tY,tZ);
	environment(2);
	glPopMatrix();
	glPushMatrix();
	glTranslated(tX,tY,tZ1);
	Pillar1Env();
	glPopMatrix();
	glPushMatrix();
	glTranslated(tX,tY,tZ2);
	environment(3);
	glPopMatrix();
	glPushMatrix();
	glTranslated(tX,tY,tZ3);
	environment(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(tX,tY,tZ4);
	environment(5);
	glPopMatrix();
	glPushMatrix();
	glTranslated(tX,tY,tZ5);
	environment(4);
	glPopMatrix();
	glPushMatrix();	
	glTranslated(tX,tY,tZ6);
	environment(2);
	glPopMatrix();
	tZ+=speed;
	tZ1+=speed;
	tZ2+=speed;
	tZ3+=speed;
	tZ4+=speed;
	tZ5+=speed;
	tZ6+=speed;
	if(tZ>=20)
		tZ=-110;
	if(tZ1>=20)
		tZ1=-110;
	if(tZ2>=20)
		tZ2=-110;
	if(tZ3>=20)
		tZ3=-110;
	if(tZ4>=20)
		tZ4=-110;
	if(tZ5>=20)
		tZ5=-110;
	if(tZ6>=20)
		tZ6=-110;
	if(rotX>0)
		rotX-=angleBackFrac;
	if(rotX<0)
		rotX+=angleBackFrac;
	if(rotY>0)
		rotY-=angleBackFrac;
	if(rotY<0)
		rotY+=angleBackFrac;
	if(rotZ>0)
		rotZ-=angleBackFrac;
	if(rotZ<0)
		rotZ+=angleBackFrac;
		speed += 0.0002;
	if(speed>=0.7)
		speed=0.7;
}
	
void drawBitmapText(char *str,float x,float y,float z)
{
	char *c;
	glRasterPos3f(x,y+8,z);
	for (c=str; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *c);
	}
}

void drawStrokeText(char* str,int x,int y,int z)
{
	char *c;
	glPushMatrix();
	glTranslatef(x, y+8,z);
	glScalef(0.002f,0.002f,z);
	for (c=str; *c != '\0'; c++)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
	}
	glPopMatrix();
}

void drawStrokeText2(char* str,int x,int y,int z)
{
	char *c;
	glPushMatrix();
	glTranslatef(x, y+8,z);
	glScalef(0.005f,0.005f,z);
	for (c=str; *c != '\0'; c++)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
	}
	glPopMatrix();
}

void drawStrokeChar(char c,float x,float y,float z)
{
	glPushMatrix();
	glTranslatef(x, y+8,z);
	glScalef(0.002f,0.002f,z);
	glutStrokeCharacter(GLUT_STROKE_ROMAN , c);
	glPopMatrix();
}

void *fonts[]=
{
	GLUT_BITMAP_9_BY_15,
	GLUT_BITMAP_TIMES_ROMAN_10,
	GLUT_BITMAP_TIMES_ROMAN_24,
	GLUT_BITMAP_HELVETICA_18,
	GLUT_BITMAP_HELVETICA_12
};

void front()
{
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0,0,1);
        output(370,610," BANGALORE INSTITUTE OF TECHNOLOGY",fonts[2]);
        glColor3f(0.7,0,1);
        output(390,570,"DEPARTMENT OF COMPUTER SCIENCE & ENGINEERING.",fonts[0]);
        glColor3f(0.8,0.1,0.2);
        output(410,500,"FLYING THROUGH HOOPS",fonts[2]);
        glColor3f(1.0,0.0,1.0);
        output(450,400,"SUBMITTED BY :",fonts[0]);
        glColor3f(0.3,0.5,0.8);
        output(130,350,"RAAGA SHETTY B P",fonts[3]);
        output(130,310,"NEHA RAVISHANKAR",fonts[3]);
        output(180,300,"",fonts[3]);
        output(680,350,"1BI17CS119",fonts[3]);
        output(680,310,"1BI17CS099",fonts[3]);
        glColor3f(0.6,0.25,0.0);
        output(410,100,"[ PRESS ANY KEY TO CONTINUE ]",fonts[3]);
}

void menus()
{
        glColor3f(0.8,0.1,0.2);
        output(280,600,"FLYING THROUGH HOOPS",fonts[2]);
        glColor3f(0.0,0.6,0.3);
        output(350,400,"SELECT AN OPTION",fonts[2]);
        output(350,380,"-----------------",fonts[2]);
        glColor3f(0.3,0.5,0.8);
        output(380,340,"[ 1 ] PROCEED",fonts[3]);
        output(380,300,"[ 2 ] INSTRUCTIONS",fonts[3]);
        output(380,260,"[ 3 ] INTRODUCTION",fonts[3]);
        output(380,220,"[ b ] BACK",fonts[3]);
        output(380,180,"[ q ] QUIT",fonts[3]);
        glColor3f(0.5,0.2,0.6);
}

void instructions()
{
        glColor3f(0.8,0.1,0.2);
        output(280,600,"FLYING THROUGH HOOPS",fonts[2]);
        
        glColor3f(0.0,0.6,0.3);
        output(180,560, "RIGHT CLICK MOUSE TO SWITCH SPEEDS OR STOP THE PLANE",fonts[3]);
        output(180,520,"",fonts[3]);
        output(180,480,"----> [ W ] FOR MOVEUP ",fonts[3]);
        output(180,440,"----> [ S ] FOR MOVEDOWN ",fonts[3]);
        output(180,400,"----> [ A ] FOR LEFT ",fonts[3]);
        output(180,360,"----> [ D ] FOR RIGHT",fonts[3]);
        output(180,320,"----> [ G ] FOR START ",fonts[3]);

        glColor3f(0.3,0.5,0.8);
        output(550,280,"SELECT AN OPTION",fonts[2]);
        output(550,265,"-----------------",fonts[2]);
        output(550,230,"( h ) HOME",fonts[3]);
        output(550,190,"( b ) BACK",fonts[3]);
        output(550,150,"( q ) QUIT",fonts[3]);
        
        glColor3f(0.5,0.2,0.6);
        output(600,60," Dept. of CS&E, BIT",fonts[0]);
}

void intro()
{
        glColor3f(0.8,0.1,0.2);
        //output(280,600,"FLYING THROUGH HOOPS",fonts[2]);
        
        glColor3f(0.0,0.6,0.3);
        output(160,480,"WELCOME TO FLYING THROUGH HOOPS!",fonts[2]);
        output(160,430,"IT'S A SIMPLE 3D PLANE GAME",fonts[2]);
        output(160,380,"HOPE YOU ENJOY THE GAME!! CHEERS!",fonts[2]);
        output(160,400,"...........",fonts[0]);
        
        glColor3f(0.3,0.5,0.8);
        output(550,300,"SELECT AN OPTION",fonts[2]);
        output(550,270,"-----------------",fonts[2]);
        output(550,230,"[ h ] HOME",fonts[3]);
        output(550,190,"[ b ] BACK",fonts[3]);
        output(550,150,"[ q ] QUIT",fonts[3]);

        glColor3f(0.5,0.2,0.6);
        output(600,60,"[ Dept. of CS&E, BIT ]",fonts[0]);
}

void menuset()
{
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, 1000, 0.0, 750,-2000,1500);
        glMatrixMode(GL_MODELVIEW);
        glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
}

//Display function to display the front page,instructions page,introduction page............the respective functions are called in this display method
static void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        if(f==0)
        {
                menuset();
                front();
                glutSwapBuffers();
        }
        else if(f==1)
        {
		menuset();
                menus();
                glutSwapBuffers();
        }
        else if(f==3)
        {
                menuset();
                instructions();
                glutSwapBuffers();
        }
        else if(f==4)
        {
                menuset();
                intro();
		glutSwapBuffers();
        }
        else
        {
        	glClearColor(1.0,0.8,0.3,0.0);
                //display1();

        }	
	const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
	double a = t*90.0;
	double aa=a;
	if(!rot)
	{
		a=0;
	}
	glLoadIdentity();
	gluLookAt( 0.0, 4.5, 10.0,0, 4, 0,0, 1.0f, 0.0f);
	if(START)
	{
		glPushMatrix();
		glTranslated(0,0,0);
		glScaled(zoom,zoom,zoom);
		glRotated(a,0,1,0);              
		draw();
		glPopMatrix();
		drawStrokeText("UP: W, DOWN: S, LEFT: A, RIGHT: D, MAIN MENU: M",-8,0.9,0);
		drawStrokeText("TIME : ",3,0,0);
		int mod,number=0;
		while(TIME)
		{
			mod=TIME%10;
			number=number*10+mod;
			TIME/=10;
		}
		float tmp=0;
		while(number)
		{
			mod=number%10;
			drawStrokeChar(mod+48,4+tmp,0,0);
			number/=10;
			tmp+=0.2;
		}
	}	
	else
	{
		glPushMatrix();
		glTranslated(0,3,0);
		glRotated(aa,0,1,0);
		glScaled(1.5,1.5,1.5);
		plane();
		glPopMatrix();
		drawStrokeText("Press G to Start",-1,-1,0);
		drawStrokeText2("Plane Game",-2,0,0);
	}
	glutSwapBuffers();
}

static void idle(void)
{
	glutPostRedisplay();
}

//Keyboard interaction is implemented using this method
void key( unsigned char key, int x, int y )
{
	float frac = 0.3;
	float rotFrac = 1;
        if(f==0)
		f=1;
        else if(f==1)
        {
                switch(key)
                {
                	case '1':f=2;
                		 break;
                	case '2':f=3;
                		 break;
                	case '3':f=4;
                		 break;
                	case 'b':
                	case 'B':f=0;
                		 break;
                	case 'q':
                	case 'Q':exit(0);
                }
        }
        else if(f==2)
        {
                switch(key)
                {
                	case 'q':
                	case 'Q':exit(0);
                		 break;
                	case 'b':
                	case 'B':f=1;
                		 break;
                	case 'h':
                	case 'H':f=0;
                		 break;
                	case 'r':rot=true;
                		 break;
			case 't':rot=false;
				 break;
			case 'z':zoom+=0.05;
				 break;
			case 'Z':zoom-=0.05;
			case 'G':
	                case 'g':START=true;
				 break;
			case 'm':START=false;
				 break;
                	case 'w':tY-=frac;
				 rotZ+=rotFrac;
				 break;
               	  	case 's':tY+=frac;
				 rotZ-=rotFrac;
				 break;
			case 'a':tX+=frac;
				 rotX-=rotFrac*3;
				 rotY+=rotFrac/2;
				 break;
                 	case 'd':tX-=frac;
				 rotX+=rotFrac*3;
				 rotY-=rotFrac/2;
				 break;
                }
        }
        else if(f==3)
        {
                switch(key)
                {
                	case 'b':
	                case 'B':f=1;
	                	 break;
	                case 'h':
	                case 'H':f=0;
	                	 break;
	                case 'q':
	                case 'Q':exit(0);
			glutSwapBuffers();
                }
        }
        else
        {

                switch(key)
                {
                	case 'b':
              	 	case 'B':f=1;
              	 		 break;
                	case 'h':
                	case 'H':f=0;
                		 break;
                	case 'q':
                	case 'Q':exit(0);
                }
        }
   	resize(1900,700);
   	idle( );
}

const GLfloat light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };
const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };


//Mouse Interaction
//This function is for controlling the speed of the plane....Thee cases in the switch block are mapped to the menu options which are acleed using glutAddMenuEntry().
void menu(int val)
{
	switch(val)
	{
		case 1: if(speed==0)
				speed=0.5;
           		else
            			speed-=0.15;
           		break;
  	 	case 2: if(speed==0)
            			speed=0.5;
           		else
            			speed+=0.25;
           		break;
   		case 3: speed=0;
          		break;
   		case 4: exit(0);
          		break;
	}
}


/* Program entry point */
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(2000,1000);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
	glutCreateWindow("Flying Through Hoops");
	
	int sub_menu;
	sub_menu=glutCreateMenu(menu);
	glutAddMenuEntry("Slow",1);
	glutAddMenuEntry("Fast",2);
	glutCreateMenu(menu);
	glutAddSubMenu("Plane Speed",sub_menu);
	glutAddMenuEntry("stop",3);
	glutAddMenuEntry("Exit",4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	
	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutKeyboardFunc(key);
	glutIdleFunc(idle);
	glClearColor(1.0,0.8,0.3,0.0);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	glutMainLoop();
	return EXIT_SUCCESS;
}
