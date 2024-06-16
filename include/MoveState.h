#pragma once

#include "SFML/Graphics.hpp"

class MoveState
{
public:
	MoveState() {};
	virtual ~MoveState() = 0;
	virtual void move(sf::Time time) = 0;
};