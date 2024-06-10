#include "Player.h"
#include <cmath>
#define M_PI 3.14159265358979323846

Player::~Player()
{
}

void Player::setChosenPlayer(int i)
{
	setTexture(m_resources.getPlayerTexture(i));
}

void Player::setBox(std::unique_ptr<b2World>& world)
{
	initBox(world);
}

void Player::startJump()
{
	if (!m_isJumping)
	{
		getBox()->SetFixedRotation(true);
		b2Vec2 vel = b2Vec2(getBox()->GetLinearVelocity().x, -120);
		getBox()->ApplyLinearImpulseToCenter(vel, true);
	}
}

//void Player::startJump()
//{
//    if (!m_isJumping)
//    {
//        getBox()->SetFixedRotation(true);
//
//        // Desired jump speed and angle (in degrees)
//        const float JUMP_SPEED = 27.0f; // Adjust as needed
//
//        // Convert the jump angle to radians
//        float jumpAngleRadians = JUMP_ANGLE_DEGREES * (M_PI / 180.0f);
//
//        // Calculate the velocity components
//        float velX = -JUMP_SPEED * std::cos(jumpAngleRadians);
//        float velY = -JUMP_SPEED * std::sin(jumpAngleRadians);
//
//        // Apply the velocity components
//        b2Vec2 vel(velX, velY);
//        getBox()->ApplyLinearImpulseToCenter(vel, true);
//
//        //m_isJumping = true; // Set the jumping state
//    }
//}

// Function to set the player back to a non-jumping state
void Player::land()
{
    m_isJumping = false;
}
