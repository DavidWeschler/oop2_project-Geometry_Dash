#include "Spike.h"

bool Spike::m_registerit = FactoryFixed::registeritFixed(ObjectTypes::SPIKE_T, [](std::unique_ptr<b2World>& world, sf::Texture& texture, sf::Color color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<Spike>(world, texture, color, position);

	});