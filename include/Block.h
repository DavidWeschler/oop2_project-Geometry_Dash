#pragma once

#include "Static.h"

class Block : public Static
{
public:
	Block(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position);
	virtual void makeVirtural() {};

private:
	static bool m_registeritBlock;
	static bool m_registeritBlock_M;
};