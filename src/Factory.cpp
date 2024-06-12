#include "Factory.h"

Factory::Factory()
{
}

void Factory::setWorld(World& world)
{
    m_world = &world;
}

void Factory::createObject(sf::Color color, MovablesObj& movables, FixedObj& fixed, sf::Vector2f location)
{
    if (color == BLOCK_C)
    {
        fixed.push_back(std::make_unique<Block>(*m_world, m_resources.getObjTexture(0), BLOCK_C, location));
    }
    else if (color == SPIKE_C)
    {
        fixed.push_back(std::make_unique<Spike>(*m_world, m_resources.getObjTexture(1), SPIKE_C, location));
    }
    else if (color == GRAVITY_PORTAL_C)
    {
        fixed.push_back(std::make_unique<GravityPortal>(*m_world, m_resources.getObjTexture(2), GRAVITY_PORTAL_C, location));
    }
    else if (color == SPACESHIP_PORTAL_C)
    {
        fixed.push_back(std::make_unique<SpaceShipPortal>(*m_world, m_resources.getObjTexture(3), SPACESHIP_PORTAL_C, location));

    }
    else if (color == DIRECTION_PORTAL_C)
    {
        fixed.push_back(std::make_unique<DirectionPortal>(*m_world, m_resources.getObjTexture(4), DIRECTION_PORTAL_C, location));
            
    }
    else if (color == ARROW_C)
    {
        fixed.push_back(std::make_unique<Arrow>(*m_world, m_resources.getObjTexture(5), DIRECTION_PORTAL_C, location));

    }
    else
    {
        //enemies
    }

    //else - maybe throw exception here
}