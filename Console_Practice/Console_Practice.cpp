// Console_Practice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Box.h"
#include "Rectangle.h"
#include "TriAngle.h"
#include "FileOp.h"
#include "DynamicMemoryAllocation.h"
#include <exception>
using namespace std;

//void printBook(struct Books book);

//struct Books
//{
//	char title[50];
//	char author[50];
//	char subject[100];
//	int book_id;
//};

typedef struct
{
	char title[50];
	char author[50];
	char subject[100];
	int book_id;
}Books;

struct MyException:public exception
{
	const char * what() const throw()
	{
		return "C++ Exception";
	}
};

void printBook(Books book );
void printBook(Books *book );
int Box::objectCount;
void CatchException();
int _tmain(int argc, _TCHAR* argv[])
{
	/*char str[]="Hello C++";
	cout<<"Value of str is:"<<str<<endl;

    char str_error[]="Unable to read....";
	cerr <<"Error Message :"<<str_error <<endl;
	clog<<"Error Message :"<<str_error<<endl;*/

	Books Book1;

	strcpy(Book1.title,"C++教程");
	strcpy(Book1.author,"Nora");
	strcpy(Book1.subject,"编程语言");
	Book1.book_id=123;
	printBook(Book1);
	printBook(&Book1 );

	Box::objectCount=0;
	Box Box1(6.0,5.0,13.0) ;
	double volume=0.0;

	/*Box1.length=6.0;
	Box1.height=5.0;
	Box1.breadth=13.0;*/
	volume=Box1.getVolume();
	cout<<"Box1的体积为："<<volume<<endl;
	Box Box2=Box1;//调用拷贝构造函数
	cout<<"Box2的体积为："<<Box2.getVolume()<<endl;
	PrintBreadth(Box1);//friend
	cout<<"重载运算符+所得Box体积："<<(Box1.operator+(Box2)).getVolume()<<endl;

	Box *ptrBox=&Box1;
	cout<<"ptrBox所指向box的体积为："<<ptrBox->getVolume()<<endl;

	cout<<Box::getCount()<<endl;

	Rectangle rect;
	rect.setWidth(5);
	rect.setHeight(7);
	cout<<"Total Area is "<<rect.getArea()<<endl;
	cout<<"Total paint cost is ($): "<<rect.getCost(rect.getArea())<<endl;

	/*char* s="abc";
	int i=1;
	int* iPtr=&i;
	cout<<"*s:"<<*s<<endl;
	cout<<"s:"<<static_cast<void*>(s)<<endl;
	cout<<"*iPtr："<<*iPtr<<endl;
	cout<<"iPtr:"<<iPtr<<endl;*/

	TriAngle tri;
	tri.setHeight(10);
	tri.setWidth(5);

	Shape *shape;
	shape=&rect;
	shape->printAreaInfo();
	shape=&tri;
	shape->printAreaInfo();

	FileOp file;
	file.OpenFile();

	CatchException();

	DynamicMemoryAllocation dma;
	dma.Mallocate();

	cin.clear();
	cin.sync();
	cin.get();
	return 0;
}


void printBook(Books book )
{
	cout<<"书名："<<book.title<<endl;
	cout<<"作者："<<book.author<<endl;
	cout<<"类目："<<book.subject<<endl;
	cout<<"ID:"<<book.book_id<<endl;
}

void printBook(Books *book )
{
	cout<<"书名："<<book->title<<endl;
	cout<<"作者："<<book->author<<endl;
	cout<<"类目："<<book->subject<<endl;
	cout<<"ID:"<<book->book_id<<endl;
}

void CatchException()
{
	try
	{
		throw MyException();
	}
	catch(MyException &e)
	{
		cout<<"MyException caught"<<endl;
		cout<<e.what()<<endl;
	}
	catch(exception &e)
	{}
}
