#include "transport/Eagle.h"

Eagle::Eagle() : AirTransport(8) {}

std::string Eagle::name() const { return "Орёл"; }

double Eagle::raceTime(double d) const
{
    return (d * 0.94) / speed_;
}
