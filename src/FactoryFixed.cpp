#include "FactoryFixed.h"

#include "Singleton.h"
#include "Object.h"
#include "Static.h"
#include "Movable.h"
#include "Singleton.h"
#include "Block.h"
#include "Spike.h"
//#include "Arrow.h"
#include "GravityPortal.h"
#include "SpaceShipPortal.h"
#include "DirectionPortal.h"

FactoryFixed::FactoryFixed()
{
}


std::unique_ptr<Static> FactoryFixed::createFixed(ObjectTypes type, std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position)
{
    auto it = getFixedMap().find(type);

    if (it == getFixedMap().end()) {
        return nullptr;
    }
    sf::Texture t = sf::Texture();      ///dummy
    return it->second(world, t, color, position);
}


bool FactoryFixed::registeritFixed(ObjectTypes type, std::unique_ptr<Static>(*f)(std::unique_ptr<b2World>&, sf::Texture&, sf::Color, sf::Vector2f))
{
    getFixedMap().emplace(type, f);
    return true;
}


FixedMap& FactoryFixed::getFixedMap()
{
    static FixedMap m_fixedMap;
    return m_fixedMap;
}







//void Factory::setWorld(World& world)
//{
//    m_world = &world;
//}

//void Factory::createObject(sf::Color color, MovablesObj& movables, FixedObj& fixed, sf::Vector2f location)
//{
//    if (color == BLOCK_C)
//    {
//        fixed.push_back(std::make_unique<Block>(*m_world, m_resources.getObjTexture(0), BLOCK_C, location));
//    }
//    else if (color == BLOCK_M_C)
//    {
//        fixed.push_back(std::make_unique<Block>(*m_world, m_resources.getObjTexture(1), BLOCK_C, location));
//    }
//    else if (color == SPIKE_C)
//    {
//        fixed.push_back(std::make_unique<Spike>(*m_world, m_resources.getObjTexture(2), SPIKE_C, location));
//    }
//    else if (color == GRAVITY_PORTAL_C)
//    {
//        fixed.push_back(std::make_unique<GravityPortal>(*m_world, m_resources.getObjTexture(3), GRAVITY_PORTAL_C, location));
//    }
//    else if (color == SPACESHIP_PORTAL_C)
//    {
//        fixed.push_back(std::make_unique<SpaceShipPortal>(*m_world, m_resources.getObjTexture(4), SPACESHIP_PORTAL_C, location));
//
//    }
//    else if (color == DIRECTION_PORTAL_C)
//    {
//        fixed.push_back(std::make_unique<DirectionPortal>(*m_world, m_resources.getObjTexture(5), DIRECTION_PORTAL_C, location));
//            
//    }
//    else if (color == ARROW_C)
//    {
//        fixed.push_back(std::make_unique<Arrow>(*m_world, m_resources.getObjTexture(6), DIRECTION_PORTAL_C, location));
//
//    }
//    else
//    {
//        //enemies
//    }
//
//    //else - maybe throw exception here
//}