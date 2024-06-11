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
		boxPos.x = 240/30;// getStartLocation().x;
		boxPos.y = 1980/30;//getStartLocation().y;

		setPosition(sf::Vector2f(boxPos.x*30, boxPos.y*30));
		getBox()->SetTransform(boxPos + b2Vec2(VELOCITY * time.asSeconds(), 0.0f), getBox()->GetAngle());
	}
	else
	{
			//m_angle = m_box->GetAngle()+ 90.0f; -ask ron (i will try to make it so that when jumping will the player will rotate. but anyway this needs to go)
		setPosition(sf::Vector2f(boxPos.x * 30, boxPos.y * 30));
		getBox()->SetTransform(getBox()->GetPosition() + b2Vec2(VELOCITY * time.asSeconds(), 0.0f), getBox()->GetAngle());
	}
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
		b2Vec2 vel = b2Vec2(getBox()->GetLinearVelocity().x, -55);
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
