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
		cout << "AggregateT ����� ���� ������" << endl;
	}
	~AggregateT()
	{
		setlocale(LC_ALL, "Russian");
		cout << "AggregateT �������� ���� ������" << endl;
	}
};

