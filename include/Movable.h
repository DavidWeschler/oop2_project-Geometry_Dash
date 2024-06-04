#pragma once

#include "Object.h"

class Movable : public Object
{
public:
	Movable() : Object() {};
	Movable(sf::Texture& texture, sf::Color color, sf::Vector2f pos) : Object(texture, color, pos) {};
};