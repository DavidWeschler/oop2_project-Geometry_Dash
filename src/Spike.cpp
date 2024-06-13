#include "Spike.h"

bool Spike::m_registerit = FactoryFixed::registeritFixed(ObjectTypes::SPIKE_T, [](std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<Spike>(world, color, position);

	});

Spike::Spike(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position)
	: Static(world, color, position, b2_staticBody)
{
	setTexture(2);
}
