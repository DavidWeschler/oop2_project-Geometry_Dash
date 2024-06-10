#include "Player.h"

Player::~Player()
{
}

void Player::setChosenPlayer(int i)
{
	setTexture(m_resources.getPlayerTexture(i));
}

void Player::setBox(std::unique_ptr<b2World>& world)
{
	initBox(world);
}

void Player::startJump()
{
	if (!m_isJumping)
	{
		getBox()->SetFixedRotation(true);
		m_isJumping = true;
		b2Vec2 vel = getBox()->GetLinearVelocity();
		vel.y = -10; 
		getBox()->SetLinearVelocity(vel);
	}
}
