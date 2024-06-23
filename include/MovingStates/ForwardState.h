#pragma once

#include "MovingStates/MoveState.h"

class Player;

class ForwardState : public MoveState
{
public:
    ForwardState() {};
    virtual void move(sf::Time time, Player& player) override;
    virtual void rotate(Player& player, float& angle, float& destAngle, bool& angleReach);
    virtual ~ForwardState() = default;
};