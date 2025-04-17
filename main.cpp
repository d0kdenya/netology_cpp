#include <iostream>
#include <string>
#include "greeter.h"

int main()
{
    system("chcp 65001 > nul");

    std::cout << "Введите имя: ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << Greeter::greet(name) << '\n';
    return 0;
}
