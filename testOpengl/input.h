#pragma once

#include <iostream>
#include <glut.h>
#include "entity.h"
#include "init.h"

class input
{
public:
	
	Polygon* polygon;
	init* Init;

	input(init* _Init, Polygon* _polygon);
	~input();
	void move(int x, int y, int state);

	int ScreenX(float vertex);
	int ScreenY(float vertex);
	float coordX(float x);
	float coordY(float y);

};