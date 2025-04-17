#include "Triangle.h"
#include <iostream>

Triangle::Triangle(const std::string& n,
                   int a,int b,int c,
                   int A,int B,int C)
    : Figure(n,3), a_(a),b_(b),c_(c),A_(A),B_(B),C_(C)
{
    if (A_ + B_ + C_ != 180)
        throw FigureError("сумма углов не равна 180");
}

void Triangle::print() const
{
    std::cout << name_
              << " (стороны "
              << a_ << ", " << b_ << ", " << c_
              << "; углы "
              << A_ << ", " << B_ << ", " << C_ << ") создан\n";
}
