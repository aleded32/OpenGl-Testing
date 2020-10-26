#include "entity.h"

entity::entity()
{
}

entity::~entity(){}


Polygon::Polygon()
{
	dx = 0.0;
	dy = 0.0;
	angle = 0.0;
	scale = 1.0;
	
}

void Polygon::init(std::ifstream* _vertexFile)
{


	vertexFile = _vertexFile;
	listName = glGenLists(1);
	vertexFile->open("v.txt");
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

Polygon::~Polygon()
{

}

float Polygon::setVertex(int index, int value)
{
	return vertex[index] += value;
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
	glDeleteLists(listName, 1);
}

float Polygon::getVertex(int index)
{
	return vertex[index];
}






