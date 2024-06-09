#pragma once

#include "Static.h"

class Weapon : public Static
{
public:
	Weapon(std::unique_ptr<b2World>& world, sf::Texture& texture, sf::Color color, sf::Vector2f position)
		: Static(world, texture, color, position) {};

};