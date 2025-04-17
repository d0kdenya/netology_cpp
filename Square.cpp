#include "Square.h"

Square::Square(int a) : Rectangle(a,a) { name_ = "Квадрат"; }

bool Square::check() const
{
    return Rectangle::check() && a_ == b_;
}
