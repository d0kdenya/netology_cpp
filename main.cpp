#define MODE 1

#ifndef MODE
#   error "Необходимо определить MODE (0 — тренировка, 1 — боевой)"
#endif

#include <iostream>

#if MODE == 1
int add(int a, int b)
{
    return a + b;
}
#endif

int main()
{
    system("chcp 65001 > nul");
#if MODE == 0
    std::cout << "Работаю в режиме тренировки\n";

#elif MODE == 1
    std::cout << "Работаю в боевом режиме\n";
    int x{}, y{};
    std::cout << "Введите число 1: ";
    std::cin  >> x;
    std::cout << "Введите число 2: ";
    std::cin  >> y;

    std::cout << "Результат сложения: " << add(x, y) << '\n';

#else
    std::cout << "Неизвестный режим. Завершение работы\n";
#endif
    return 0;
}
