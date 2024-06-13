#include "Player.h"
#include <iostream>

Player::~Player()
{
}

void Player::move(sf::Time time)
{
	b2Vec2 boxPos = getBox()->GetPosition();

	if (m_spiked)
	{
		puts("i am spiked");
		m_spiked = false;
		boxPos.x = getStartLocation().x/30;
		boxPos.y = getStartLocation().y/30;

	}
	//m_angle = m_box->GetAngle()+ 90.0f; -ask ron (i will try to make it so that when jumping will the player will rotate. but anyway this needs to go)s

	getBox()->SetTransform(boxPos + b2Vec2(VELOCITY * time.asSeconds(), 0.0f), getBox()->GetAngle());
	setPosition(sf::Vector2f(boxPos.x * 30, boxPos.y * 30));
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
		m_isJumping = true;
		//getBox()->SetFixedRotation(true);
		b2Vec2 vel = b2Vec2(getBox()->GetLinearVelocity().x, -30);
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

void Player::setSpiked(bool state)
{
	m_spiked = state;
}

bool Player::getSpiked() const
{
	return m_spiked;
}

void Player::setJumping(bool state)
{
	m_isJumping = state;
}

bool Player::isJumping() const
{
	return m_isJumping;
}
