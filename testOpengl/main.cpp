#include <fstream>
#include <glut.h>
#include "init.h"
#include "projection.h"
#include "entity.h"


void display();
void reshape(int w, int h);
void idle();


	

int main(int argc, char **argv)
{
	
	

	init* intialise = new init(argc,argv,640,480);
	
	
		
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	glutMainLoop();
	
	
	return 0;
	//delete intialise;
};

void display()
{
	teapot Teapot(0.5, 0.1);
	std::ifstream vertexText;
	Polygon* polygon = new Polygon(&vertexText);
	
	polygon->init();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Teapot.create();
	polygon->create();


	delete polygon;
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