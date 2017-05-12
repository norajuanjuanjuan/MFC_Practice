// ThreadProcess.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <thread>
#include <functional>
#include <iomanip>
#include <cstdint>
#include <future>
#include "OnlineTicket.h"
#include "ConditionVar.h"
using namespace std;

mutex m;  
condition_variable cond;  
int flag=10;  
void fun(int num){  
    for(int i=0;i<50;i++){  
    unique_lock<mutex> lk(m);//A unique lock is an object that manages a mutex object with unique ownership in both states: locked and unlocked.  
        while(flag!=num)  
            cond.wait(lk);//�ڵ���waitʱ��ִ��lk.unlock()  
        for(int j=0;j<num;j++)  
            cout<<j<<" ";  
        cout<<endl;  
        flag=(num==10)?100:10;  
        cond.notify_one();//���������̻߳��Ѻ�lk.lock()�ָ��ڵ���waitǰ��״̬  
    }  
}  

void thread_proc()
{
	cout<<"thread id="<<this_thread::get_id()<<endl;
}

//void func_test()
//{
//	cout<<"I'M the tester"<<endl;
//}

struct functor{
	void operator()(int a,int b){
		cout<<a<<"+"<<b<<"="<<a+b<<endl;
	}};

class C
{
	int data_;
public:
	C(int data):data_(data)//<=>C(int data){data_=data;} �ó�ʼ���б�����ʼ������
	{}
	void member_func(){
		cout<<"this->data_ ��"<<this->data_<<endl;
	}
};

uint32_t add(uint32_t a,uint32_t b)
{
	cout<<"thread id ="<<this_thread::get_id()<<",a="<<a<<",b="<<b<<endl;
	if(numeric_limits<uint32_t>::max()-a<b)
	{
		overflow_error("overflow_error");
	}
	return a+b;
}

void add_wrapper(promise<uint32_t> m_promise,uint32_t a,uint32_t b)
{
	try
	{
		m_promise.set_value(add(a,b));
	}
	catch(...)
	{
		m_promise.set_exception(current_exception());
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	thread td(thread_proc);//����thread���󼴴�����һ���µ��̲߳�ִ�У�
	td.join();//�ȴ��߳�ִ�н���

	thread 	td1([](int a,int b){
	cout<<a<<"+"<<b<<"="<<a+b<<endl;},1,2);//ʹ��Lambda���ʽ�����̶߳��󲢴��ݲ���1��2
	td1.join();

	thread td2(functor(),1,2);//ʹ��functor���󴴽��̶߳��󲢴��ݲ���1��2
	td2.join();

	functor myFunctor;
	myFunctor(1,2);

	C obj(10);
	thread td3(bind(&C::member_func,&obj));//bind���ʽ�󶨶������Ǿ�̬��Ա���� 
	td3.join();
	//�ȼ���obj.member_func();

	thread td4([&obj](){
		obj.member_func();//ʹ��Lambda���ʽ���ö���ķǾ�̬��Ա����
	});

	thread td5;
	cout << "td5.joinable() = " << boolalpha << td5.joinable() << endl;

	/*future<uint32_t> f1=async(launch::async,add,1ul,2ul);*/
	packaged_task<uint32_t(uint32_t,uint32_t)> task1(add);
	future<uint32_t> f1=task1.get_future();
	thread(move(task1),1ul,2ul).detach();
	//promise<uint32_t> promise1;
	//future<uint32_t> f1=promise1.get_future();
	// // �����߳�ִ��add�����İ�װ����
	//thread(add_wrapper, std::move(promise1),1ul,2ul).detach();

	// ͨ��std::future::get�ȴ��첽������ɲ�ȡ�÷���ֵ
	uint32_t sum1=f1.get();
	cout<<"thread id="<<this_thread::get_id()<<",sum1="<<sum1<<endl;
	//future<uint32_t> f2=async(launch::async,add, 4000000000ul, 4000000000ul);
	
	packaged_task<uint32_t(uint32_t,uint32_t)> task2(add);
	future<uint32_t> f2=task2.get_future();
	  std::thread(std::move(task2), 4000000000ul, 4000000000ul).detach();

	//promise<uint32_t> promise2;
	//future<uint32_t> f2=promise2.get_future();
	//thread(add_wrapper, std::move(promise2),4000000000ul, 4000000000ul).detach();

	// 4000000000ul + 4000000000ul���׳��쳣���쳣�ᱻ�ӳٵ�std::future::get��std::future::waitʱ�׳�
	try
	{
		uint32_t sum2=f2.get();
		cout<<"thread id="<<this_thread::get_id()<<",sum2="<<sum2<<endl;
	}
	catch(const overflow_error &e)
	{
		cout<<"thread id="<<this_thread::get_id()<<",e.what()"<<e.what()<<endl;
	}

	OnlineTicket ot;
	ot.Display();

	thread child(fun,11);  
    fun(10);  
    child.join();

	cin.clear();
	cin.sync();
	cin.get();
	return 0;
}

