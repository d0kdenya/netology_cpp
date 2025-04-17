#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <cstdlib>

class Address {
private:
    std::string city, street;
    int house, apartment;

public:
    Address(const std::string& c,
            const std::string& s,
            int h,
            int a)
        : city(c), street(s), house(h), apartment(a) {}

    std::string toString() const {
        return city + ", " + street + ", "
             + std::to_string(house) + ", "
             + std::to_string(apartment);
    }
    const std::string& getCity() const { return city; }
};

void sort(std::vector<Address>& arr) {
    for (std::size_t i = 0; i + 1 < arr.size(); ++i)
        for (std::size_t j = 0; j + 1 < arr.size() - i; ++j)
            if (arr[j].getCity() > arr[j + 1].getCity())
                std::swap(arr[j], arr[j + 1]);
}

int main() {
    system("chcp 65001 > nul");

    std::ifstream in("../in.txt");
    if (!in) {
        std::cerr << "Не удалось открыть in.txt\n";
        return 1;
    }

    int N;
    in >> N;
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::vector<Address> arr;
    arr.reserve(N);

    for (int i = 0; i < N; ++i) {
        std::string city, street;
        int house, apt;

        std::getline(in, city);
        std::getline(in, street);
        in >> house >> apt;
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        arr.emplace_back(city, street, house, apt);
    }
    in.close();

    sort(arr);

    std::ofstream out("../out.txt");
    if (!out) {
        std::cerr << "Не удалось открыть out.txt\n";
        return 1;
    }

    out << N << '\n';
    for (const auto& a : arr)
        out << a.toString() << '\n';

    return 0;
}
