#include "Quadrangle.h"
#include <iostream>

Quadrangle::Quadrangle(const std::string& n,
                       int a,int b,int c,int d,
                       int A,int B,int C,int D)
    : Figure(n,4), a_(a),b_(b),c_(c),d_(d),A_(A),B_(B),C_(C),D_(D) {}

bool Quadrangle::check() const { return A_+B_+C_+D_ == 360; }

void Quadrangle::print_info() const
{
    Figure::print_info();
    std::cout << "Стороны: a=" << a_ << " b=" << b_
              << " c=" << c_ << " d=" << d_ << '\n'
              << "Углы:   A=" << A_ << " B=" << B_
              << " C=" << C_ << " D=" << D_ << "\n\n";
}
