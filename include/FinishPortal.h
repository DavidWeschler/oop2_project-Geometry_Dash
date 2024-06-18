#pragma once
#include "Portal.h"

class FinishPortal : public Portal
{
public:
	FinishPortal(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position);
	virtual void makeVirtural() {};

private:
	static bool m_registerit;
};