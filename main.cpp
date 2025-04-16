#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>

class Counter {
private:
    int value;

public:
    Counter() : value(1) {}

    explicit Counter(int init) : value(init) {}

    void increment() {
        ++value;
    }

    void decrement() {
        --value;
    }

    int getValue() const {
        return value;
    }
};

int main() {
    system("chcp 65001 > nul");

    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::string answer;
    std::getline(std::cin, answer);

    for (auto &c : answer) c = static_cast<char>(std::tolower(c));

    Counter counter;

    if (answer == "да") {
        int init;
        while (true) {
            std::cout << "Введите начальное значение счётчика: ";
            if (!(std::cin >> init)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Неверный ввод! Попробуйте ещё раз.\n";
                continue;
            }
            break;
        }
        counter = Counter(init);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    while (true) {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        char cmd;
        std::cin >> cmd;

        switch (cmd) {
            case '+':
                counter.increment();
                break;
            case '-':
                counter.decrement();
                break;
            case '=':
                std::cout << counter.getValue() << "\n";
                break;
            case 'x':
                std::cout << "До свидания!\n";
                return 0;
            default:
                std::cout << "Неверная команда\n";
        }
    }

    return 0;
}
