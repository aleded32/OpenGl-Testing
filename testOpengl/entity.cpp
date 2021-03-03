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

void Polygon::init(std::ifstream* vertexFileRead)
{

	

	
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

void Polygon::initAnimation(points* p, float* starVertex)
{
	float degrees = 360 / 5;
	float angleOfVertex = degrees * M_PI / 180;
		
	
	
			starVertex[0] = vertex[0];
			starVertex[1] = vertex[1];

			
			starVertex[2] = (vertex[0] + vertex[2]) / 2;
			starVertex[3] = (vertex[1] + vertex[3]) / 2;

			starVertex[4] = vertex[2];
			starVertex[5] = vertex[3];
			
			
			starVertex[6] = (vertex[2] + vertex[4]) / 2;
			starVertex[7] = (vertex[3] + vertex[5]) / 2;

			starVertex[8] = vertex[4];
			starVertex[9] = vertex[5];

			starVertex[10] = (vertex[4] + vertex[6]) / 2;
			starVertex[11] = (vertex[5] + vertex[7]) / 2;

			starVertex[12] = vertex[6];
			starVertex[13] = vertex[7];

			starVertex[14] = (vertex[6] + vertex[8]) / 2;
			starVertex[15] = (vertex[7] + vertex[9]) / 2;

			starVertex[16] = vertex[8];
			starVertex[17] = vertex[9];

			starVertex[18] = (vertex[8] + vertex[0]) / 2;
			starVertex[19] = (vertex[9] + vertex[1]) / 2;
			
			
}

Polygon::~Polygon()
{

}

void Polygon::writeVertices(std::ofstream* vertexFileWrite)
{




	vertexFileWrite->open("v.txt");
	if(vertexFileWrite->is_open())
	{
		float degrees = 360/5;
		float angleOfVertex = degrees * M_PI/180;
		float scale = 0.5;
		


		
		

		for (int i = 0; i < 5; i++) 
		{
			x = scale *sin(angleOfVertex * i);
			y = scale *cos(angleOfVertex * i);

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
	glLineWidth(2);

	glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
		
				glVertex2f(vertex[0], vertex[1]);
				glTexCoord2f(vertex[0], vertex[1]);
				glVertex2f(vertex[2], vertex[3]);
				glTexCoord2f(vertex[2], vertex[3]);
				glVertex2f(vertex[4], vertex[5]);
				glTexCoord2f(vertex[4], vertex[5]);
				glVertex2f(vertex[6], vertex[7]);
				glTexCoord2f(vertex[6], vertex[7]);
				glVertex2f(vertex[8], vertex[9]);
				glTexCoord2f(vertex[8], vertex[9]);
				
				
		glEnd();
		glDisable(GL_TEXTURE_2D);
		
	glEndList();

	glCallList(listName);
	glDeleteLists(listName, 1);

	
}

float Polygon::getVertex(int index)
{
	return vertex[index];
}

GLuint Polygon::loadTexture(const char* filePath)
{
	
	

	FILE* file = fopen(filePath, "rb");

	if (!file) 
	{
		return 0;
	}
	
		if(fread(header, 1, 54, file) != 54)
		{
			return false;
		}
		
		

		if (header[0] != 'B' || header[1] != 'M') 
		{
			return 0;
		}
		
		dataPos = *(int*)&(header[0x0A]);
		imageSize = *(int*)&(header[0x22]);
		width = *(int*)&(header[0x12]);
		height = *(int*)&(header[0x16]);

		data = new unsigned char[imageSize];

		fread(data, 1, imageSize, file);

		fclose(file);
	

	
		glGenTextures(1, &texture);

		glBindTexture(GL_TEXTURE_2D, texture);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, data);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);


		delete data;

	return texture;
}


Star::Star()
{
	dx = 0.0;
	dy = 0.0;
	angle = 0.0;
	scale = 1.0;

}

Star::~Star()
{
}

void Star::init(std::ifstream* vertexFileRead)
{
	listName = glGenLists(1);
	vertexFileRead->open("vStar.txt");
	if (vertexFileRead->is_open())
	{

		for (int i = 0; i < 20; i++)
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

void Star::writeVertices(std::ofstream* vertexFileWrite)
{



	vertexFileWrite->open("vStar.txt");
	if (vertexFileWrite->is_open())
	{
		float scale = 0.4;

		float degrees = 360 / 5;
		float angleOfVertex = degrees * M_PI / 180;




		for (int i = 0; i < 5; i++)
		{
			
				
				x[2*i] = scale * sin(angleOfVertex * i);
				y[2*i] = scale * cos(angleOfVertex * i);
			
			*vertexFileWrite << x[i] << " " << y[i] << std::endl;
		}
		for (int i = 0; i < 5; i++)
		{


			x[2 * i +1] = (x[2 * i] * cos(angleOfVertex/2) + y[2*i] * sin(angleOfVertex/2))/2;
			y[2 * i + 1] = (y[2 * i] * cos(angleOfVertex / 2) - x[2 * i] * sin(angleOfVertex / 2)) / 2;

			*vertexFileWrite << x[i+5] << " " << y[i+5] << std::endl;
		}


	}
	else
	{
		printf("cant load from file");
	}

	vertexFileWrite->close();

}

void Star::create()
{




	glNewList(listName, GL_COMPILE);
	glLineWidth(5);


	glBegin(GL_LINE_LOOP);
	
	glVertex2f(vertex[0], vertex[1]);
	glVertex2f(vertex[2], vertex[3]);
	glVertex2f(vertex[4], vertex[5]);
	glVertex2f(vertex[6], vertex[7]);
	glVertex2f(vertex[8], vertex[9]);
	glVertex2f(vertex[10], vertex[11]);
	glVertex2f(vertex[12], vertex[13]);
	glVertex2f(vertex[14], vertex[15]);
	glVertex2f(vertex[16], vertex[17]);
	glVertex2f(vertex[18], vertex[19]);
	glEnd();
	glEndList();

	glCallList(listName);
	glDeleteLists(listName, 2);


}


float Star::getVertex(int index)
{
	return vertex[index];
}




