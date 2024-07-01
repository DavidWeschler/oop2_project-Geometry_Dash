#pragma region headers
#include "MovingStates/FlyState.h"
#include "GameObj/MovablesObj/Player.h"
#pragma endregion headers

void FlyState::move(sf::Time time, Player& player)
{
	static float angle = 0;
	static float destAngle = angle + 24;
	static bool angleReach = true;
	b2Vec2 boxPos = player.getBoxPosition();

	auto dt = time.asSeconds();

	spiked(player, boxPos, angle);
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
		if (angle > 0) angle -= 2;
		else angleReach = m_turn = false;
	}
	else if (!angleReach)
	{
		if (angle < destAngle) angle++;
		else angleReach = true;
	}
	player.setRotation(angle);
}
