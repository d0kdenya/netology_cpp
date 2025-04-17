#include <iostream>
#include <vector>
#include <memory>
#include "RightTriangle.h"
#include "Rectangle.h"

int main()
{
    system("chcp 65001 > nul");

    std::vector<std::unique_ptr<Figure>> figs;

    try {
        figs.emplace_back(std::make_unique<RightTriangle>(3,4,5,30,60));
        figs.back()->print();
    }
    catch (const FigureError& e) {
        std::cout << "Ошибка создания фигуры. Причина: "
                  << e.what() << '\n';
    }

    try {
        figs.emplace_back(std::make_unique<RightTriangle>(3,4,5,45,45));
        figs.back()->print();
    }
    catch (const FigureError& e) {
        std::cout << "Ошибка создания фигуры. Причина: "
                  << e.what() << '\n';
    }

    try {
        figs.emplace_back(std::make_unique<Rectangle>(10,20));
        figs.back()->print();
    }
    catch (const FigureError& e) {
        std::cout << "Ошибка создания фигуры. Причина: "
                  << e.what() << '\n';
    }
    return 0;
}
