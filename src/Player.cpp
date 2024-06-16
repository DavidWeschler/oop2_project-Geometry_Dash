#include "Player.h"
#include <iostream>

Player::Player(std::unique_ptr<b2World>& world, sf::Texture& texture, sf::Color color, sf::Vector2f pos)
	: Movable(world, texture, color, pos), m_startLocation(pos), m_bullets(0)
{
	setTexture(m_resources.getPlayerTexture(0));	//give here the right int
	m_moveState = &m_forwardState;
}

Player::~Player()
{
}

void Player::move(sf::Time time)
{
	m_moveState->move(time, *this);

	//m_angle = m_box->GetAngle()+ 90.0f; -ask ron (i will try to make it so that when jumping will the player will rotate. but anyway this needs to go)s
	//all of the options for moving in constant speed:
	//getBox()->SetLinearVelocity(b2Vec2(5, getBox()->GetLinearVelocity().y));
	//getBox()->ApplyForce(b2Vec2(50, 0), getBox()->GetWorldCenter(), true);
	//getBox()->ApplyLinearImpulse(b2Vec2(0.13f, 0), getBox()->GetWorldCenter(), true);

}


void Player::setChosenPlayer(int i)
{
	setTexture(m_resources.getPlayerTexture(i));
}

void Player::setBox(std::unique_ptr<b2World>& world)
{
	initBox(world, b2_dynamicBody);
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

bool Player::isSpiked() const
{
	return m_spiked;
}

void Player::setJumping(bool state)
{
	m_isJumping = state;
}

void Player::setOnGround(bool state)
{
	m_onGround = state;
}

bool Player::isOnGround() const
{
	return m_onGround;
}

bool Player::isJumping() const
{
	return m_isJumping;
}
