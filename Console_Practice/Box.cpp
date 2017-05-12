#include "stdafx.h"
#include "Box.h"
#include<iostream>
using namespace std;

Box::Box()
{}

Box::Box(double len,double h,double b)
{
	cout<<"调用构造函数并为指针lPtr分配内存"<<endl;
	length=len;
	height=h;
	breadth=b;
	//lPtr=new double;
	//*lPtr=len;
	objectCount++;
}

//Box::Box(const Box &obj)
//{
//	cout<<"调用拷贝构造函数并为指针lPtr分配内存"<<endl;
//	length=obj.length;
//	height=obj.height;
//	breadth=obj.breadth;
//	lPtr=new double;
//	*lPtr=*obj.lPtr;//拷贝值
//	objectCount++;
//}

Box::~Box(void)
{
	cout<<"Object is being deleted"<<endl;
	/*delete lPtr;*/
	cin.clear();
	cin.sync();
	cin.get();
}
 double Box:: getVolume(void)
{
  return length * breadth * height;
}

 void PrintBreadth(Box box)
 {
	 cout<<"Breadth of box:"<<box.breadth<<endl;
 }

  int  Box::getCount()
  {
	 return objectCount;
  }

  Box Box:: operator+(const Box& b)
  {
	  Box box;
	  box.length=this->length+b.length;
	  box.breadth=this->breadth+b.breadth;
	  box.height=this->height+b.height;
	  return box;
  }