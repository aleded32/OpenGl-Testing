#include "input.h"


void input::move(int x, int y, int state)
{
	if(state == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(x >= ScreenX(8) &&  x <= ScreenX(2) && y >= ScreenY(3) && y <= ScreenY(5))
		{
			std::cout << "pentagon" << std::endl;
		}
		
	}
	
}

int input::ScreenX(float vertex)
{
	int x = (Init->getWidth()/4) * (polygon->getVertex(vertex) + 2);
	return x;
}

int input::ScreenY(float vertex)
{

	int y = (Init->getHeight()/4) * ((polygon->getVertex(vertex)*-1) + 2);	

	return y;
}

float input::coordX(float x)
{

	float vertexX = x/(Init->getWidth()/4) - 2;

	return vertexX;
}

float input::coordY(float y)
{
	float vertexY = (y/(Init->getWidth()/4)*-1) - 2;

	return vertexY;
}


input::input(init* _Init, Polygon* _polygon)
{
	Init = _Init;
	polygon = _polygon;
}

input::~input()
{
	
}