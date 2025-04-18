#include "transport/Centaur.h"

Centaur::Centaur() : LandTransport(15) {}

std::string Centaur::name() const { return "Кентавр"; }

double Centaur::raceTime(double d) const
{
    double tMove = d / speed_;
    int rests = static_cast<int>(tMove / 8);
    if (tMove / 8 == rests) rests--;

    return tMove + rests * 2;
}
