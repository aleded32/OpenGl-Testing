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
void inputs(int button, int state, int x, int y);
init* intialise;



	

int main(int argc, char **argv)
{
	
	

	intialise = new init(argc,argv,601,601);
	

	glutDisplayFunc(display);
	
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	
	glutMainLoop();
	
	
	
	return 0;
	
};

void display()
{
	
	//teapot Teapot(0.5, 0.1);
	
	std::ifstream vertexText;
    Polygon* polygon = new Polygon(&vertexText);
	

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	polygon->create();
	//Teapot.create();
	
	
	glutSwapBuffers();
	glutMouseFunc(inputs);
	delete polygon;
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

void inputs(int button, int state, int x, int y)
{

	std::ifstream vertexText;
    Polygon* polygon = new Polygon(&vertexText);
	
	input* Input = new input(intialise, polygon);
	Input->move(x, y, state);
	//std::cout << polygon->getVertex(0) << std::endl;
	delete Input;
	delete polygon;
}

