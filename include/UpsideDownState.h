#pragma once

#include "MoveState.h"

class Player;

class UpsideDownState : public MoveState
{
public:
	UpsideDownState() {};
	virtual void move(sf::Time time, Player& player);
	virtual void rotate(Player& player, float& angle, float& destAngle, bool& angleReach);
	virtual ~UpsideDownState() = default;
};