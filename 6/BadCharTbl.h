#pragma once
#include <string.h>

class BadCharTbl {
public:
    BadCharTbl();
    int operator[] (unsigned char c) const;
    void Init(const char* s);
private:
    int badChar[256];
};

inline BadCharTbl::BadCharTbl() {
    // пустой конструктор
}

inline int BadCharTbl::operator[] (unsigned char c) const {
    return badChar[c];
}

inline void BadCharTbl::Init(const char* s) {
    for (int i = 0; i < 256; i++) {
        badChar[i] = -1;
    }
    int len = strlen(s);
    for (int i = 0; i < len - 1; i++) {
        badChar[(unsigned char)s[i]] = len - 1 - i;
    }
}
