#pragma once

#include "SFML/Graphics.hpp"
#include "GlobalConsts.h"

class Player;

class MoveState
{
public:
    MoveState() {};
    virtual ~MoveState() = default;
    virtual void move(sf::Time time, Player& player) = 0;
};