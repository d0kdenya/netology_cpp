#include "Triangle.h"
#include <iostream>

Triangle::Triangle(const std::string& n,
                   int a, int b, int c,
                   int A, int B, int C)
    : Figure(n, 3), a_(a), b_(b), c_(c), A_(A), B_(B), C_(C) {}

bool Triangle::check() const
{
    return A_ + B_ + C_ == 180 && !Figure::check();
}

void Triangle::print_info() const
{
    Figure::print_info();
    std::cout << "Стороны: a=" << a_ << " b=" << b_ << " c=" << c_ << '\n'
              << "Углы:   A=" << A_ << " B=" << B_ << " C=" << C_ << "\n\n";
}
