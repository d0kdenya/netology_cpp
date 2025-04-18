#pragma once
#include "LandTransport.h"

class Boots : public LandTransport
{
public:
    Boots();

    std::string name() const override;
    double      raceTime(double distance) const override;
};
