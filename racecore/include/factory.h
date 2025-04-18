#pragma once
#include <memory>
#include <vector>
#include <string>
#include "transport/Transport.h"

std::vector<std::string> listAllNames();
std::shared_ptr<Transport> createByIndex(int idx);
bool isLand(int idx);
bool isAir(int idx);
