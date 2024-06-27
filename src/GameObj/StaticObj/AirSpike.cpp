#include "GameObj/StaticObj/AirSpike.h"

bool AirSpike::m_registerit = GameEnityFactory<AirSpike>::registerit(AIR_SPIKE_C,
	[](std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<AirSpike>
	{
		return std::make_unique<AirSpike>(world, AIR_SPIKE_C, position);

	});

AirSpike::AirSpike(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position)
	: Static(world, color, position, b2_staticBody)
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
	setRotation(m_rotation);
}
