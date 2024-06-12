#pragma once

#include "Static.h"

class Arrow : public Static
{
public:
	Arrow(std::unique_ptr<b2World>& world, sf::Texture& texture, sf::Color color, sf::Vector2f position)
		: Static(world, texture, color, position) {};
	virtual void makeVirtural() {};

private:

};