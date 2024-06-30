#include "GameObj/StaticObj/Spike.h"

bool Spike::m_registerIt = GameEnityFactory<Static>::registerit(SPIKE_C,
	[](World& world, sf::Color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<Spike>(world, SPIKE_C, position);
	});

bool Spike::m_registerItDown = GameEnityFactory<Static>::registerit(DOWN_SPIKE_C,
	[](World& world, sf::Color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<Spike>(world, DOWN_SPIKE_C, position);
	});

Spike::Spike(World& world, sf::Color color, sf::Vector2f position)
	: Static(world, position, b2_staticBody, sf::Vector2f(position.x / 30.f, position.y / 30.f), sf::Vector2f(1.f, 1.f), true)
{
	if (color == SPIKE_C) setTexture(2);
	else //color == DOWN_SPIKE_C
		setTexture(7);
}
