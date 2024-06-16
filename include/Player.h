#pragma once

#include <box2d/b2_body.h>
#include "Movable.h"
#include "Singleton.h"
#include "MoveState.h"

class Player : public Movable
{
public:
	Player(std::unique_ptr<b2World>& world, sf::Texture& texture, sf::Color color, sf::Vector2f pos);
	virtual ~Player() override;
	/*virtual*/ void move(sf::Time time);

	void setChosenPlayer(int i);
	void setBox(std::unique_ptr<b2World>& world);
	virtual void makeVirtural() {};
	void startJump();
	void moveRight();

	void setStratLocation(sf::Vector2f pos);
	sf::Vector2f getStartLocation() const;
	void setSpiked(bool state);
	bool getSpiked() const;
	void setJumping(bool state);

	bool isJumping() const;

private:
	MoveState* m_moveState;
	Singleton& m_resources = Singleton::instance();
	int m_bullets;
	sf::Vector2f m_startLocation;
	bool m_isJumping;
	bool m_spiked = false;
	bool m_jumpKeyPressedLastFrame;
};