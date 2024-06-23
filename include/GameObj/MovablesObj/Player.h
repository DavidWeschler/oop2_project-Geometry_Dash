#pragma once

#include <box2d/b2_body.h>
#include "GameObj\MovablesObj\Movable.h"
#include "Singleton.h"
#include "MoveState.h"
#include "ForwardState.h"
#include "UpsideDownState.h"
#include "FlyState.h"

class Player : public Movable
{
public:
	Player(std::unique_ptr<b2World>& world, sf::Vector2f pos);
	virtual ~Player() override;
	virtual void move(sf::Time time);
	virtual void makeVirtural() {};

	void setChosenPlayer(int i);

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

	void setNextLevel(bool state);
	bool getNextLevelState() const;

	void setBoxTransform(const b2Vec2& position);
	b2Vec2 getBoxLinearVelocity() const;
	void setBoxLinearVelocity(const b2Vec2& vel);
	float getBoxAngle() const;

	PlayerState getStateType() const;

	bool getSwitch() const;
	void changeState(std::unique_ptr<b2World>& world);
	void setState(PlayerState state);
	bool isJumping() const;
	void setGroundJumpDelta(int delta);
	int getGroundJumpDelta() const;

	void insertBox(std::unique_ptr<b2World>& world, int i, sf::Vector2f boxValues); //private?

	b2Vec2 getBoxPosition() const;

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
	bool m_nextLevel = false;
	int m_setNum;

	int m_groundJumpDelta;

	bool m_toSwitch = false;
	PlayerState m_currState;
	PlayerState m_nextState;

	sf::Texture m_shipTexture;
};





