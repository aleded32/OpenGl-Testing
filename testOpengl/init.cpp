#include "init.h"




init::init(int argc, char **argv, int _width, int _height)
{
	width = _width;
	height = _height;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(width,height);
	glutCreateWindow("Test");
	
	

	
};

int init::getWidth()
{
	return width;
}

int init::getHeight()
{
	return height;
}




