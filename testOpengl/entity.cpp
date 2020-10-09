#include "entity.h"

entity::entity(){}

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