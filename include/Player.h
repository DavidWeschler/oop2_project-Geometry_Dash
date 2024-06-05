#pragma once

#include "Movable.h"
#include "Singleton.h"
#include <box2d/b2_body.h>

class Player : public Movable
{
public:
	Player();
	void setChosenPlayer(int i);
	void setBox(b2World& world);
private:

	Singleton& m_resources = Singleton::instance();
	int m_bullets;
};





