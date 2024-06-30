#pragma once

#include "GameObj/StaticObj/Static.h"

class Portal : public Static
{
public:
	Portal(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position);
	Portal(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position, sf::Vector2f boxPosition, sf::Vector2f boxShapeSize);
	virtual ~Portal() = default;
};