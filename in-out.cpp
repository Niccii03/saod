
#include <iostream>
#include <math.h> 
using namespace std;

int main()
{
	int x, y;
	cout << "x = "; cin >> x; // Подсказка и ввод х
	cout << "y = "; cin >> y; // Подсказка и ввод y
	cout << x << " + " << y << " = " << x + y << endl;
	cout << x << " - " << y << " = " << x - y << endl;
	cout << x << " * " << y << " = " << x * y << endl;
	cout << x << " / " << y << " = " << x / y << endl;
	cout << x << " % " << y << " = " << x % y << endl;
	cout << x << " ^ " << y << " = " << pow(x,y) << endl;
}
	