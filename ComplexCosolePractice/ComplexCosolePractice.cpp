// ComplexCosolePractice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <csignal>
#include <windows.h>
#include <iostream>
using namespace std;

#define DEBUG
#define MIN(a,b) (((a)<(b))?a:b)
#define MKSTR(x) #x

template <typename T>
 T const& Max(T const& a,T const& b)
{
	return a<b?b:a;
}

 template<class T>
 class Stack
 {
 public:
	 Stack();
	 ~Stack();
	 void push(T const&);
	 void pop();
	 T top() const;
	 bool empty() const
	 {
		 return elems.empty();
	 }
 private:
	 vector<T> elems;
 };
 template<class T>
 Stack<T>::Stack()
 {
 }
  template<class T>
 Stack<T>::~Stack()
 {
 }

  template<class T>
  void Stack<T>::push(T const& elem)
  {
	  elems.push_back(elem);
  }

  template<class T>
  void Stack<T>::pop()
  {
	  if(elems.empty())
	  {
		  throw out_of_range("Stack<>::pop():empty stack");
	  }
	  elems.pop_back();
  }

  template<class T>
  T Stack<T>::top() const
  {
	  if(elems.empty())
	  {
		  throw out_of_range("Stack<>::top():empty stack");
	  }
	  return elems.back();
  }

  //void signalHandler(int signum)
  //{
	 // cout<<"Interrupt signal ("<<signum<<") received. \n";
	 // exit(signum);//清理关闭 终止程序
  //}

int _tmain(int argc, _TCHAR* argv[])
{
	int i=39;
	int j=20;
	cout<<"Max(i,j):"<<Max(i,j)<<endl;

	double f1=13.5;
	double f2=20.7;
	cout<<"Max(f1,f2):"<<Max(f1,f2)<<endl;

	string s1="Hello";
	string s2="World";
	cout<<"Max(s1,s2):"<<Max(s1,s2)<<endl;

	try
	{
	Stack<int> intStack;
	Stack<string> stringStack;

	intStack.push(7);
	cout<<intStack.top()<<endl;

	stringStack.push("Hello");
	cout<<stringStack.top()<<endl;
	stringStack.pop();
	//stringStack.pop();
	}
	catch(exception const& ex)
	{
		cerr<<"Exception:"<<ex.what()<<endl;
	}

#ifdef DEBUG
	cerr<<"Trace: Inside main function"<<endl;
#endif
//#if 0
	cout<<MKSTR(Hello C++)<<endl;
//#endif
#ifdef DEBUG
	cerr<<"Trace:Coming out of main function"<<endl;
#endif

	cout<<"Value of __LINE__:"<<__LINE__<<endl;
	cout<<"Value of __FILE__:"<<__FILE__<<endl;
	cout<<"Value of __DATE__:"<<__DATE__<<endl;
	cout<<"Value of __TIME__:"<<__TIME__<<endl;

	/*int s=0;
	signal(SIGINT,signalHandler);
	while(++s)
	{
		cout<<"Going to sleep ...."<<endl;
		if(s==3) raise(SIGINT);
		Sleep(1000);
	}*/

	cin.clear();
	cin.sync();
	cin.get();
	return 0;
}


