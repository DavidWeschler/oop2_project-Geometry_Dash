#include "Portal.h"


Portal::Portal(std::unique_ptr<b2World>& world, sf::Texture& texture, sf::Color color, sf::Vector2f position)
	: Static(world, texture, color, position)
{
	setSize(60, 60 * 4);
}
