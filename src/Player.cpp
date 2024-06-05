#include "Player.h"

Player::Player()
{
	setTexture(m_resources.getPlayerTexture(0));
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
