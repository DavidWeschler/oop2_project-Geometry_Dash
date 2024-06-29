#include "MovingStates/FlyState.h"
#include "GameObj/MovablesObj/Player.h"

void FlyState::move(sf::Time time, Player& player)
{
	static float angle = 0;
	static float destAngle = angle + 24;
	static bool angleReach = true;
	b2Vec2 boxPos = player.getBoxPosition();

	auto dt = time.asSeconds();

	if (player.isSpiked())
	{
		player.setStats(NUM_OF_ATTEMPTS_STAT, 1);
		player.setSpiked(false);
		boxPos.x = player.getStartLocation().x / 30;
		boxPos.y = player.getStartLocation().y / 30;
		player.setBoxTransform(boxPos);
		player.setState(PlayerState::FORWARD_S);
	}
	if (player.isJumping())
	{
		b2Vec2 vel = b2Vec2(player.getBoxLinearVelocity().x, -24);
		player.setBoxLinearVelocity(vel);
		player.setJumping(false);
		m_turn = true;
	}
	rotate(player, angle, destAngle, angleReach);

	player.setBoxTransform(boxPos + b2Vec2(VELOCITY * dt, 0.0f));
	player.setPosition(sf::Vector2f(boxPos.x * 30, boxPos.y * 30));
}

void FlyState::rotate(Player& player, float& angle, float& destAngle, bool& angleReach)
{
	if (m_turn)
	{
		if (angle > 0)
		{
			angle -= 2;
		}
		else
		{
			m_turn = false;
			angleReach = false;
		}
		player.setRotation(angle);
	}
	else if (!angleReach)
	{
		if (angle < destAngle)
		{
			angle++;
		}
		else
		{
			angleReach = true;
		}
		player.setRotation(angle);
	}
}
