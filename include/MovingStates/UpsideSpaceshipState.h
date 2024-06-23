#pragma once

#include "MovingStates/MoveState.h"

class Player;

class UpsideSpaceshipState : public MoveState
{
public:
	UpsideSpaceshipState() {};
	virtual void move(sf::Time time, Player& player);
	virtual void rotate(Player& player, float& angle, float& destAngle, bool& angleReach);
	virtual ~UpsideSpaceshipState() = default;
private:
	bool m_turn = false;
};