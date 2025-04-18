#pragma once
#include "LandTransport.h"

class Centaur : public LandTransport
{
public:
    Centaur();

    std::string name() const override;
    double      raceTime(double distance) const override;
};
