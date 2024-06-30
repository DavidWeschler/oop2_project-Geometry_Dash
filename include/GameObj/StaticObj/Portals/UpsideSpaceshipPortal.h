#pragma once
#include "GameObj/StaticObj/Portals/Portal.h"

class UpsideSpaceshipPortal : public Portal
{
public:
	UpsideSpaceshipPortal(World& world, sf::Color color, sf::Vector2f position);
	virtual ~UpsideSpaceshipPortal() = default;
private:
	static bool m_registerit;
};