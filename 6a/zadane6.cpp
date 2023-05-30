#include"Str.h"
#include <iostream>
using namespace std;

int main() {
    Str s("Hello, world!");

    std::cout << s.substr(7, 5) << std::endl; // "world"
    std::cout << s.substr(7, 20) << std::endl; // "world!"
    std::cout << s.substr(0, 6) << std::endl; // "Hello,"
    std::cout << s.substr(0, 0) << std::endl; // ""
    std::cout << s.substr(7, -3) << std::endl; // ""
    std::cout << s.substr(-3, 5) << std::endl; // "Hello"
    std::cout << s.substr(20, 5) << std::endl; // ""
    std::cout << s.substr(7, 6) << std::endl; // "world!"
    std::cout << s.substr(13, 5) << std::endl; // "!"
    std::cout << s.substr(0, 50) << std::endl; // "Hello, world!"

    return 0;
}
