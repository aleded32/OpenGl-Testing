#include "input.h"


void input::move(int& x, int& y, int button)
{

	
	
		if(button == GLUT_LEFT_BUTTON)
		{
			translateObject(x,y);
			
			
		}
		if(button == GLUT_RIGHT_BUTTON)
		{
			rotateObject(x,y);
			
		}
		if(button == GLUT_MIDDLE_BUTTON)
		{
			scaleObject(x,y);
		}
		
	
	
}



float input::coordX(float x)
{

	float vertexX = x/(601/4) - 2;

	return vertexX;
}

float input::coordY(float y)
{
	float vertexY = (y/(601/4) -2) *-1;

	return vertexY;
}

void input::translateObject(int x, int y)
{

	
	polygon->dx += (coordX(x) - coordX(lastMouseX));
	polygon->dy += (coordY(y) - coordY(lastMouseY));


	lastMouseX = x;
	lastMouseY = y;
	

}

void input::rotateObject(int x, int y)
{
	polygon->angle += (coordY(lastMouseY) - coordY(y));

	
}

void input::scaleObject(int x, int y)
{
	polygon->scale -= (coordY(lastMouseY) - coordY(y))* 0.05;
}


input::input(init* _Init, Polygon* _polygon)
{

	

	Init = _Init;
	polygon = _polygon;
}

input::~input()
{
	
}