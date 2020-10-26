#pragma once

#include <iostream>
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

	std::vector<int> index;

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
	void init(std::ifstream* vertexFile);
	float getVertex(int index);
	float setVertex(int index, int value);
	
	

private:

	std::ifstream* vertexFile;

	float vertex[10];

};