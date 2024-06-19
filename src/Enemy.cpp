#include "Enemy.h"

Enemy::Enemy(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position, b2BodyType bodyType, sf::RectangleShape* enemy)
	: Movable(world, color, position, enemy)
{
	//move to .h if its empty
}

