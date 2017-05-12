// STL_Practice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <array>
#include <iterator>
#include <algorithm>
#include <map>
#include <list>
#include <string>
#include <deque>
#include <set>
#include <stack>
using namespace std;

template<class T,class U>
	void Multiply(T t,U u)
	{
		auto v=t*u;
	}

	template <typename T1,typename T2>
	auto compose(T1 t1,T2 t2)->decltype(t1+t2)
	{
		return t1+t2;
	}

int _tmain(int argc, _TCHAR* argv[])
{
	/*vector<int> vec;
	int i;
	cout<<"vector size ="<<vec.size()<<endl;
	for(i=0;i<5;i++)
	{
		vec.push_back(i);
	}
	cout<<"extended vector size ="<<vec.size()<<endl;

	for(int i=0;i<5;i++)
	{
		cout << "value of vec ["<<i<<"] ="<<vec[i]<<endl;
	}

	vector<int>::iterator v=vec.begin();
	while (v!=vec.end())
	{
		cout<<"value of v ="<<*v<<endl;
		v++;
	}*/

	array<int,3> a1={1,2,3};
	array<int,3> a2={1,2,3};
	array<std::string,2> a3={"a","b"};

	sort(a1.begin(),a1.end());
	sort(a2.rbegin(),a2.rend());
	reverse_copy(a2.begin(),a2.end(),
		ostream_iterator<int>(cout," "));

	cout<<'\n';
	for(const auto& s: a3)
	{
        std::cout<< s << ' ';
		cout<<typeid(s).name()<<endl;
	}

	int a[9];
	auto j=a;
	cout<<typeid(j).name()<<endl;

	auto& k=a;
	cout<<typeid(k).name()<<endl;

	map<int,map<int,int>> map_;
	map<int,map<int,int>>::const_iterator itr1=map_.begin();
	const auto itr2=map_.begin();
	auto ptr=[](){cout<<"Hello world"<<endl;};

	auto v=compose(2,3.14);
	cout<<v<<endl;

	std::vector<int> vi;
	vi.push_back(25);
	vi.push_back(13);
	for(int n:vi)
	{
		cout<<n<<endl;
	}

	deque<int> d;
	d.push_front(1);
	d.push_front(25);
	d.push_back(13);
	for(int n:d)
		cout<<n<<endl;

	list<int> l;
	l.push_back(2);
	l.push_front(5);
	l.push_back(7);
	auto it=find(l.begin(),l.end(),5);
	if(it!=l.end()) l.insert(it,42);

	for(int n:l)
		cout<<n<<endl;

	int _a[]={1,2,3};
	set<int> s;
	set<int>::iterator iter;
	s.insert(_a,_a+3);
	for(iter=s.begin();iter!=s.end();++iter)
	{cout<<*iter<<endl;}
	cout<<endl;
	pair<set<int>::iterator,bool> pr;
	pr=s.insert(5);
	if(pr.second)
	{
		cout<<*pr.first<<endl;
	}

	cout<<*s.lower_bound(2)<<endl;
	cout<<*s.upper_bound(2)<<endl;

	map<const char*,int> m;
	m["aa"]=1;
	m["bb"]=2;
	m["cc"]=9;
    map<const char*,int>::iterator it1;
	it1=m.begin();
	const char* c=it1->first;
	cout<<"first element is :"<<c<<endl;
	while(it1!=m.end())
	{
		cout<<it1->first<<";"<<it1->second<<endl;
		++it1;
	}

	deque<int> mydeque(2,100);
	vector<int> myvector(2,200);
	stack<int> first;
	stack<int> second(mydeque);

	stack<int,vector<int>> third;
	stack<int,vector<int>> fourth(myvector);

	cout << "size of first: " << (int) first.size() << endl;  
    cout << "size of second: " << (int) second.size() << endl;  
    cout << "size of third: " << (int) third.size() << endl;  
    cout << "size of fourth: " << (int) fourth.size() << endl;  

	cin.clear();
	cin.sync();
	cin.get();

	return 0;
}

