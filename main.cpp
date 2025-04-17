#include <iostream>

#define SUB(x, y)   ((x) - (y))

int main()
{
    int a = 6;
    int b = 5;
    int c = 2;

    std::cout << SUB(a, b)             << '\n';
    std::cout << SUB(a, b) * c         << '\n';
    std::cout << SUB(a, b + c) * c     << '\n';
    return 0;
}
