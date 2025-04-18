#pragma once
#include "Transport.h"

class AirTransport : public Transport {
protected:
    double speed_;
public:
    explicit AirTransport(double v) : speed_(v) {}
};