#pragma once

#include "Movable.h"
#include "Singleton.h"

class Player : public Movable
{
public:
	Player();
	void setChosenPlayer(int i);
private:

	Singleton& m_resources = Singleton::instance();
	int m_bullets;
};





