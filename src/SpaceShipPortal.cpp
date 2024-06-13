#include "SpaceShipPortal.h"

bool SpaceShipPortal::m_registerit = FactoryFixed::registeritFixed(ObjectTypes::SPACESHIP_PORTAL_T, [](std::unique_ptr<b2World>& world, sf::Texture& texture, sf::Color color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<SpaceShipPortal>(world, texture, color, position);

	});

SpaceShipPortal::SpaceShipPortal(std::unique_ptr<b2World>& world, sf::Texture& texture, sf::Color color, sf::Vector2f position)
	: Portal(world, texture, color, position)
{
	setTexture(4);
}
