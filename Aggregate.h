#pragma once  
#include "Test.h"
#include <clocale>
class Aggregate
{
public:
	Test m_objTest;

	Aggregate()
	{
		setlocale(LC_ALL, "Russian");
		cout << "Aggregate начал свою работу" << endl;
	}
	~Aggregate()
	{
		setlocale(LC_ALL, "Russian");
		cout << "Aggregate закончил свою работу" << endl;
	}
};

