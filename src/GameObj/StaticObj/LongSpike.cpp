#include "GameObj/StaticObj/LongSpike.h"

bool LongSpike::m_registeritLong = GameEnityFactory<Static>::registerit(LONG_SPIKE_C,
	[](World& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<LongSpike>(world, LONG_SPIKE_C, position);
	});

bool LongSpike::m_registeritDownLong = GameEnityFactory<Static>::registerit(DOWN_LONG_SPIKE_C,
	[](World& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<LongSpike>(world, DOWN_LONG_SPIKE_C, position);
	});

LongSpike::LongSpike(World& world, sf::Color color, sf::Vector2f position)
	: Static(world, position, b2_staticBody, sf::Vector2f((240 + position.x) / 30.f, position.y / 30.f), sf::Vector2f(8.f, 0.4f), true)
{
	if (color == LONG_SPIKE_C)
	{
		setTexture(15);
		setSize(8 * 60, 60);
	}
	else //color == DOWN_LONG_SPIKE_C
	{
		setTexture(16);
		setSize(8 * 60, 60);
	}
}

void LongSpike::draw(sf::RenderWindow& window)
{
	Object::draw(window);
}