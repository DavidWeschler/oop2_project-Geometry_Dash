#include "GameObj/StaticObj/Portals/FinishPortal.h"

bool FinishPortal::m_registerit = GameEnityFactory<Static>::registerit(FINISH_PORTAL_C,
	[](std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<FinishPortal>(world, FINISH_PORTAL_C, position);
	});

FinishPortal::FinishPortal(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position)
	: Portal(world, color, position, sf::Vector2f(position.x/30.f, (60+position.y)/30.f), sf::Vector2f(0.8f, 15.f))
{
	setSize(3*60, 60 * 4*3);
	setTexture(11);
}
