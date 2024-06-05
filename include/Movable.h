#pragma once

#include "Object.h"

class Movable : public Object
{
public:
	Movable() : Object() {};
	Movable(b2World& world, sf::Texture& texture, sf::Color color, sf::Vector2f pos) : Object(world, texture, color, pos) {};
};