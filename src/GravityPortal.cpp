#include "GravityPortal.h"

bool GravityPortal::m_registeritGPortal = FactoryFixed::registeritFixed(ObjectTypes::GRAVITY_PORTAL_T, 
	[](std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<GravityPortal>(world, color, position);

	});

GravityPortal::GravityPortal(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position)
	: Portal(world, color, position)
{
	setTexture(3);
}
