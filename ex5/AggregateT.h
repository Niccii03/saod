#pragma once
#include "Test.h"
#include <clocale>
template <typename T> class AggregateT
{
public:
	T m_objecct;
	AggregateT()
	{
		setlocale(LC_ALL, "Russian");
		cout << "AggregateT начал свою работу" << endl;
	}
	~AggregateT()
	{
		setlocale(LC_ALL, "Russian");
		cout << "AggregateT закончил свою работу" << endl;
	}
};

