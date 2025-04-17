#include <iostream>
#include <limits>
#include <string>

struct bad_length { };

int get_length_or_throw(const std::string& str, int forbidden_length)
{
    int len = static_cast<int>(str.length());
    if (len == forbidden_length)
        throw bad_length{};
    return len;
}

int main()
{
    system("chcp 65001 > nul");

    int forbidden{};
    std::cout << "Введите запретную длину: ";
    std::cin  >> forbidden;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (true)
    {
        std::string word;
        std::cout << "Введите слово: ";
        std::getline(std::cin, word);

        try
        {
            int len = get_length_or_throw(word, forbidden);
            std::cout << "Длина слова \"" << word << "\" равна " << len << '\n';
        }
        catch (const bad_length&)
        {
            std::cout << "Вы ввели слово запретной длины! До свидания\n";
            break;
        }
    }
    return 0;
}
