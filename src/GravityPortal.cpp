#include "GravityPortal.h"

bool GravityPortal::m_registeritGPortal = FactoryFixed::registeritFixed(ObjectTypes::GRAVITY_PORTAL_T, [](std::unique_ptr<b2World>& world, sf::Texture& texture, sf::Color color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<GravityPortal>(world, texture, color, position);

	});