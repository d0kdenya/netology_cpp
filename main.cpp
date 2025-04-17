#include <iostream>
#include <string>

int main()
{
    system("chcp 65001 > nul");

    std::string name;
    std::cout << "Введите имя: ";
    std::getline(std::cin, name);

    std::cout << "Здравствуйте, " << name << "!\n";
    return 0;
}