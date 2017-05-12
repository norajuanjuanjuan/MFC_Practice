#include "stdafx.h"
#include "Rectangle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle(void)
{
}


Rectangle::~Rectangle(void)
{
}

int Rectangle::getArea()
{
	return (width*height);
}

void Rectangle::printAreaInfo()
{
	cout<<"Rectangle class area:"<<endl;
}