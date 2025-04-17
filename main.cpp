#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

class Figure {
protected:
    std::string name_;
    int         sides_count_;

    Figure(std::string n, int s)
        : name_(std::move(n)), sides_count_(s) {}

public:
    Figure() : Figure("Фигура", 0) {}

    virtual ~Figure() = default;

    virtual bool check() const {
        return sides_count_ == 0;
    }

    virtual void print_info() const {
        std::cout << name_ << ":\n"
                  << (check() ? "Правильная\n" : "Неправильная\n")
                  << "Количество сторон: " << sides_count_ << '\n';
    }
};

class Triangle : public Figure {
protected:
    int a_, b_, c_, A_, B_, C_;
public:
    Triangle(std::string name,
             int a, int b, int c,
             int A, int B, int C)
        : Figure(std::move(name), 3),
          a_(a), b_(b), c_(c),
          A_(A), B_(B), C_(C) {}

    bool check() const override {
        return A_ + B_ + C_ == 180 && !Figure::check();
    }

    void print_info() const override {
        Figure::print_info();
        std::cout << "Стороны: a=" << a_
                  << " b=" << b_
                  << " c=" << c_ << '\n'
                  << "Углы:   A=" << A_
                  << " B=" << B_
                  << " C=" << C_ << "\n\n";
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle(int a, int b, int c, int A, int B)
        : Triangle("Прямоугольный треугольник",
                   a, b, c, A, B, 90) {}

    bool check() const override {
        return Triangle::check() && C_ == 90;
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int b, int A, int B)
        : Triangle("Равнобедренный треугольник",
                   a, b, a, A, B, A) {}

    bool check() const override {
        return Triangle::check() && a_ == c_ && A_ == C_;
    }
};

class EquilateralTriangle : public Triangle {
public:
    explicit EquilateralTriangle(int a)
        : Triangle("Равносторонний треугольник",
                   a, a, a, 60, 60, 60) {}

    bool check() const override {
        return Triangle::check() &&
               a_ == b_ && b_ == c_ && A_ == 60;
    }
};

class Quadrangle : public Figure {
protected:
    int a_, b_, c_, d_;
    int A_, B_, C_, D_;
public:
    Quadrangle(std::string name,
               int a, int b, int c, int d,
               int A, int B, int C, int D)
        : Figure(std::move(name), 4),
          a_(a), b_(b), c_(c), d_(d),
          A_(A), B_(B), C_(C), D_(D) {}

    bool check() const override {
        return A_ + B_ + C_ + D_ == 360;
    }

    void print_info() const override {
        Figure::print_info();
        std::cout << "Стороны: a=" << a_
                  << " b=" << b_
                  << " c=" << c_
                  << " d=" << d_ << '\n'
                  << "Углы:   A=" << A_
                  << " B=" << B_
                  << " C=" << C_
                  << " D=" << D_ << "\n\n";
    }
};

class Parallelogram : public Quadrangle {
public:
    Parallelogram(int a, int b, int A, int B)
        : Quadrangle("Параллелограмм",
                     a, b, a, b,
                     A, B, A, B) {}

    bool check() const override {
        return Quadrangle::check() &&
               a_ == c_ && b_ == d_ &&
               A_ == C_ && B_ == D_;
    }
};

class Rectangle : public Parallelogram {
public:
    Rectangle(int a, int b)
        : Parallelogram(a, b, 90, 90) {
        name_ = "Прямоугольник";
    }

    bool check() const override {
        return Parallelogram::check() && A_ == 90;
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(int a, int A, int B)
        : Parallelogram(a, a, A, B) {
        name_ = "Ромб";
    }

    bool check() const override {
        return Parallelogram::check() && a_ == b_;
    }
};

class Square : public Rectangle {
public:
    explicit Square(int a) : Rectangle(a, a) {
        name_ = "Квадрат";
    }

    bool check() const override {
        return Rectangle::check() && a_ == b_;
    }
};

void print_info(const Figure* fig) {
    fig->print_info();
}

int main() {
#ifdef _WIN32
    system("chcp 65001 > nul");
#endif

    std::vector<Figure*> figs;

    Figure               base;
    Triangle             tri("Треугольник", 10, 20, 30, 50, 60, 70);

    RightTriangle        wrongRight(10, 20, 30, 50, 60);
    RightTriangle        goodRight (10, 20, 30, 50, 40);

    IsoscelesTriangle    badIso (10, 20, 50, 60);
    EquilateralTriangle  goodEqui(30);

    Quadrangle           quad("Четырёхугольник",
                              10, 20, 30, 40,
                              50, 60, 70, 80);

    Rectangle            rect(10, 20);
    Square               sq(20);
    Parallelogram        wrongPar(20, 30, 30, 40);
    Rhombus              wrongRh(30, 30, 40);

    figs = { &base, &tri,
             &wrongRight, &goodRight,
             &badIso, &goodEqui,
             &quad, &rect, &sq,
             &wrongPar, &wrongRh };

    for (auto* f : figs) print_info(f);
    return 0;
}