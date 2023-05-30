#include "GoodSufTbl.h"

GoodSufTbl::GoodSufTbl()
    : pss(nullptr)
    , z(nullptr)
    , N(0)
    , cmpCount(0)

{
}

GoodSufTbl::~GoodSufTbl()
{
    if (pss)
    {
        delete[] pss;
        pss = nullptr;
    }
    if (z)
    {
        delete[] z;
        z = nullptr;
    }
}

void GoodSufTbl::suffShift(int* suff, const char* str, int len)
{
    // ������������ ������� ���������
    int i, j, k;
    for (i = 0; i < len; i++)
        suff[i] = len;
    k = 0;
    for (j = len - 1; j >= 0; j--)
    {
        if (z[j] == j + 1)
        {
            for (; k < len - 1 - j; k++)
                if (suff[k] == len)
                    suff[k] = len - 1 - j;
        }
    }
    for (i = 0; i < len - 1; i++)
        suff[len - 1 - z[i]] = len - 1 - i;
}

void GoodSufTbl::zInv(int* z, const char* str, int len)
{
    cmpCount = 0; 

    
    int last[256];
    for (int i = 0; i < 256; i++)
        last[i] = -1;
    for (int i = 0; i < len; i++)
        last[static_cast<unsigned char>(str[i])] = i;

    
    for (int i = len - 1; i >= 0; i--)
    {
        int j = last[static_cast<unsigned char>(str[i])];
        if (j < i)
        {
            z[i] = i - j;
            cmpCount++; 
        }
        else
        {
            z[i] = 0;
        }
        for (j = i - z[i] - 1; j >= 0 && str[j] == str[j + z[i]]; j--)
        {
            z[i]++;
        }
    }
}



void GoodSufTbl::Init(const char* str)
{
    // ������� ������ �� ���������� �������������
    if (pss)
    {
        delete[] pss;
        pss = nullptr;
    }
    if (z)
    {
        delete[] z;
        z = nullptr;
    }
    cmpCount = 0; // ���������� ������� ��������� ��������

    // ������������ ����� ������
    N = static_cast<int>(strlen(str));

    // �������� ������ ��� �������
    pss = new int[N];
    z = new int[N];

    // ������������ ��������������� z-�������
    zInv(z, str, N);

    // ������������ ������� ���������
    suffShift(pss, str, N);
}
