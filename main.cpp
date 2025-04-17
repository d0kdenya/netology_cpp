#include <iostream>
#include <string>
#include <cstdlib>

class Figure {
protected:
    std::string name;
    explicit Figure(std::string n) : name(std::move(n)) {}
public:
    virtual ~Figure() = default;
    virtual void print_info() const = 0;
};

class Triangle : public Figure {
protected:
    int a, b, c;
    int A, B, C;
public:
    Triangle(int a_, int b_, int c_, int A_, int B_, int C_)
        : Figure("Треугольник"), a(a_), b(b_), c(c_), A(A_), B(B_), C(C_) {}

    void print_info() const override {
        std::cout << name << ":\n"
                  << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n"
                  << "Углы:   A=" << A << " B=" << B << " C=" << C << "\n\n";
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle(int a, int b, int c, int A, int B)
        : Triangle(a, b, c, A, B, 90)     // C = 90
    { name = "Прямоугольный треугольник"; }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int b, int A, int B)
        : Triangle(a, b, a, A, B, A)      // c=a, C=A
    { name = "Равнобедренный треугольник"; }
};

class EquilateralTriangle : public Triangle {
public:
    explicit EquilateralTriangle(int a)
        : Triangle(a, a, a, 60, 60, 60)
    { name = "Равносторонний треугольник"; }
};

class Quadrangle : public Figure {
protected:
    int a, b, c, d;
    int A, B, C, D;
public:
    Quadrangle(int a_, int b_, int c_, int d_,
               int A_, int B_, int C_, int D_)
        : Figure("Четырёхугольник"),
          a(a_), b(b_), c(c_), d(d_),
          A(A_), B(B_), C(C_), D(D_) {}

    void print_info() const override {
        std::cout << name << ":\n"
                  << "Стороны: a=" << a << " b=" << b
                  << " c=" << c << " d=" << d << "\n"
                  << "Углы:   A=" << A << " B=" << B
                  << " C=" << C << " D=" << D << "\n\n";
    }
};

class Parallelogram : public Quadrangle {
public:
    Parallelogram(int a, int b, int A, int B)
        : Quadrangle(a, b, a, b, A, B, A, B)
    { name = "Параллелограмм"; }
};

class Rectangle : public Parallelogram {
public:
    Rectangle(int a, int b)
        : Parallelogram(a, b, 90, 90)
    { name = "Прямоугольник"; }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(int a, int A, int B)
        : Parallelogram(a, a, A, B)
    { name = "Ромб"; }
};


class Square : public Rectangle {
public:
    explicit Square(int a)
        : Rectangle(a, a)
    { name = "Квадрат"; }
};

void print_info(const Figure* fig) {
    fig->print_info();
}

int main() {
    system("chcp 65001 > nul");

    Triangle             tri(10, 20, 30, 50, 60, 70);
    RightTriangle        rtri(10, 20, 30, 50, 60);
    IsoscelesTriangle    itri(10, 20, 50, 60);
    EquilateralTriangle  etri(30);

    Quadrangle           quad(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle            rect(10, 20);
    Square               sq(20);
    Parallelogram        para(20, 30, 30, 40);
    Rhombus              rh(30, 30, 40);

    print_info(&tri);
    print_info(&rtri);
    print_info(&itri);
    print_info(&etri);

    print_info(&quad);
    print_info(&rect);
    print_info(&sq);
    print_info(&para);
    print_info(&rh);

    return 0;
}
