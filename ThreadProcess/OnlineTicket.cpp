#include "stdafx.h"
#include "OnlineTicket.h"
#include <iostream>
#include <thread>
#include <windows.h>
#include <mutex>
using namespace std;


std::mutex m_mutex;
OnlineTicket::OnlineTicket(void)
{
	tickets=100;
	countA=0;
	countB=0;
}


OnlineTicket::~OnlineTicket(void)
{
}

void OnlineTicket::Display()
{
	thread tA(&OnlineTicket::myThreadA,this);//创建一个分支线程，回调到myThread函数里
	thread tB(&OnlineTicket::myThreadB,this);
	tA.detach();
	tB.detach();
	cout<<"in major thread"<<endl;
}

void OnlineTicket::myThreadA()
{
	while(true)
	{
		lock_guard<mutex> lck(m_mutex);
		//m_mutex.lock();
		if(tickets>0)
		{
			Sleep(100);
			/*tickets--;*/
			/*++countA;*/
			cout<<"A Sell tickets["<<tickets--<<"]"<<endl;
			//m_mutex.unlock();
		}
		else
		{
			//m_mutex.unlock();
			break;
		}
	}
}

void OnlineTicket::myThreadB()
{
	while(true)
	{
		lock_guard<mutex> lck(m_mutex);
		//m_mutex.lock();
		if(tickets>0)
		{
			Sleep(100);
			/*tickets--;
			++countB;*/
			cout<<"B Sell tickets["<<tickets--<<"]"<<endl;
			//m_mutex.unlock();
		}
		else
		{
			//m_mutex.unlock();
			break;
		}
	}
}
