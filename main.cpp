#include <iostream>
#include <fstream>
#include <string>
#include <limits>

class Address {
private:
    std::string city;
    std::string street;
    int house;
    int apartment;

public:
    Address(const std::string& city_,
            const std::string& street_,
            int house_,
            int apartment_)
        : city(city_), street(street_),
          house(house_), apartment(apartment_)
    {}

    std::string get_output_address() const {
        return city + ", " +
               street + ", " +
               std::to_string(house) + ", " +
               std::to_string(apartment);
    }
};

int main() {
    system("chcp 65001 > nul");

    std::ifstream in("../in.txt");
    if (!in) {
        std::cerr << "Не удалось открыть файл in.txt для чтения\n";
        return 1;
    }

    int N;
    in >> N;
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Address** arr = new Address*[N];

    for (int i = 0; i < N; ++i) {
        std::string city, street;
        int house, apartment;

        std::getline(in, city);
        std::getline(in, street);
        in >> house >> apartment;
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        arr[i] = new Address(city, street, house, apartment);
    }
    in.close();

    std::ofstream out("../out.txt");
    if (!out) {
        std::cerr << "Не удалось открыть файл out.txt для записи\n";
        for (int i = 0; i < N; ++i) delete arr[i];
        delete[] arr;
        return 1;
    }

    out << N << "\n";
    for (int i = N - 1; i >= 0; --i) {
        out << arr[i]->get_output_address() << "\n";
    }
    out.close();

    for (int i = 0; i < N; ++i) {
        delete arr[i];
    }
    delete[] arr;

    return 0;
}