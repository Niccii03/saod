#include <iostream>
#include "Str.h"

using namespace std;

void Test(Str s) {}
int main()
{
    Str s = "123";
    cout << s << endl << strlen(s) << endl;
    Test(s);
    cout << s << endl << strlen(s) << endl;
    Str t;
    t = s = t; //t ������������� ������� s, ������� ������������� �������� t ������ "". ��������� ������ ������ � ����� ������ ������ ����;
    cout << t << endl << strlen(t) << endl;
    Str l = "lp", g = "gka";
    cout << l << " " << g << endl;
    l += g;
    cout << l << endl << strlen(l) << endl;
    Str m;
    m = l + g;
    cout << m << endl;
}
