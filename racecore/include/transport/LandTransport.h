#pragma once
#include "Transport.h"

class LandTransport : public Transport {
protected:
    double speed_;
public:
    explicit LandTransport(double v) : speed_(v) {}
};