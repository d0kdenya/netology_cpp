#include "transport/Camel.h"

Camel::Camel() : LandTransport(10) {}

std::string Camel::name() const { return "Верблюд"; }

double Camel::raceTime(double d) const
{
    double moveTime = d / speed_;
    int rests = static_cast<int>(moveTime / 30);
    if (moveTime / 30 == rests) rests--;

    double restTime = 0.0;
    if (rests > 0)
        restTime = 5 + (rests - 1) * 8;

    return moveTime + restTime;
}
