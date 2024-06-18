#include "UpsideDownState.h"
#include "Player.h"

void UpsideDownState::move(sf::Time time, Player& player)
{
	static float angle = 0;
	static float dest_angle = angle + 180;
	static bool angle_reach = false;
	b2Vec2 boxPos = player.getBoxPosition();

	auto dt = time.asSeconds();

	if (player.isSpiked())
	{
		player.setSpiked(false);
		boxPos.x = player.getStartLocation().x / 30;
		boxPos.y = player.getStartLocation().y / 30;
		player.setBoxTransform(boxPos);
		player.setState(PlayerState::FORWARD_S);
	}

	if (player.isJumping() && player.isOnGround())
	{
		b2Vec2 vel = b2Vec2(player.getBoxLinearVelocity().x, 35);
		player.setBoxLinearVelocity(vel);
		player.setJumping(false);
		player.setOnGround(false);
	}

	if (!player.isOnGround())
	{
		if (angle < dest_angle)
		{
			angle += 4.5;
		}
		else
		{
			angle_reach = true;
		}
		if (!angle_reach)
		{
			player.setRotation(angle);
		}
	}
	else if (angle_reach)
	{
		dest_angle += 180;
		angle_reach = false;
	}


	if (player.gotAKick())
	{
		b2Vec2 vel = b2Vec2(22, player.getBoxLinearVelocity().y + 13);
		player.setBoxLinearVelocity(vel);
		player.arrowTouch(false);

	}
	player.setBoxTransform(boxPos + b2Vec2(VELOCITY * dt, 0.0f));
	player.setPosition(sf::Vector2f(boxPos.x * 30, boxPos.y * 30));
}
