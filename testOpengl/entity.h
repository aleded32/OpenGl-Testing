#include <iostream>
#include <vector>
#include <fstream>
#include <GL/glut.h>

class entity
{
public:

	double size;
	float angle;
	std::vector<int> index;

	entity();
	~entity();
	void create();
	void checkList();
	GLuint listName;

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