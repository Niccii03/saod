#include <cstring>
#include <algorithm>

class GoodSufTbl
{
public:
    GoodSufTbl();
    ~GoodSufTbl();
    void Init(const char* str);
    int operator[] (int i) const { return pss[i]; }
    operator int() const { return N; }
    int CmpCount() const { return cmpCount; }
    int GetSize() const { return N; }

private:
    void suffShift(int* suff, const char* str, int len);
    void zInv(int* z, const char* str, int len);
    int* pss;
    int* z;
    int N;
    int cmpCount;
};
