#include "RightTriangle.h"

RightTriangle::RightTriangle(int a,int b,int c,int A,int B)
    : Triangle("Прямоугольный треугольник", a,b,c, A,B,90)
{
    if (C_ != 90)
        throw FigureError("угол C не равен 90");
}
