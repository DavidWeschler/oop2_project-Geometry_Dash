#include "MovingStates/ForwardState.h"
#include "GameObj/MovablesObj/Player.h"

void ForwardState::move(sf::Time time, Player& player)
{
	static float angle = 0;
	static float destAngle = 180;
	static bool angleReach = false;
	b2Vec2 boxPos = player.getBoxPosition();

	auto dt = time.asSeconds();

	spiked(player, boxPos, angle);

	jump(player, 1);

	rotate(player, angle, destAngle, angleReach);

	kick(player, -1);

	player.setBoxTransform(boxPos + b2Vec2(VELOCITY * dt, 0.0f));
	player.setPosition(sf::Vector2f(boxPos.x * 30, boxPos.y * 30));
}

void ForwardState::rotate(Player& player, float& angle, float& destAngle, bool& angleReach)
{
	if (!player.isOnGround())
	{
		if (angle < destAngle)
		{
			angle += 4.5;
		}
		else
		{
			angleReach = true;
		}
		if (!angleReach)
		{
			player.setRotation(angle);
		}
	}
	else if (angleReach)
	{
		destAngle += 180;
		angleReach = false;
	}
	else
	{
		int check = int(angle);
		angle = check;
		if (check % 90 != 0)
			angle++;
		player.setRotation(angle);
	}
}
