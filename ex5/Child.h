#pragma once
#include "Test.h"
#include <clocale>
#include <iostream>
class Child : public Test
{
public:
	Child()
	{
		setlocale(LC_ALL, "Russian");
		cout << "Child начал свою работу" << endl;
	}
	~Child()
	{
		setlocale(LC_ALL, "Russian");
		cout << "Child закончил свою работу" << endl;
	}
};

