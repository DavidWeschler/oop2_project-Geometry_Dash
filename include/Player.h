#pragma once

#include "Movable.h"
#include "Singleton.h"
#include <box2d/b2_body.h>

class Player : public Movable
{
public:
	Player();
	~Player() override {};
	void setChosenPlayer(int i);
	void setBox(std::unique_ptr<b2World>& world);
	//virtual void stam() {};

private:

	Singleton& m_resources = Singleton::instance();
	int m_bullets;
};





