#include "DirectionPortal.h"

bool DirectionPortal::m_registerit = FactoryFixed::registeritFixed(ObjectTypes::DIRECTION_PORTAL_T, [](std::unique_ptr<b2World>& world, sf::Texture& texture, sf::Color color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<DirectionPortal>(world, texture, color, position);

	});

DirectionPortal::DirectionPortal(std::unique_ptr<b2World>& world, sf::Texture& texture, sf::Color color, sf::Vector2f position)
	: Portal(world, texture, color, position)
{
	setTexture(5);
}
