#include <iostream>
#include <numeric>
#include <stdexcept>
#include <cstdlib>

class Fraction
{
private:
    int numerator_;
    int denominator_;

    void normalize()
    {
        if (denominator_ == 0)
            throw std::invalid_argument("Denominator must not be 0");

        if (denominator_ < 0) {
            numerator_   = -numerator_;
            denominator_ = -denominator_;
        }

        int g = std::gcd(numerator_, denominator_);
        numerator_   /= g;
        denominator_ /= g;
    }

public:
    Fraction(int num, int den) : numerator_(num), denominator_(den)
    {
        normalize();
    }

    friend bool operator==(const Fraction& lhs, const Fraction& rhs)
    {
        return static_cast<long long>(lhs.numerator_)   * rhs.denominator_ ==
               static_cast<long long>(rhs.numerator_)   * lhs.denominator_;
    }
    friend bool operator<(const Fraction& lhs, const Fraction& rhs)
    {
        return static_cast<long long>(lhs.numerator_)   * rhs.denominator_ <
               static_cast<long long>(rhs.numerator_)   * lhs.denominator_;
    }

    friend bool operator!=(const Fraction& lhs, const Fraction& rhs) { return !(lhs == rhs); }
    friend bool operator> (const Fraction& lhs, const Fraction& rhs) { return   rhs < lhs; }
    friend bool operator<=(const Fraction& lhs, const Fraction& rhs) { return !(rhs < lhs); }
    friend bool operator>=(const Fraction& lhs, const Fraction& rhs) { return !(lhs < rhs); }
};


int main()
{
    system("chcp 65001 > nul");

    Fraction f1(4, 3);
    Fraction f2(6, 11);

    std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
    std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
    std::cout << "f1" << ((f1 <  f2) ? " < "  : " not < ")  << "f2" << '\n';
    std::cout << "f1" << ((f1 >  f2) ? " > "  : " not > ")  << "f2" << '\n';
    std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
    std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
    return 0;
}
