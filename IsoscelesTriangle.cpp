#include "IsoscelesTriangle.h"

IsoscelesTriangle::IsoscelesTriangle(int a,int b,int A,int B)
    : Triangle("Равнобедренный треугольник", a,b,a, A,B,A) {}

bool IsoscelesTriangle::check() const
{
    return Triangle::check() && a_ == c_ && A_ == C_;
}
