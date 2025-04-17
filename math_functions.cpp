#include "math_functions.h"
#include <cmath>
#include <stdexcept>

double add(double x, double y)    { return x + y; }
double sub(double x, double y)    { return x - y; }
double mul(double x, double y)    { return x * y; }

double divide(double x, double y)
{
    if (y == 0.0)
        throw std::runtime_error("Деление на ноль!");
    return x / y;
}

double power(double base, double exp)
{
    return std::pow(base, exp);
}
