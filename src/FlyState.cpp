#include "FlyState.h"
#include "Player.h"

void FlyState::move(sf::Time time, Player& player)
{
	b2Vec2 boxPos = player.getBoxPosition();

	auto dt = time.asSeconds();

	if (player.isSpiked())
	{
		player.setSpiked(false);
		boxPos.x = player.getStartLocation().x / 30;
		boxPos.y = player.getStartLocation().y / 30;
		player.setBoxTransform(boxPos, true);
		player.setState(PlayerState::FORWARD_S);
	}
	if (player.isJumping())
	{
		b2Vec2 vel = b2Vec2(player.getBoxLinearVelocity().x, -35);
		player.setBoxLinearVelocity(vel);
		player.setJumping(false);
	}

	player.setBoxTransform(boxPos + b2Vec2(VELOCITY * dt, 0.0f), player.getBoxAngle());
	player.setPosition(sf::Vector2f(boxPos.x * 30, boxPos.y * 30));
}
