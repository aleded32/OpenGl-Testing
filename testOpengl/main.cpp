#include <fstream>
#include <iostream>
#include <vector>
#include <glut.h>
#include "init.h"
#include "projection.h"
#include "entity.h"
#include "input.h"



void display();
void reshape(int w, int h);
void idle();
void inputMouse(int x, int y);
void inputKey(int button,int state, int x, int y);
init* intialise;
Polygon* polygon = new Polygon;
input* Input = new input(intialise, polygon);


int _button;
float dx = 0.0, dy = 0.0;

	

int main(int argc, char **argv)
{
	
	

	intialise = new init(argc,argv,601,601);
	

	glutDisplayFunc(display);
	
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	glutMouseFunc(inputKey);
	glutMotionFunc(inputMouse);

	
	
	glutMainLoop();
	
	
	delete polygon;
	delete intialise;
	delete Input;
	return 0;
	
};

void display()
{
	
	
	std::ifstream vertexTextRead;
    std::ofstream vertexTextWrite;
	polygon->writeVertices(&vertexTextWrite);
	polygon->init(&vertexTextRead);
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	
	glTranslatef(polygon->dx, polygon->dy, 0);
	glRotatef(polygon->angle, 0,0,1);
	glScalef(polygon->scale,polygon->scale, 0);
	polygon->create();

	glPopMatrix();
	glutSwapBuffers();
	
	
	
	glFlush();

	
}



void reshape(int w, int h)
{
	projection* projected = new projection;
	projected->windowProjection(w,h);
	delete projected;
}

void idle()
{
  glutPostRedisplay();
  
  
}

void inputMouse(int x, int y)
{

	
	
	
	Input->move(x, y, _button);
	
	
	
}

void inputKey(int button, int state, int x, int y)
{
	_button = button;
	Input->lastMouseX = x;
	Input->lastMouseY = y;

}



