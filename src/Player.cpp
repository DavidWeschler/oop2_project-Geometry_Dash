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
		//getBox()->SetFixedRotation(true);
		b2Vec2 vel = b2Vec2(getBox()->GetLinearVelocity().x, -40);
		getBox()->ApplyLinearImpulseToCenter(vel, true);
	}
}

void Player::setStratLocation(sf::Vector2f pos)	//we dont use it for now...
{
	m_startLocation = pos;
}

sf::Vector2f Player::getStartLocation() const
{
	return m_startLocation;
}
