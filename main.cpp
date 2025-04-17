#include <iostream>
#include <string>
#include <cstdlib>

class Figure {
protected:
    int         sides_count;
    std::string name;

    Figure(const std::string& n, int sides)
        : sides_count(sides), name(n) {}

public:
    Figure() : Figure("Фигура", 0) {}

    int  get_sides_count() const { return sides_count; }
    const std::string& get_name() const { return name; }
};

class Triangle : public Figure {
public:
    Triangle() : Figure("Треугольник", 3) {}
};

class Quadrangle : public Figure {
public:
    Quadrangle() : Figure("Четырёхугольник", 4) {}
};

int main() {
    system("chcp 65001 > nul");

    Figure      f;
    Triangle    t;
    Quadrangle  q;

    std::cout << "Количество сторон:\n";
    std::cout << f.get_name() << ": " << f.get_sides_count() << '\n';
    std::cout << t.get_name() << ": " << t.get_sides_count() << '\n';
    std::cout << q.get_name() << ": " << q.get_sides_count() << '\n';
    return 0;
}