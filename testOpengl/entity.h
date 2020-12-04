#pragma once

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <glut.h>

class entity
{
public:

	double size;
	float dx, dy;
	float angle;
	float scale;
	float x, y;
	

	entity();
	~entity();
	void create();
	void move();
	GLuint listName;

};


class Polygon : public entity
{
public:
	Polygon();
	~Polygon();

	void create();
	void init(std::ifstream* vertexFileRead);
	void writeVertices(std::ofstream* vertexFileWrite);
	float getVertex(int index);
	float setVertex(int index, int value);
	float vertex[10];
	
	

private:

	std::ifstream* vertexFileRead;
	std::ofstream* vertexFileWrite;

	

};