#include "stdafx.h"
#include "DynamicMemoryAllocation.h"
#include <iostream>
#include "Box.h"
using namespace std;

DynamicMemoryAllocation::DynamicMemoryAllocation(void)
{
	cout<<"���ù��캯��"<<endl;
}


DynamicMemoryAllocation::~DynamicMemoryAllocation(void)
{
	cout<<"������������"<<endl;
}

void DynamicMemoryAllocation ::Mallocate()
{
	Box* myBoxArray=new Box[4];
	delete [] myBoxArray;
}