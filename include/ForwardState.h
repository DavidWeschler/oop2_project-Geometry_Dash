#pragma once

#include "MoveState.h"

class Player;

class ForwardState : public MoveState
{
public:
    ForwardState() {};
    virtual void move(sf::Time time, Player& player) override;
    virtual ~ForwardState() = default;
};