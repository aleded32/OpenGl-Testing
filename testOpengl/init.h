#pragma once

#include <glut.h>

class init
{
public:

	 
	 init(int argc, char **argv, int width, int height);
	 int getWidth();
	int getHeight();
	~init();
private:
	int width, height;
	
	


};