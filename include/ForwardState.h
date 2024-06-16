#pragma once

#include "MoveState.h"

class ForwardState : MoveState
{
public:
	ForwardState();
	virtual void move(sf::Time time);
	virtual ~ForwardState() = default;
};