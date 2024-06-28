#include "GameObj/MovablesObj/Player.h"
#include <ctime>
#include <iostream>

Player::Player(World& world, sf::Vector2f pos)
	: Movable(world, PLAYER_C, pos, sf::Vector2f(1, 1), false), m_startLocation(pos), m_currState(PlayerState::FORWARD_S)
{
	srand(std::time(NULL));
	m_setNum = rand() % NUM_OF_CHOOSE_SETS;
	setTexture(m_resources.getPlayerTexture(m_setNum));
	m_moveState = &m_forwardState;
	m_nextState = m_currState;
	m_groundJumpDelta = 0;
}

void Player::move(sf::Time time)
{
	static bool freeze = true;
	static sf::Clock delayClock;

	if (m_spiked && freeze && delayClock.getElapsedTime().asSeconds() >= 0.25f)
	{
		freeze = false;
	}
	else
	{
		delayClock.restart();
		freeze = true;
		m_moveState->move(time, *this);
	}
}

void Player::setChosenPlayer(int i)
{
	m_setNum = i;
	setTexture(m_resources.getPlayerTexture(m_setNum));
}

sf::Vector2f Player::getStartLocation() const
{
	return m_startLocation;
}

void Player::setSpiked(bool state)
{
	setGroundJumpDelta(0);
	m_spiked = state;
}

bool Player::isSpiked() const
{
	return m_spiked;
}

void Player::arrowTouch(bool state)
{
	m_arrowKick = state;
}

bool Player::gotAKick() const
{
	return m_arrowKick;
}

void Player::setJumping(bool state)
{
	if (!(state && !m_onGround))
	{ 
		m_isJumping = state; 
	}
}

void Player::setOnGround(bool state)
{
	m_onGround = state;
}

bool Player::isOnGround() const
{
	return m_onGround;
}

void Player::setSetNum(int i)
{
	m_setNum = i;
}

int Player::getSetNum() const
{
	return m_setNum;
}

void Player::setNextLevel(bool state)
{
	m_nextLevel = state;
}

bool Player::getNextLevelState() const
{
	return m_nextLevel;
}

void Player::setBoxTransform(const b2Vec2& position)
{
	setTransform(position);
}

b2Vec2 Player::getBoxLinearVelocity() const
{
	return getLinearVelocity();
}

void Player::setBoxLinearVelocity(const b2Vec2& vel)
{
	setLinearVelocity(vel);
}

float Player::getBoxAngle() const
{
	return getAngle();
}

PlayerState Player::getStateType() const
{
	return m_currState;
}

void Player::setState(PlayerState state)
{
	m_nextState = state;
}

void Player::changeState(World& world)
{
	if (m_currState != m_nextState)
	{
		m_currState = m_nextState;
		switch (m_currState)
		{
		case PlayerState::FORWARD_S: 
			handleForwardState(world);
			break;
		case PlayerState::SPACESHIP_S:
			handleSpaceShipState(world);
			break;
		case PlayerState::UPSIDEDOWN_S:
			handleUpsideDownState(world);
			break;
		case PlayerState::UPSIDESPACESHIP_S:
			handleUpsideDownShipState(world);
			break;
		default:
			break;
		}
	}
}

void Player::makeShip(World& world)
{
	insertBox(world, m_setNum + 15, sf::Vector2f(4.5f/30.f, 2.f/30.f));
}

void Player::handleForwardState(World& world)
{
	m_moveState = &m_forwardState;
	insertBox(world, m_setNum, sf::Vector2f(1.f, 1.f));
	setMyGravity(1);
	setRotation(0);
	setScale(1, 1);
}

void Player::handleSpaceShipState(World& world)
{
	m_onGround = true;
	m_moveState = &m_flyState;
	makeShip(world);
	setMyGravity(1);
	setScale(1, 1);
	setRotation(0);
}

void Player::handleUpsideDownState(World& world)
{
	m_moveState = &m_upsideDownState;
	insertBox(world, m_setNum, sf::Vector2f(1.f, 1.f));
	setMyGravity(-1);
	setScale(1, 1);
	setRotation(180);
}

void Player::handleUpsideDownShipState(World& world)
{
	m_onGround = true;
	m_moveState = &m_upsideSpaceship;
	makeShip(world);
	setMyGravity(-1);
	setScale(1, -1);
	setRotation(0);
}

b2Vec2 Player::getBoxPosition() const
{
	return getBPosition();
}

bool Player::isJumping() const
{
	return m_isJumping;
}

void Player::setGroundJumpDelta(int delta)
{
	m_groundJumpDelta = delta;
}

int Player::getGroundJumpDelta() const
{
	return m_groundJumpDelta;
}

void Player::insertBox(World& world, int i, sf::Vector2f boxValues)
{
	b2PolygonShape boxShape;
	b2FixtureDef fixtureDef;
	b2BodyDef bodyDef;
	bodyDef.position.Set(getPosition().x / 30.0f, getPosition().y / 30.0f);
	boxShape.SetAsBox(boxValues.x, boxValues.y);
	fixtureDef.shape = &boxShape;
	fixtureDef.density = 5.0f;
	createFixture(&fixtureDef);
	sf::Vector2u textureSize = m_resources.getPlayerTexture(i).getSize();
	setSize(sf::Vector2f(textureSize.x / 3.f, textureSize.y / 3.f));	
	setTextureRect(sf::IntRect(0, 0, textureSize.x, textureSize.y));
	setTexture(m_resources.getPlayerTexture(i));
}