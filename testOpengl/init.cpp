#include "init.h"




init::init(int argc, char **argv, int width, int height)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(400,400);
	glutCreateWindow("Test");
	
	

	
};

