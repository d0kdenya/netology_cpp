#pragma once
#include "AirTransport.h"

class Broom : public AirTransport
{
public:
    Broom();

    std::string name() const override;
    double      raceTime(double distance) const override;
};