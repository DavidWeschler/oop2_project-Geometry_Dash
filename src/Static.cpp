#include "Static.h"

Static::Static(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position, b2BodyType bodyType)
	: Object(world, color, position)
{
	initBox(world, bodyType);
}

void Static::initBox(std::unique_ptr<b2World>& world, b2BodyType bodyType)
{
	b2FixtureDef fixtureDef;
	b2PolygonShape boxShape;
	b2BodyDef bodyDef;

	bodyDef.type = bodyType;
	bodyDef.position.Set(getPosition().x / 30, getPosition().y / 30);
	bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(this);
	m_box = world->CreateBody(&bodyDef);

	//make better
	if (getColor() == SPACESHIP_PORTAL_C || 
		getColor() == GRAVITY_PORTAL_C || 
		getColor() == FORWARD_PORTAL_C || 
		getColor() == FINISH_PORTAL_C)
	{
		boxShape.SetAsBox(1.0f, 10.0f);
	}
	else if (getColor() == GROUND_JUMP_C)
	{
		boxShape.SetAsBox(1.0f, 0.3f);
	}
	else
	{
		boxShape.SetAsBox(1.0f, 1.0f);
	}


	if (getColor() == BLOCK_C || getColor() == BLOCK_M_C)
	{
		fixtureDef.isSensor = false;	//defult
	}
	else
	{
		fixtureDef.isSensor = true;
	}

	fixtureDef.shape = &boxShape;
	fixtureDef.density = 5.0f;


	m_box->CreateFixture(&fixtureDef);
}