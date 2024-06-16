#pragma once

#include "MoveState.h"

class FlyState : MoveState
{
public:
	FlyState();
	virtual void move(sf::Time time);
	virtual ~FlyState() = default;
};