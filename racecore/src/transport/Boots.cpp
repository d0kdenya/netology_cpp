#include "transport/Boots.h"

Boots::Boots() : LandTransport(6) {}

std::string Boots::name() const { return "Ботинки-вездеходы"; }

double Boots::raceTime(double d) const
{
    double tMove = d / speed_;
    int rests = static_cast<int>(tMove / 60);
    if (tMove / 60 == rests) rests--;

    double rest = 0.0;
    if (rests > 0)
        rest = 10 + (rests - 1) * 5;

    return tMove + rest;
}
