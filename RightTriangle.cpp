#include "RightTriangle.h"

RightTriangle::RightTriangle(int a,int b,int c,int A,int B)
    : Triangle("Прямоугольный треугольник", a,b,c, A,B,90) {}

bool RightTriangle::check() const
{
    return Triangle::check() && C_ == 90;
}
