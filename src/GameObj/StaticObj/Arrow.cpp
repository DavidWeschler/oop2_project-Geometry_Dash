#include "GameObj/StaticObj/Arrow.h"

bool Arrow::m_registerit = GameEnityFactory<Static>::registerit(ARROW_C,
	[](std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<Arrow>(world, ARROW_C, position);
	});

Arrow::Arrow(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position)
	: Static(world, color, position, b2_staticBody, sf::Vector2f(position.x / 30.f, position.y / 30.f), sf::Vector2f(1.f, 1.f), true)
{
	setTexture(6);
}
