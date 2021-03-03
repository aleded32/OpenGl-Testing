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
Star* star = new Star;
input* Input = new input(intialise, polygon);
Star inbet;
bool revertAnim = false;


int _button;
float dx = 0.0, dy = 0.0;
float timer;
	

int main(int argc, char **argv)
{
	
	
	
	intialise = new init(argc,argv,601,601);

	GLuint Texture = NULL;
	Texture = polygon->loadTexture("texture.bmp");

	glutDisplayFunc(display);
	
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	glutMouseFunc(inputKey);
	glutMotionFunc(inputMouse);

	
	
	glutMainLoop();
	
	
	delete polygon;
	delete intialise;
	delete Input;
	delete star;
	return 0;
	
};

void display()
{
	
	
	points p[10];
	
	std::ifstream vertexTextRead;
    std::ofstream vertexTextWrite;
	polygon->writeVertices(&vertexTextWrite);
	polygon->init(&vertexTextRead);
	
	
	

	star->writeVertices(&vertexTextWrite);
	star->init(&vertexTextRead);
	//inbet.init(&vertexTextRead);
	polygon->initAnimation(p, inbet.vertex);
	

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	
	glTranslatef(polygon->dx, polygon->dy, 0);
	glRotatef(polygon->angle, 0,0,1);
	glScalef(polygon->scale,polygon->scale, 0);
	polygon->create();
	//star->create();
	
	Star tmp;

	if (timer > 1.0) 
	{
		revertAnim = true;
	} 
	else if (timer <= 0.0) 
	{
		revertAnim = false;
	}

	for (int i = 0; i < 20; i++) 
	{
		tmp.vertex[i] = inbet.getVertex(i) * (1.0 - timer) + star->getVertex(i) * timer;
	}
	tmp.create();
	
	
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
	if (revertAnim == false) 
	{
		timer += 0.01;
	}
	else if (revertAnim == true)
	{
		timer -= 0.01;
	}
	
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



