#pragma once
#include "GameObj/StaticObj/Static.h"

class Block : public Static
{
public:
	Block(World& world, sf::Color color, sf::Vector2f position);
	virtual ~Block() = default;
private:
	static bool m_registerItBlock;
	static bool m_registerItBlockM;
	static bool m_registerItBlockV;
};