#include "factory.h"
#include "transport/Camel.h"
#include "transport/FastCamel.h"
#include "transport/Centaur.h"
#include "transport/Boots.h"
#include "transport/Carpet.h"
#include "transport/Eagle.h"
#include "transport/Broom.h"

static std::vector<std::string> names={
    "Верблюд",
    "Верблюд-быстроход",
    "Кентавр",
    "Ботинки-вездеходы",
    "Ковёр-самолёт",
    "Орёл",
    "Метла"
};

std::vector<std::string> listAllNames(){ return names; }

std::shared_ptr<Transport> createByIndex(int i)
{
    switch(i){
        case 0: return std::make_shared<Camel>();
        case 1: return std::make_shared<FastCamel>();
        case 2: return std::make_shared<Centaur>();
        case 3: return std::make_shared<Boots>();
        case 4: return std::make_shared<Carpet>();
        case 5: return std::make_shared<Eagle>();
        case 6: return std::make_shared<Broom>();
        default:return nullptr;
    }
}
bool isLand(int i){ return i<=3; }
bool isAir (int i){ return i>=4; }
