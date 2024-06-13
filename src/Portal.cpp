#include "Portal.h"
#include <SFML/Graphics.hpp>


Portal::Portal(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position)
	: Static(world, color, position, b2_dynamicBody)
{
	setSize(60, 60 * 4);
}
