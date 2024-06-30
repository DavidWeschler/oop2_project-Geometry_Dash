#pragma once

#pragma region headers
#include <box2d/b2_body.h>
#include "GameObj\MovablesObj\Movable.h"
#include "Singletones/TexturesManger.h"
#include "MovingStates/MoveState.h"
#include "MovingStates/ForwardState.h"
#include "MovingStates/UpsideDownState.h"
#include "MovingStates/UpsideSpaceshipState.h"
#include "MovingStates/FlyState.h"
#pragma endregion headers

class Player : public Movable
{
public:
	Player(World& world, sf::Vector2f pos);
	virtual ~Player() = default;
	virtual void move(sf::Time time);

	void handleForwardState(World& world);

	//set:
	void setChosenPlayer(int i);
	void setSpiked(bool state);
	void arrowTouch(bool state);
	void setJumping(bool state);
	void setOnGround(bool state);
	void setSetNum(int i);
	void setBoxLinearVelocity(const b2Vec2& vel);
	void setBoxTransform(const b2Vec2& position);
	void setState(PlayerState state);
	void setGroundJumpDelta(int delta);
	void setNextLevel(bool state);
	void changeState(World& world);
	void setStats(PlayerStats statistic, int amount);

	//get
	bool isSpiked() const;
	bool isOnGround() const;
	bool isJumping() const;
	bool gotAKick() const;
	bool getNextLevelState() const;
	int getSetNum() const;
	int getGroundJumpDelta() const;
	int getStat(PlayerStats stat) const;
	float getBoxAngle() const;
	PlayerState getStateType() const;
	b2Vec2 getBoxLinearVelocity() const;
	b2Vec2 getBoxPosition() const;
	sf::Vector2f getStartLocation() const;

private:
	void insertBox(World& world, int i, sf::Vector2f boxValues); 
	void makeShip(World& world);
	void handleSpaceShipState(World& world);
	void handleUpsideDownState(World& world);
	void handleUpsideDownShipState(World& world);

	//states
	MoveState* m_moveState;
	FlyState m_flyState;
	UpsideDownState m_upsideDownState;
	UpsideSpaceshipState m_upsideSpaceship;
	ForwardState m_forwardState;
	PlayerState m_currState;
	PlayerState m_nextState;

	TexturesManger& m_resources = TexturesManger::instance();
	sf::Vector2f m_startLocation;
	sf::Texture m_shipTexture;
	std::vector<int> m_stats;
	int m_groundJumpDelta;
	unsigned int m_setNum;
	bool m_isJumping=false;
	bool m_spiked = false;
	bool m_arrowKick = false;
	bool m_onGround = true;
	bool m_nextLevel = false;
};