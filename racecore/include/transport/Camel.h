#pragma once
#include "LandTransport.h"

class Camel : public LandTransport
{
public:
    Camel();

    std::string name() const override;
    double      raceTime(double distance) const override;
};
