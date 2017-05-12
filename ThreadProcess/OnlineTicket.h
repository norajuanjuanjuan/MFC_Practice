#pragma once
class OnlineTicket
{
public:
	OnlineTicket(void);
	~OnlineTicket(void);

	void myThreadA();
	void myThreadB();
	void Display(void);

	int tickets;
	int countA;
	int countB;

};

