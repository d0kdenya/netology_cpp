#include <iostream>

enum class Month {
    January   = 1,
    February  = 2,
    March     = 3,
    April     = 4,
    May       = 5,
    June      = 6,
    July      = 7,
    August    = 8,
    September = 9,
    October   = 10,
    November  = 11,
    December  = 12
};

int main() {
    system("chcp 65001 > nul");

    int m;
    while (true) {
        std::cout << "Введите номер месяца: ";
        if (!(std::cin >> m)) {
            std::cout << "До свидания\n";
            break;
        }

        if (m == 0) {
            std::cout << "До свидания\n";
            break;
        }

        Month month = static_cast<Month>(m);
        switch (month) {
            case Month::January:   std::cout << "Январь\n";    break;
            case Month::February:  std::cout << "Февраль\n";   break;
            case Month::March:     std::cout << "Март\n";      break;
            case Month::April:     std::cout << "Апрель\n";    break;
            case Month::May:       std::cout << "Май\n";       break;
            case Month::June:      std::cout << "Июнь\n";      break;
            case Month::July:      std::cout << "Июль\n";      break;
            case Month::August:    std::cout << "Август\n";    break;
            case Month::September: std::cout << "Сентябрь\n";  break;
            case Month::October:   std::cout << "Октябрь\n";   break;
            case Month::November:  std::cout << "Ноябрь\n";    break;
            case Month::December:  std::cout << "Декабрь\n";   break;
            default:
                std::cout << "Неправильный номер!\n";
        }
    }
    return 0;
}