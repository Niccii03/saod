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
		cout << "Aggregate ����� ���� ������" << endl;
	}
	~Aggregate()
	{
		setlocale(LC_ALL, "Russian");
		cout << "Aggregate �������� ���� ������" << endl;
	}
};

