#pragma once

#include <mutex>
#include <condition_variable>

class ConditionVar
{
public:
	ConditionVar(void);
	~ConditionVar(void);
	void execute();

	int flag;
	void myfun( const int &num);
};

