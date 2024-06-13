#pragma once

#include "Static.h"

class Arrow : public Static
{
public:
	Arrow(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position);
	virtual void makeVirtural() {};

private:
	static bool m_registerit;

};