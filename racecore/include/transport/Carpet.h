#pragma once
#include "AirTransport.h"

class Carpet : public AirTransport
{
public:
    Carpet();

    std::string name() const override;
    double      raceTime(double distance) const override;
};
