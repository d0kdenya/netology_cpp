#include "Rectangle.h"

Rectangle::Rectangle(int a,int b)
    : Parallelogram(a,b,90,90)
{
    name_ = "Прямоугольник";
}

bool Rectangle::check() const
{
    return Parallelogram::check() && A_ == 90;
}
