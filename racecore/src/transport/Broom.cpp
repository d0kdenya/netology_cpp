#include "transport/Broom.h"
#include <cmath>

Broom::Broom() : AirTransport(20) {}

std::string Broom::name() const { return "Метла"; }

double Broom::raceTime(double d) const
{
    int thousands = static_cast<int>(d / 1000);
    double coef = 1.0 - thousands * 0.01;
    if (coef < 0) coef = 0;

    return (d * coef) / speed_;
}
