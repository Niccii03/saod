#include <iostream>
#include "BadCharTbl.h"
#include "GoodSufTbl.h"

using namespace std;

int main()
{
    // Создание объектов таблиц плохих символов и хороших суффиксов
    BadCharTbl ctbl;
    GoodSufTbl stbl;

    // Инициализация таблицы плохих символов
    ctbl.Init("karakara");

    // Вывод значений таблицы плохих символов
    for (int i = 0; i < 256; i++)
    {
        if (ctbl[i] != -1)
        {
            cout << (char)i << '\t' << ctbl[i] << endl;
        }
    }

    // Инициализация таблицы хороших суффиксов
    const char* s = "abacabadabacaba";
    stbl.Init(s);

    // Вывод значений таблицы хороших суффиксов
    for (int i = 0; i < stbl.GetSize(); i++)
    {
        cout <<stbl[i] << " ";
    }
    cout << endl;
    cout << endl;
    const int N = 100;
    char s1[N]{ 0 };
    for (int i = 0; i < N - 1; i++)
        s1[i] = rand() % ('z' - 'a' + 1) + 'a';
    for (int i = 0; i < N; i++)
    {
        cout << s1[i] << " ";
    }
    stbl.Init(s1);
    for (int i = 0; i < stbl.GetSize(); i++)
    {
        cout << stbl[i] << " ";
    }

    return 0;
}
