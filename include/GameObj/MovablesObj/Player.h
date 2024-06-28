#pragma once

#include <box2d/b2_body.h>
#include "GameObj\MovablesObj\Movable.h"
#include "Singletones/TexturesManger.h"
#include "MovingStates/MoveState.h"
#include "MovingStates/ForwardState.h"
#include "MovingStates/UpsideDownState.h"
#include "MovingStates/UpsideSpaceshipState.h"
#include "MovingStates/FlyState.h"

typedef std::unique_ptr<b2World> World;

class Player : public Movable
{
public:
	Player(World& world, sf::Vector2f pos);
	virtual ~Player() = default;
	virtual void move(sf::Time time);

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
	int getChosenPlayer() const;

	void setNextLevel(bool state);
	bool getNextLevelState() const;

	void setBoxTransform(const b2Vec2& position);
	b2Vec2 getBoxLinearVelocity() const;
	void setBoxLinearVelocity(const b2Vec2& vel);
	float getBoxAngle() const;

	PlayerState getStateType() const;

	//bool getSwitch() const;
	void changeState(World& world);
	void setState(PlayerState state);
	bool isJumping() const;
	void setGroundJumpDelta(int delta);
	int getGroundJumpDelta() const;

	void insertBox(World& world, int i, sf::Vector2f boxValues); //private?

	b2Vec2 getBoxPosition() const;
	void handleForwardState(World& world);
private:
	void makeShip(World& world);

	void handleSpaceShipState(World& world);
	void handleUpsideDownState(World& world);
	void handleUpsideDownShipState(World& world);

	MoveState* m_moveState;
	FlyState m_flyState;
	UpsideDownState m_upsideDownState;
	UpsideSpaceshipState m_upsideSpaceship;
	ForwardState m_forwardState;
	TexturesManger& m_resources = TexturesManger::instance();
	int m_bullets;
	sf::Vector2f m_startLocation;
	bool m_isJumping=false;
	bool m_spiked = false;
	bool m_arrowKick = false;
	bool m_onGround = true;
	bool m_nextLevel = false;
	unsigned int m_setNum;

	int m_groundJumpDelta;

	//bool m_toSwitch = false;
	PlayerState m_currState;
	PlayerState m_nextState;

	sf::Texture m_shipTexture;
};





