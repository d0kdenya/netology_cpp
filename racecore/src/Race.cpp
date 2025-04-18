#include "Race.h"
#include "transport/LandTransport.h"
#include "transport/AirTransport.h"
#include "exceptions.h"
#include <algorithm>

Race::Race(RaceType t,double d):distance_(d),type_(t){}

void Race::registerTransport(const std::shared_ptr<Transport>& t)
{
    bool isLand = dynamic_cast<LandTransport*>(t.get())!=nullptr;
    bool isAir  = dynamic_cast<AirTransport*>(t.get())!=nullptr;

    if(type_==RaceType::Land  && !isLand)
        throw RegistrationError("Нельзя регистрировать воздушное ТС");
    if(type_==RaceType::Air   && !isAir )
        throw RegistrationError("Нельзя регистрировать наземное ТС");

    for(auto& p:part_)
        if(p->name()==t->name())
            throw RegistrationError("Этот транспорт уже зарегистрирован");

    part_.push_back(t);
}

std::vector<std::pair<std::string,double>> Race::start() const
{
    if(part_.size()<2) throw RaceError("Нужно >=2 участников");
    std::vector<std::pair<std::string,double>> res;
    for(auto& p:part_)
        res.emplace_back(p->name(), p->raceTime(distance_));
    std::sort(res.begin(),res.end(),
              [](auto&a,auto&b){return a.second<b.second;});
    return res;
}
