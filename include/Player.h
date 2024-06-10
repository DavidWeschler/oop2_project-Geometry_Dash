#pragma once

#include "Movable.h"
#include "Singleton.h"
#include <box2d/b2_body.h>

class Player : public Movable
{
public:
	Player(std::unique_ptr<b2World>&world, sf::Texture& texture, sf::Color color, sf::Vector2f pos) 
		: Movable(world, texture, color, pos), m_bullets(0) {};
	virtual ~Player() override;
	void setChosenPlayer(int i);
	void setBox(std::unique_ptr<b2World>& world);
	virtual void makeVirtural() {};

private:

	Singleton& m_resources = Singleton::instance();
	int m_bullets;
};





