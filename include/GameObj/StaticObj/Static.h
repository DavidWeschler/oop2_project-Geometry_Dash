#pragma once

#include "GameObj/Object.h"

class Static : public Object
{
public:
	Static(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position, b2BodyType bodyType);
	virtual void makeVirtural() = 0;
	virtual ~Static() =default;

	void initBox(std::unique_ptr<b2World>& world, b2BodyType bodyType);	//private?
private:
	b2Body* m_box;
};