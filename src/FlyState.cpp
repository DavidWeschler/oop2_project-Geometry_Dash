#include "FlyState.h"
#include "Player.h"

void FlyState::move(sf::Time time, Player& player)
{
	static float angle = 0;
	static float dest_angle = angle + 24;
	static bool angle_reach = true;
	static bool my_turn = false;
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
	if (player.isJumping())
	{
		b2Vec2 vel = b2Vec2(player.getBoxLinearVelocity().x, -35);
		player.setBoxLinearVelocity(vel);
		player.setJumping(false);
		my_turn = true;
	}

	if (my_turn)
	{
		if (angle > 0)
		{
			angle-=2;
		}
		else
		{
			my_turn = false;
			angle_reach = false;
		}
		player.setRotation(angle);	
	}
	else if(!angle_reach)
	{
		if (angle < dest_angle)
		{
			angle++;
		}
		else
		{
			angle_reach = true;
		}
		player.setRotation(angle);
		
	}


	player.setBoxTransform(boxPos + b2Vec2(VELOCITY * dt, 0.0f));
	player.setPosition(sf::Vector2f(boxPos.x * 30, boxPos.y * 30));
}
