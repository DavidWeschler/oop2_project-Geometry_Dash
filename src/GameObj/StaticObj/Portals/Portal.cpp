#include "GameObj/StaticObj/Portals/Portal.h"
#include <SFML/Graphics.hpp>


Portal::Portal(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position)
	: Static(world, color, position, b2_staticBody, sf::Vector2f(position.x/30.f, (120 + position.y)/30.f), sf::Vector2f(0.8f, 6.f), true)
{
	setSize(60, 60 * 6);
}

Portal::Portal(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position, sf::Vector2f boxPosition, sf::Vector2f boxShapeSize)
	: Static(world, color, position, b2_staticBody, boxPosition, boxShapeSize, true)
{
	setSize(60, 60 * 6);
}
