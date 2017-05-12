#include "stdafx.h"
#include "Shape.h"
#include <iostream>
using namespace std;

Shape::Shape(void)
{
}


Shape::~Shape(void)
{
}

void Shape::setWidth(int w)
{
	width=w;
}

void Shape::setHeight(int h)
{
	height=h;
}

 void Shape::printAreaInfo()
{
	cout<<"Parent class area"<<endl;
}