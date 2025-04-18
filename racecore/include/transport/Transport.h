#pragma once
#include <string>

class Transport {
public:
    virtual ~Transport() = default;
    virtual std::string name() const = 0;
    virtual double raceTime(double distance) const = 0;
};
