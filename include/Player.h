#pragma once

#include <box2d/b2_body.h>
#include "Movable.h"
#include "Singleton.h"
#include "MoveState.h"
#include "ForwardState.h"
#include "UpsideDownState.h"
#include "FlyState.h"

class Player : public Movable
{
public:
	Player(std::unique_ptr<b2World>& world, sf::Texture& texture, sf::Color color, sf::Vector2f pos);
	virtual ~Player() override;
	/*virtual*/ void move(sf::Time time);

	void setChosenPlayer(int i);
	void setBox(std::unique_ptr<b2World>& world);
	virtual void makeVirtural() {};

	void setStratLocation(sf::Vector2f pos);
	sf::Vector2f getStartLocation() const;
	void setSpiked(bool state);
	bool isSpiked() const;
	void arrowTouch(bool state);
	bool gotAKick() const;
	void setJumping(bool state);
	void setOnGround(bool state);
	bool isOnGround() const;
	void setSetNum(int i);
	int getSetNum() const;

	PlayerState getStateType() const;

	bool getSwitch() const;

	void changeState(std::unique_ptr<b2World>& world);

	void setState(PlayerState state);
	bool isJumping() const;

private:
	void makeShip(std::unique_ptr<b2World>& world);
	MoveState* m_moveState;
	FlyState m_flyState;
	UpsideDownState m_upsideDownState;
	ForwardState m_forwardState;
	Singleton& m_resources = Singleton::instance();
	int m_bullets;
	sf::Vector2f m_startLocation;
	bool m_isJumping=false;
	bool m_spiked = false;
	bool m_arrowKick = false;
	bool m_onGround = true;
	int m_setNum;

	bool m_toSwitch = false;
	PlayerState m_currState;
	PlayerState m_nextState;

	sf::Texture m_shipTexture;
};





