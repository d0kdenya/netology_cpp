#include <iostream>
#include <limits>
#include <cstdlib>
#include "math_functions.h"

int main() {
    system("chcp 65001 > nul");

    double a, b;
    int op;

    std::cout << "Введите первое число: ";
    std::cin  >> a;
    std::cout << "Введите второе число: ";
    std::cin  >> b;

    std::cout << "Выберите операцию\n"
              << "(1 - сложение, 2 - вычитание, 3 - умножение,\n"
              << " 4 - деление, 5 - возведение в степень): ";
    std::cin >> op;

    try {
        double result{};
        switch (op) {
            case 1:  result = add(a, b);                    break;
            case 2:  result = sub(a, b);                    break;
            case 3:  result = mul(a, b);                    break;
            case 4:  result = divide(a, b);                 break;
            case 5:  result = power(a, b);                  break;
            default:
                std::cout << "Неизвестная операция!\n";
            return 0;
        }

        const char* msg[] = { "", " + ", " - ", " * ", " / ", " в степени " };
        if (op == 5)
            std::cout << a << msg[op] << b << " = " << result << '\n';
        else
            std::cout << a << msg[op] << b << " = " << result << '\n';
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << '\n';
    }

    return 0;
}
