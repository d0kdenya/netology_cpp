#include <iostream>
#include <vector>
#include <cstdlib>

#include "Triangle.h"
#include "RightTriangle.h"
#include "IsoscelesTriangle.h"
#include "EquilateralTriangle.h"
#include "Quadrangle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Parallelogram.h"
#include "Rhombus.h"

static void print(const Figure* f) { f->print_info(); }

int main()
{
    system("chcp 65001 > nul");

    Triangle          tri("Треугольник", 10,20,30, 50,60,70);
    RightTriangle     badRT(10,20,30, 50,60);
    RightTriangle     goodRT(10,20,30, 50,40);
    IsoscelesTriangle badIso(10,20,50,60);
    EquilateralTriangle goodEqui(30);

    Quadrangle quad("Четырёхугольник", 10,20,30,40, 50,60,70,80);
    Rectangle  rect(10,20);
    Square     sq(20);
    Parallelogram badPar(20,30,30,40);
    Rhombus    badRh(30,30,40);

    std::vector<Figure*> figs = {
        &tri, &badRT, &goodRT, &badIso, &goodEqui,
        &quad, &rect, &sq, &badPar, &badRh
    };

    for (auto f : figs) print(f);
    return 0;
}
