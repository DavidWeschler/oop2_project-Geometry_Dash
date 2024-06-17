#pragma once

#include "Static.h"

class Spike : public Static
{
public:
	Spike(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position);

	virtual void makeVirtural() {};

private:
	static bool m_registerit;
	static bool m_registerit_down;
};

