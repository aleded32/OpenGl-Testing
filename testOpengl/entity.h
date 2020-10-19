#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <glut.h>

class entity
{
public:

	double size;
	float angle;
	std::vector<int> index;

	entity();
	~entity();
	void create();
	void move();
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

	void create();
	float getVertex(int index);
	float setVertex(int index, int value);
	
private:

	std::ifstream* vertexFile;

	float vertex[10];

};