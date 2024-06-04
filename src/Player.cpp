#include "Player.h"

Player::Player()
{
	//many things related to box2d
}

Player::Player(sf::Texture& texture, sf::Color color, sf::Vector2f pos)
	: Movable(texture, color, pos)
{
	m_bullets = 0;
}

void Player::setChosenPlayer(int i)
{
	setTexture(m_resources.getPlayerTexture(i));
}

void Player::setLocation(sf::Vector2f pos)
{
	setPosition(pos);
}
