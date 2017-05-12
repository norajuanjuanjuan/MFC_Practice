#pragma once
#include "shape.h"
#include "PaintCost.h"
class Rectangle :
	public Shape,public PaintCost
{
public:
	Rectangle(void);
	~Rectangle(void);
	int getArea();
	void printAreaInfo();
};

