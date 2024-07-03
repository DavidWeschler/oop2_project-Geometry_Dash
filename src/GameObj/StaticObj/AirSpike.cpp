#include "GameObj/StaticObj/AirSpike.h"

bool AirSpike::m_registerIt = GameEnityFactory<Static>::registerit(AIR_SPIKE_C,
	[](World& world, sf::Color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<AirSpike>(world, AIR_SPIKE_C, position);
	});

AirSpike::AirSpike(World& world, sf::Color, sf::Vector2f position)
	: Static(world, position, b2_staticBody, sf::Vector2f(position.x / 30.f, position.y / 30.f), sf::Vector2f(2.5f, 2.5f), true)
{
	setTexture(8);
	setSize(3 * 60, 3 * 60);
	setFillColor(sf::Color(140, 0, 0, 185));
	m_rotation = 0;
}

void AirSpike::draw(sf::RenderWindow& window)
{
	Object::draw(window);
	m_rotation += 5;
	setRotation(m_rotation * 1.f);
}
