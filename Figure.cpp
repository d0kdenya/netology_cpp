#include "Figure.h"
#include <iostream>

Figure::Figure(const std::string& n, int s) : name_(n), sides_count_(s) {}
Figure::Figure() : Figure("Фигура", 0) {}

bool Figure::check() const { return sides_count_ == 0; }

void Figure::print_info() const
{
    std::cout << name_ << ":\n"
              << (check() ? "Правильная\n" : "Неправильная\n")
              << "Количество сторон: " << sides_count_ << '\n';
}
