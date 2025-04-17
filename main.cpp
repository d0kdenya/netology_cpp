#include <iostream>
#include <limits>
#include <cstdlib>

class Calculator {
private:
    double num1 = 0.0;
    double num2 = 0.0;

public:
    bool set_num1(double n) {
        if (n == 0.0) return false;
        num1 = n;
        return true;
    }
    bool set_num2(double n) {
        if (n == 0.0) return false;
        num2 = n;
        return true;
    }

    double add()          const { return num1 + num2; }
    double multiply()     const { return num1 * num2; }
    double subtract_1_2() const { return num1 - num2; }
    double subtract_2_1() const { return num2 - num1; }
    double divide_1_2()   const { return num1 / num2; }
    double divide_2_1()   const { return num2 / num1; }
};

int main() {
    system("chcp 65001 > nul");

    Calculator calc;
    double value;

    while (true) {
        while (true) {
            std::cout << "Введите num1: ";
            if (!(std::cin >> value)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Неверный ввод!\n";
                continue;
            }
            if (!calc.set_num1(value)) {
                std::cout << "Неверный ввод!\n";
                continue;
            }
            break;
        }

        while (true) {
            std::cout << "Введите num2: ";
            if (!(std::cin >> value)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Неверный ввод!\n";
                continue;
            }
            if (!calc.set_num2(value)) {
                std::cout << "Неверный ввод!\n";
                continue;
            }
            break;
        }

        std::cout << "num1 + num2 = "   << calc.add()          << "\n";
        std::cout << "num1 - num2 = "   << calc.subtract_1_2() << "\n";
        std::cout << "num2 - num1 = "   << calc.subtract_2_1() << "\n";
        std::cout << "num1 * num2 = "   << calc.multiply()     << "\n";
        std::cout << "num1 / num2 = "   << calc.divide_1_2()   << "\n";
        std::cout << "num2 / num1 = "   << calc.divide_2_1()   << "\n\n";
    }

    return 0;
}
