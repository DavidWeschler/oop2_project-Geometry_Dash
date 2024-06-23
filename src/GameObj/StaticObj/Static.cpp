#include "GameObj/StaticObj/Static.h"

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
	//make better
	if (getColor() == SPACESHIP_PORTAL_C || 
		getColor() == GRAVITY_PORTAL_C || 
		getColor() == FORWARD_PORTAL_C ||
		getColor() == UPSIDESPACESHIP_PORTAL_C)
	{
		bodyDef.position.Set(getPosition().x / 30, (120+getPosition().y) / 30);
		boxShape.SetAsBox(0.8f, 6.0f);
	}
	else if (getColor() == FINISH_PORTAL_C)
	{
		bodyDef.position.Set(getPosition().x / 30, (60 + getPosition().y) / 30);
		boxShape.SetAsBox(0.8f, 15.0f);
	}
	else if (getColor() == GROUND_JUMP_C || getColor()== GROUND_JUMP_U_C)
	{
		boxShape.SetAsBox(1.0f, 0.3f);
	}
	else if (getColor() == AIR_JUMP_C)
	{
		boxShape.SetAsBox(2.0f, 1.5f);
	}
	else if (getColor() == AIR_SPIKE_C)
	{
		boxShape.SetAsBox(2.0f, 2.0f);
	}
	else if (getColor() == LONG_SPIKE_C)
	{
		bodyDef.position.Set((4*60+getPosition().x) / 30, getPosition().y / 30);
		boxShape.SetAsBox(8.0f, 1.f);
	}
	else
	{
		boxShape.SetAsBox(1.0f, 1.0f);
	}

	m_box = world->CreateBody(&bodyDef);

	if (getColor() == BLOCK_C || getColor() == BLOCK_M_C || getColor()== BLOCK_V_C)
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