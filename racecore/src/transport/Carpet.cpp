#include "transport/Carpet.h"

Carpet::Carpet() : AirTransport(10) {}

std::string Carpet::name() const { return "Ковёр-самолёт"; }

double Carpet::raceTime(double d) const
{
    double coef = 1.0;
    if (d < 1000)       coef = 1.0;
    else if (d < 5000)  coef = 0.97;
    else if (d < 10000) coef = 0.90;
    else                coef = 0.95;

    return (d * coef) / speed_;
}
