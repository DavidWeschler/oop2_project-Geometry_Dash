#pragma once

#include "MoveState.h"

class UpsideDownState : MoveState
{
public:
	UpsideDownState();
	virtual void move(sf::Time time);
	virtual ~UpsideDownState() = default;
};