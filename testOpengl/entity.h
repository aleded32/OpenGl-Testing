#include <glut.h>

class entity
{
public:

	double size;
	float angle;

	entity();
	~entity();
	void create();


};

class teapot : public entity
{
public:
	teapot(double size, float angle);
	~teapot();
	void create();
	
};