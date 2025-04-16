#include <iostream>
#include <string>
#include <limits>

struct Account {
    int number;
    std::string owner;
    double balance;
};

void updateBalance(Account &acc, double newBalance) {
    acc.balance = newBalance;
}

int main() {
    system("chcp 65001 > nul");

    Account acc;

    std::cout << "Введите номер счёта: ";
    std::cin >> acc.number;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Введите имя владельца: ";
    std::getline(std::cin, acc.owner);

    std::cout << "Введите баланс: ";
    std::cin >> acc.balance;

    double newBal;
    std::cout << "Введите новый баланс: ";
    std::cin >> newBal;

    updateBalance(acc, newBal);

    std::cout << "Ваш счёт: "
              << acc.owner << ", "
              << acc.number << ", "
              << acc.balance
              << std::endl;

    return 0;
}