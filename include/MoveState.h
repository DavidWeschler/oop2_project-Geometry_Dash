#pragma once

#include "SFML/Graphics.hpp"
#include "GlobalConsts.h"
#include <Box2D/Box2D.h>

class Player;

class MoveState
{
public:
    MoveState() {};
    virtual ~MoveState() = default;
    virtual void move(sf::Time time, Player& player) = 0;
    bool spiked(Player& player, b2Vec2& boxPos);
    virtual void rotate(Player& player, float& angle, float& destAngle, bool& angleReach)=0;
    void jump(Player& player, int delta);
    void kick(Player& player, int delta);
};