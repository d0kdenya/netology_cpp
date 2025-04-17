#include "EquilateralTriangle.h"

EquilateralTriangle::EquilateralTriangle(int a)
    : Triangle("Равносторонний треугольник", a,a,a, 60,60,60) {}

bool EquilateralTriangle::check() const
{
    return Triangle::check() && a_ == b_ && b_ == c_ && A_ == 60;
}
