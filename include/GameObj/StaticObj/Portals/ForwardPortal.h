#pragma once
#include "GameObj/StaticObj/Portals/Portal.h"

class ForwardPortal : public Portal
{
public:
	ForwardPortal(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position);
	virtual ~ForwardPortal() = default;
private:
	static bool m_registerit;
};

