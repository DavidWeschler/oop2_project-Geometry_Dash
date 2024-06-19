#include "Enemy.h"

Enemy::Enemy(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position, b2BodyType bodyType, sf::RectangleShape& robot)
	: Movable(world, color, position, robot)
{
	puts("ENEMY");
	//move to .h if its empty
}

