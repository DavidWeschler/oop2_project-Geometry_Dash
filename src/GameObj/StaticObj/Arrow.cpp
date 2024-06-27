#include "GameObj/StaticObj/Arrow.h"

bool Arrow::m_registerit = GameEnityFactory<Arrow>::registerit(ARROW_C,
	[](std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<Arrow>
	{
		return std::make_unique<Arrow>(world, ARROW_C, position);
	});

Arrow::Arrow(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position)
	: Static(world, color, position, b2_staticBody)
{
	setTexture(6);
}
