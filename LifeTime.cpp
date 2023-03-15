#include <iostream>
#include "Test.h"
#include "Child.h"
#include "Aggregate.h"
#include "AggregateT.h"
using namespace std;
int Test::nCount = 0;
Test test(1,2);
Child ch;
//Aggregate ag;
//AggregateT<Test> agr;					
//AggregateT<Child> agrt;
int main()
{
	
	cout << "Before" << endl;
	/*Test();
	Test *p = new Test;
	delete p;*/
	/*Test* t = new Test[2];
	delete[] t;*/
	cout << "After"<<endl;
	/*test.foo(t[1]);*/

}
