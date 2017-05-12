#include "stdafx.h"
#include "ConditionVar.h"
#include <iostream>
#include <thread>
using namespace std;


	mutex mt;
	condition_variable cv;
ConditionVar::ConditionVar(void)
{
	flag=10;
}


ConditionVar::~ConditionVar(void)
{
}

void ConditionVar::myfun(const int &num)
{
	for(int i=0;i<50;i++)
	{
		unique_lock<mutex> lk(mt);
		while(flag!= num)
			cv.wait(lk);//在调用wait时会执行lk.unlock() 
		for(int j=0;j<num;j++)
			cout<<j<<" ";
		cout<<endl;
		flag=(num==10)?100:10;//被阻塞的线程唤醒后lk.lock()恢复在调用wait前的状态  
		cv.notify_one();
	}
}

void ConditionVar::execute()
{
	
}
