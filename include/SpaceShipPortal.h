#pragma once

#include "Portal.h"

class SpaceShipPortal : public Portal
{
public:
	SpaceShipPortal(std::unique_ptr<b2World>& world, sf::Texture& texture, sf::Color color, sf::Vector2f position)
		: Portal(world, texture, color, position) {};
};