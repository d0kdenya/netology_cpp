#include <iostream>
#include <string>

struct Address {
    std::string city;
    std::string street;
    int house;
    int apartment;
    int zip;
};

void printAddress(const Address& addr) {
    std::cout << "Город: "        << addr.city      << '\n'
              << "Улица: "        << addr.street    << '\n'
              << "Номер дома: "   << addr.house     << '\n'
              << "Номер квартиры: "<< addr.apartment << '\n'
              << "Индекс: "       << addr.zip       << "\n";
}

int main() {
    system("chcp 65001 > nul");

    Address a1;
    a1.city      = "Москва";
    a1.street    = "Арбат";
    a1.house     = 12;
    a1.apartment = 8;
    a1.zip       = 123456;

    printAddress(a1);
    std::cout << '\n';

    Address a2{"Ижевск", "Пушкина", 59, 143, 953769};
    printAddress(a2);

    return 0;
}
