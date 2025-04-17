#include "Parallelogram.h"

Parallelogram::Parallelogram(int a,int b,int A,int B)
    : Quadrangle("Параллелограмм", a,b,a,b, A,B,A,B) {}

bool Parallelogram::check() const
{
    return Quadrangle::check() && a_==c_ && b_==d_ && A_==C_ && B_==D_;
}
