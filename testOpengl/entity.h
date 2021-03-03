#pragma once

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <glut.h>

class points 
{
public:

	float x, y, z;

	points(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}
	points() {}

	
};




class entity
{
public:

	double size;
	float dx, dy;
	float angle;
	float scale;
	float x, y;
	int listName;
	
	

	entity();
	~entity();
	void create();
	void move();
	void loadTexture(GLuint texture, const char* filePath);
	void morphAnimation();

	unsigned char header[54];
	unsigned int dataPos;
	unsigned int width, height;
	unsigned int imageSize;
    unsigned char * data;
	GLuint image;
	GLuint LoadBMP(const char* filePath);
	GLuint texture;

private:

	
	

	
	

};


class Polygon : public entity
{
public:
	Polygon();
	~Polygon();

	//void create();
	points p[5];
	void init(std::ifstream* vertexFileRead);
	void writeVertices(std::ofstream* vertexFileWrite);
	float getVertex(int index);
	float setVertex(int index, int value);
	void create();
	GLuint loadTexture(const char* file);
	void initAnimation(points* p, float* starVertex);

	float vertex[10];
	
	//void morphAnimation();

private:



	

};


class Star : public entity
{
public:
	Star();
    ~Star();

	float x[10], y[10];

	void init(std::ifstream* _vertexFileRead);
	void writeVertices(std::ofstream* vertexFileWrite);
	float getVertex(int index);
	float setVertex(int index, int value);
	void create();
	float vertex[20];



private:





};