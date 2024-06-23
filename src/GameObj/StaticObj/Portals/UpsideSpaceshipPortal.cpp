#include "GameObj/StaticObj/Portals/UpsideSpaceshipPortal.h"

bool UpsideSpaceshipPortal::m_registerit = FactoryFixed::registeritFixed(ObjectTypes::UPSIDESPACESHIP_T,
	[](std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<UpsideSpaceshipPortal>(world, color, position);

	});

UpsideSpaceshipPortal::UpsideSpaceshipPortal(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position)
	: Portal(world, color, position)
{
	setTexture(17);
}