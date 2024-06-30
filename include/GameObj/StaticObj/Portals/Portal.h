#pragma once
#include "GameObj/StaticObj/Static.h"

class Portal : public Static
{
public:
	Portal(World& world, sf::Vector2f position);
	Portal(World& world, sf::Vector2f position, sf::Vector2f boxPosition, sf::Vector2f boxShapeSize);
	virtual ~Portal() = default;
};