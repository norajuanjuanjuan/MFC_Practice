#pragma once
class Shape
{
public:
	Shape(void);
	~Shape(void);
	void setWidth(int w);
	void setHeight(int h);
	virtual void printAreaInfo();
protected:
	int width;
	int height;
};

