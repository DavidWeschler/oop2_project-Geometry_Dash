#include "Portal.h"
#include <SFML/Graphics.hpp>


Portal::Portal(std::unique_ptr<b2World>& world, sf::Texture& texture, sf::Color color, sf::Vector2f position)
	: Static(world, texture, color, position)
{
	setSize(60, 60 * 4);
}
