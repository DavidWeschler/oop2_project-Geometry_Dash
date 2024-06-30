#include "GameObj/StaticObj/Spike.h"

bool Spike::m_registerit = GameEnityFactory<Static>::registerit(SPIKE_C,
	[](std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<Spike>(world, SPIKE_C, position);
	});

bool Spike::m_registerit_down = GameEnityFactory<Static>::registerit(DOWN_SPIKE_C,
	[](std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<Spike>(world, DOWN_SPIKE_C, position);
	});

Spike::Spike(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position)
	: Static(world, color, position, b2_staticBody, sf::Vector2f(position.x / 30.f, position.y / 30.f), sf::Vector2f(1.f, 1.f), true)
{
	//(color == SPIKE_C) ? setTexture(2) : setTexture(7);

	if (color == SPIKE_C) setTexture(2);
	else //color == DOWN_SPIKE_C
		setTexture(7);
}
