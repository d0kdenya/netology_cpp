#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <limits>
#include "counter.h"

static std::string to_lower(std::string s)
{
    for (char &c : s) c = static_cast<char>(std::tolower(c));
    return s;
}

int main()
{
    system("chcp 65001 > nul");

    std::cout << "Вы хотите указать начальное значение счётчика? "
                 "Введите да или нет: ";
    std::string answer;
    std::getline(std::cin, answer);

    Counter cnt;

    if (to_lower(answer) == "да")
    {
        int init{};
        while (true)
        {
            std::cout << "Введите начальное значение счётчика: ";
            if (std::cin >> init) break;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Неверный ввод!\n";
        }
        cnt = Counter(init);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    char cmd;
    while (true)
    {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> cmd;

        switch (cmd)
        {
            case '+': cnt.increment(); break;
            case '-': cnt.decrement(); break;
            case '=': std::cout << cnt.get() << '\n'; break;
            case 'x': std::cout << "До свидания!\n";  return 0;
            default : std::cout << "Неверная команда\n";
        }
    }
}
