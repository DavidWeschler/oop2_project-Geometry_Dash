#pragma once

#include "MoveState.h"

class Player;

class FlyState : public MoveState
{
public:
	FlyState() {};
	virtual void move(sf::Time time, Player& player) override;
	virtual ~FlyState() = default;
};