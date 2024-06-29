#include "MovingStates/MoveState.h"
#include "GameObj/MovablesObj/Player.h"

void MoveState::spiked(Player& player, b2Vec2& boxPos, float &angle)
{
	if (player.isSpiked())
	{
		player.setStats(NUM_OF_ATTEMPTS_STAT, 1);
		player.setSpiked(false);
		boxPos.x = player.getStartLocation().x / 30;
		boxPos.y = player.getStartLocation().y / 30;
		player.setBoxTransform(boxPos);
		player.setState(PlayerState::FORWARD_S);
		angle = 0;
	}
}

void MoveState::jump(Player& player, int delta)
{
	if (player.isJumping() && player.isOnGround())
	{
		player.setStats(NUM_OF_JUMPS_STAT, 1);
		auto yJump = delta * (- 35 + player.getGroundJumpDelta());
		player.setGroundJumpDelta(0);
		b2Vec2 vel = b2Vec2(player.getBoxLinearVelocity().x, yJump);
		player.setBoxLinearVelocity(vel);
		player.setJumping(false);
		player.setOnGround(false);
	}
}

void MoveState::kick(Player& player, int delta)
{
	if (player.gotAKick())
	{
		b2Vec2 vel = b2Vec2(22, player.getBoxLinearVelocity().y + delta*13);
		player.setBoxLinearVelocity(vel);
	}
	player.arrowTouch(false);
}
