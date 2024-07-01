#pragma once

#pragma region headers
#include "GameObj/Object.h"
#include <typeinfo>
#pragma endregion headers

struct UnknownCollision : public std::runtime_error
{
    UnknownCollision(Object& a, Object& b)
        : std::runtime_error(std::string("Unknown collision of ") + typeid(a).name() + " and " + typeid(b).name())
    {}
};

void processCollision(Object& object1, Object& object2);