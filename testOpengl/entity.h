#include <iostream>
#include <fstream>
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

class Polygon : public entity
{
public:
	Polygon(std::ifstream* vertexFile);
	~Polygon();

	std::ifstream* vertexFile;
	float vertex[10];

	void init();
	void create();
};