#pragma once
#include <iostream>
#include <clocale>
using namespace std;

class Test
{
public:
	static int nCount;
	
	Test(int num1, int num2)
	{
		setlocale(LC_ALL, "Russian");
		/*nCount++;*/
		cout << "Конструктор с параметром" << endl;
		/*cout << nCount << endl;*/
		int num3 = num1 + num2;
		cout << num3 << endl;
	}
	/*Test()
	{
		setlocale(LC_ALL, "Russian");
		nCount++;
		cout << "Объект сотворен" << endl;
		cout << nCount << endl;
	}

	~Test()
	{
		setlocale(LC_ALL, "Russian");
		nCount--;
		cout << "Объект уничтожен" << endl;
		cout << nCount << endl;
	}
	Test(const Test& t)
	{
		setlocale(LC_ALL, "Russian");
		nCount++;
		cout << "Конструктор копирования создан" << endl;
		cout << nCount << endl;
	}*/
	void foo(Test t)
	{
		nCount++;
		cout << "foo is running"<<endl;
		cout << nCount << endl;
	}
	
};

			