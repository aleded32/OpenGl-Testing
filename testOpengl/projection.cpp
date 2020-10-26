#include "projection.h"

void projection::windowProjection(int w, int h)
{
	if(h == 0)
		h =1;

	float ratio = 1 * w/h;

	glViewport(0,0,(GLsizei)w, (GLsizei)h);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluPerspective(45,ratio,1,1000);
	gluLookAt(0,0,5,
			  0,0,1,
			  0,1,0);
}