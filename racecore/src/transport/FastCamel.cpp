#include "transport/FastCamel.h"

FastCamel::FastCamel() : LandTransport(40) {}

std::string FastCamel::name() const { return "Верблюд-быстроход"; }

double FastCamel::raceTime(double d) const
{
    double tMove = d / speed_;
    int rests = static_cast<int>(tMove / 10);
    if (tMove / 10 == rests) rests--;

    double rest = 0.0;
    for (int i = 0; i < rests; ++i)
        rest += (i == 0 ? 5 : (i == 1 ? 6.5 : 8));

    return tMove + rest;
}
