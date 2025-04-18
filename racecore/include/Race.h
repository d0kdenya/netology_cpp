#pragma once
#include <vector>
#include <memory>
#include <string>
#include "transport/Transport.h"

enum class RaceType { Land, Air, Mixed };

class Race {
    double distance_;
    RaceType type_;
    std::vector<std::shared_ptr<Transport>> part_;
public:
    Race(RaceType,double dist);

    void registerTransport(const std::shared_ptr<Transport>&);
    std::vector<std::pair<std::string,double>> start() const;
};
