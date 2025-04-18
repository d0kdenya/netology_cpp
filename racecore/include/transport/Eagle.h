#pragma once
#include "AirTransport.h"

class Eagle : public AirTransport
{
public:
    Eagle();

    std::string name() const override;
    double      raceTime(double distance) const override;
};
