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

void Polygon::init(std::ifstream* _vertexFileRead)
{

	

	vertexFileRead = _vertexFileRead;
	listName = glGenLists(1);
	vertexFileRead->open("v.txt");
	if(vertexFileRead->is_open())
	{
		
		for(int i = 0; i < 10; i++)
		{
			*vertexFileRead >> vertex[i];
		}
		
	}
	else
	{
		printf("cant load from file");
	}
	
	vertexFileRead->close();
	
}

Polygon::~Polygon()
{

}

void Polygon::writeVertices(std::ofstream* _vertexFileWrite)
{
	vertexFileWrite = _vertexFileWrite;



	vertexFileWrite->open("v.txt");
	if(vertexFileWrite->is_open())
	{
		
		float angleOfVertex = 2 * M_PI / 5.0;

		float x1 = 0.0;
		float y1 = 0.5;


		*vertexFileWrite << x1 << " " << y1 << std::endl;
		

		for (int i = 1; i < 5; i++) 
		{
			x = x1 * cos(angleOfVertex * i) - y1 * sin(angleOfVertex * i);
			y = y1 * cos(angleOfVertex * i) + x1 * sin(angleOfVertex * i);

			*vertexFileWrite << x << " " << y << std::endl;
		}

	}
	else
	{
		printf("cant load from file");
	}
	
	vertexFileWrite->close();


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
			glColor3f(0.2,0.3,0.2);
				glVertex2f(vertex[2], vertex[3]);
			glColor3f(0,0.6,0.2);
				glVertex2f(vertex[4], vertex[5]);
			glColor3f(0.1,0.7,0.2);
				glVertex2f(vertex[6], vertex[7]);
			glColor3f(0.1,0.3,0.5);
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






