#include "stdafx.h"
#include "FileOp.h"
#include <fstream>
#include <iostream>
using namespace std;

FileOp::FileOp(void)
{
}


FileOp::~FileOp(void)
{
}

void FileOp::OpenFile()
{
	char data[100];

	ofstream outfile;
	outfile.open("D:\\test.txt");

	cout<<"Writing to the file"<<endl;
	cout<<"Enter your name:";
	cin.getline(data,100);

	outfile<<data<<endl;
	cout<<"Enter your age:";
	cin>>data;
	cin.ignore();
	outfile<<data<<endl;

	outfile.close();

	ifstream infile;
	infile.open("D:\\test.txt");
	cout<<"Reading from the file"<<endl;
	infile>>data;

	cout<<data<<endl;
	infile>>data;
	cout<<data<<endl;
	infile.close();
}