#include "UpsideDownState.h"
#include "Player.h"

void UpsideDownState::move(sf::Time time, Player& player)
{
	b2Vec2 boxPos = player.getBox()->GetPosition();

	auto dt = time.asSeconds();

	if (player.isSpiked())
	{
		player.setSpiked(false);
		boxPos.x = player.getStartLocation().x / 30;
		boxPos.y = player.getStartLocation().y / 30;
		player.getBox()->SetTransform(boxPos, true);
	}

	if (player.isJumping() && player.isOnGround())
	{
		b2Vec2 vel = b2Vec2(player.getBox()->GetLinearVelocity().x, 35);
		//getBox()->ApplyLinearImpulseToCenter(vel, true);
		player.getBox()->SetLinearVelocity(vel);
		player.setJumping(false);
		player.setOnGround(false);
	}

	if (player.gotAKick())
	{
		player.arrowTouch(false);
		b2Vec2 vel = b2Vec2(22, player.getBox()->GetLinearVelocity().y + 13);
		player.getBox()->SetLinearVelocity(vel);

	}
	player.getBox()->SetTransform(boxPos + b2Vec2(VELOCITY * dt, 0.0f), player.getBox()->GetAngle());
	player.setPosition(sf::Vector2f(boxPos.x * 30, boxPos.y * 30));
}
