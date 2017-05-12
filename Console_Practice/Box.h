#pragma once
class Box
{
public:
	Box(void);
	Box(double len,double height,double breadth);
	//Box(const Box &obj);//¿½±´¹¹Ôìº¯Êý
	~Box(void);

	friend void PrintBreadth(Box box);
	double getVolume(void);

	static int objectCount;
	static int getCount();

	Box operator+(const Box& b);

private:
	double length;
	double breadth;
	double height;
	//double *lPtr;
};

