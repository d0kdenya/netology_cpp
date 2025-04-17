#include <iostream>
#include <numeric>
#include <stdexcept>

class Fraction
{
private:
    long long n_;
    long long d_;

    void normalise()
    {
        if (d_ == 0) throw std::invalid_argument("denominator = 0");
        if (d_ < 0)  { n_ = -n_; d_ = -d_; }

        long long g = std::gcd(n_, d_);
        n_ /= g;  d_ /= g;
    }

public:
    Fraction(long long n = 0, long long d = 1) : n_(n), d_(d) { normalise(); }

    friend Fraction operator+(Fraction a, const Fraction& b) {
        a.n_ = a.n_*b.d_ + b.n_*a.d_;
        a.d_ = a.d_*b.d_;
        a.normalise();  return a;
    }
    friend Fraction operator-(Fraction a, const Fraction& b) {
        a.n_ = a.n_*b.d_ - b.n_*a.d_;
        a.d_ = a.d_*b.d_;
        a.normalise();  return a;
    }
    friend Fraction operator*(Fraction a, const Fraction& b) {
        a.n_ *= b.n_;   a.d_ *= b.d_;
        a.normalise();  return a;
    }
    friend Fraction operator/(Fraction a, const Fraction& b) {
        if (b.n_ == 0) throw std::invalid_argument("division by zero");
        a.n_ *= b.d_;   a.d_ *= b.n_;
        a.normalise();  return a;
    }
    Fraction operator-() const { return Fraction(-n_, d_); }

    Fraction& operator++()  { n_ += d_;  return *this; }
    Fraction  operator++(int) { Fraction tmp = *this; ++(*this); return tmp; }

    Fraction& operator--()  { n_ -= d_;  return *this; }
    Fraction  operator--(int) { Fraction tmp = *this; --(*this); return tmp; }

    friend bool operator==(const Fraction& a,const Fraction& b)
        { return a.n_*b.d_ == b.n_*a.d_; }
    friend bool operator<(const Fraction& a,const Fraction& b)
        { return a.n_*b.d_ <  b.n_*a.d_; }
    friend bool operator!=(const Fraction& a,const Fraction& b){ return !(a==b);}
    friend bool operator>(const Fraction& a,const Fraction& b){ return  b<a; }
    friend bool operator<=(const Fraction& a,const Fraction& b){ return !(b<a);}
    friend bool operator>=(const Fraction& a,const Fraction& b){ return !(a<b);}

    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        return os << f.n_ << '/' << f.d_;
    }
};

int main()
{
    system("chcp 65001 > nul");

    long long n1,d1,n2,d2;
    std::cout << "Введите числитель дроби 1: ";
    std::cin  >> n1;
    std::cout << "Введите знаменатель дроби 1: ";
    std::cin  >> d1;
    std::cout << "Введите числитель дроби 2: ";
    std::cin  >> n2;
    std::cout << "Введите знаменатель дроби 2: ";
    std::cin  >> d2;

    Fraction f1(n1,d1), f2(n2,d2);

    std::cout << f1 << " + "  << f2 << " = " << f1 + f2 << '\n';
    std::cout << f1 << " - "  << f2 << " = " << f1 - f2 << '\n';
    std::cout << f1 << " * "  << f2 << " = " << f1 * f2 << '\n';
    std::cout << f1 << " / "  << f2 << " = " << f1 / f2 << '\n';

    std::cout << "++" << f1 << " * " << f2 << " = " << (++f1 * f2) << '\n';
    std::cout << "Значение дроби 1 = " << f1 << '\n';
    std::cout << f1 << "-- * " << f2 << " = " << (f1-- * f2) << '\n';
    std::cout << "Значение дроби 1 = " << f1 << '\n';
    return 0;
}
