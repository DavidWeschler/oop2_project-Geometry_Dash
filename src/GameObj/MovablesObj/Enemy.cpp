#include "GameObj/MovablesObj/Enemy.h"

Enemy::Enemy(World& world, sf::Vector2f position, sf::Vector2f boxSize)
	: Movable(world, position, boxSize, false)
{}