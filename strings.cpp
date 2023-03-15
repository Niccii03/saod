#include <iostream>

using namespace std;

void string_copy(char* d, char* s)
{
	for (int i = 0; i < 32; i++)
	{
		*d++ = *s++;
	}
}
int len(const char* s) 
{
	return strlen(s);
}
int compare(const char* s, const char* t)
{
	if (s > t)
		return s - t;
	else if (s < t)
		return s - t;
	else if (s == t)
		return 0;
}
int main()
{
	char str[] = "Hello!";
	cout << str << endl;
	/*cout << strlen(str) << ' ' << sizeof(str) << endl;*/
	/*for (char* pd = t, *ps = str; *pd++ = *ps++;);*/
	char t[32];
	char* pd = t;
	char* ps = str;
	string_copy(pd, ps);
	cout <<  len(str) << endl;
	cout <<  compare(str,t) << endl;
	cout << t << endl;
}