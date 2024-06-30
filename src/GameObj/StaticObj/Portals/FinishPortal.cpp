#include "GameObj/StaticObj/Portals/FinishPortal.h"

bool FinishPortal::m_registerIt = GameEnityFactory<Static>::registerit(FINISH_PORTAL_C,
	[](World& world, sf::Color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<FinishPortal>(world, FINISH_PORTAL_C, position);
	});

FinishPortal::FinishPortal(World& world, sf::Color, sf::Vector2f position)
	: Portal(world, position, sf::Vector2f(position.x/30.f, (60+position.y)/30.f), sf::Vector2f(0.8f, 15.f))
{
	setSize(3*60, 60 * 4*3);
	setTexture(11);
}