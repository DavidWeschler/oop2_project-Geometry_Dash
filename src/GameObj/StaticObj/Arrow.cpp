#include "GameObj/StaticObj/Arrow.h"

bool Arrow::m_registerit = FactoryFixed::registeritFixed(ObjectTypes::ARROW_T, 
	[](std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<Arrow>(world, color, position);
	});

Arrow::Arrow(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position)
	: Static(world, color, position, b2_staticBody)
{
	setTexture(6);
}
