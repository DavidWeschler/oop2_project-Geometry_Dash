#pragma once

#include "MoveState.h"

class Player;

class FlyState : public MoveState
{
public:
	FlyState() {};
	virtual void move(sf::Time time, Player& player) override;
	virtual void rotate(Player& player, float& angle, float& destAngle, bool& angleReach) {};
	virtual ~FlyState() = default;
private:

	bool m_turn = false;
};