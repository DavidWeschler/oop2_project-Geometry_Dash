#pragma once

#include "Portal.h"

class DirectionPortal : public Portal
{
public:
	DirectionPortal(std::unique_ptr<b2World>& world, sf::Texture& texture, sf::Color color, sf::Vector2f position);
	virtual void makeVirtural() {};
private:
	static bool m_registerit;
};

