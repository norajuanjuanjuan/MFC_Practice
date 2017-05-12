#include "stdafx.h"
#include "DynamicMemoryAllocation.h"
#include <iostream>
#include "Box.h"
using namespace std;

DynamicMemoryAllocation::DynamicMemoryAllocation(void)
{
	cout<<"调用构造函数"<<endl;
}


DynamicMemoryAllocation::~DynamicMemoryAllocation(void)
{
	cout<<"调用析构函数"<<endl;
}

void DynamicMemoryAllocation ::Mallocate()
{
	Box* myBoxArray=new Box[4];
	delete [] myBoxArray;
}