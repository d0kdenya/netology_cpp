#include "Quadrangle.h"
#include <iostream>

Quadrangle::Quadrangle(const std::string& n,
                       int a,int b,int c,int d,
                       int A,int B,int C,int D)
    : Figure(n,4), a_(a),b_(b),c_(c),d_(d),
      A_(A),B_(B),C_(C),D_(D)
{
    if (A_+B_+C_+D_ != 360)
        throw FigureError("сумма углов не равна 360");
}

void Quadrangle::print() const
{
    std::cout << name_
              << " (стороны "
              << a_ << ", " << b_ << ", " << c_ << ", " << d_
              << "; углы "
              << A_ << ", " << B_ << ", " << C_ << ", " << D_
              << ") создан\n";
}
