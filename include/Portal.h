#pragma once

#include "Static.h"

class Portal : public Static
{
public:
	Portal(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position);
	virtual void makeVirtural() {};
};