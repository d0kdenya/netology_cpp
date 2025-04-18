#pragma once
#include "LandTransport.h"

class FastCamel : public LandTransport
{
public:
    FastCamel();

    std::string name() const override;
    double      raceTime(double distance) const override;
};
