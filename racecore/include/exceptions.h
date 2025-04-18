#pragma once
#include <stdexcept>

struct RegistrationError : std::logic_error {
    using std::logic_error::logic_error;
};
struct RaceError : std::logic_error {
    using std::logic_error::logic_error;
};