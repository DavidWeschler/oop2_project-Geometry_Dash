#include "Enemy.h"

Enemy::Enemy(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position, b2BodyType bodyType, sf::Vector2f boxSize)
	: Movable(world, color, position, boxSize)
{
	//move to .h if its empty
}

