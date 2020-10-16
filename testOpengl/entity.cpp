#include "entity.h"

entity::entity()
{
}

entity::~entity(){}


teapot::teapot(double size, float angle)
{
	this->size = size;
	this->angle = angle;
}

teapot::~teapot()
{

}

void teapot::create()
{
	
	glRotatef(angle, 1,0,0);
	glutWireTeapot(size);
}

Polygon::Polygon(std::ifstream* _vertexFile)
{
	vertexFile = _vertexFile;
	listName = glGenLists(1);
}

Polygon::~Polygon()
{

}

void Polygon::init()
{
	

	vertexFile->open("D:\\v.txt");
	if(vertexFile->is_open())
	{
		
		for(int i = 0; i < 10; i++)
		{
			*vertexFile >> vertex[i];
		}
		
	}
	else
	{
		printf("cant load from file");
	}
	
	vertexFile->close();
	
	

}

void Polygon::create()
{
	
	glNewList(listName, GL_COMPILE);
		glBegin(GL_POLYGON);
			glColor3f(0.5,0.1,0.2);
				glVertex2f(vertex[0], vertex[1]);
				glVertex2f(vertex[2], vertex[3]);
				glVertex2f(vertex[4], vertex[5]);
				glVertex2f(vertex[6], vertex[7]);
				glVertex2f(vertex[8], vertex[9]);	
		glEnd();
	glEndList();

	glCallList(listName);

}

