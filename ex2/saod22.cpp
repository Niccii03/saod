#include <iostream>
#include "utils.h"

using namespace std;

int main()
{
	int a = 4, b = 5;
	cout << a << ' ' << b << endl;
	Swap(a, b);
	cout << a << ' ' << b << endl;


	/*int x = 3;
	int *p = &x;
	cout << x << "" << *p << "" << p << endl;
	p++;
	cout << p << endl;
	cout << p - &x << endl;
	typedef unsigned char byte;
	byte* pb = (byte*)--p;
	for (byte* pt = pb; pt - pb < sizeof(int); pt++)
		cout << (int)*pt << ' ';
	cout << endl;*/
}