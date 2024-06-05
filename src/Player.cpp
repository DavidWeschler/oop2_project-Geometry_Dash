#include "Player.h"

Player::Player()
{
	setTexture(m_resources.getPlayerTexture(0));
	m_bullets = 0;	
}

void Player::setChosenPlayer(int i)
{
	setTexture(m_resources.getPlayerTexture(i));
}

void Player::setBox(b2World& world)
{
	initBox(world);
}
