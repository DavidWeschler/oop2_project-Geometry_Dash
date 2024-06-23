#include "FactoryFixed.h"

#include "Singleton.h"
#include "Object.h"
#include "GameObj/StaticObj/Static.h"
#include "Singleton.h"
#include "GameObj/StaticObj/Block.h"
#include "GameObj/StaticObj/Spike.h"
#include "GameObj/StaticObj/Arrow.h"
#include "GameObj/StaticObj/Portals/GravityPortal.h"
#include "GameObj/StaticObj/Portals/SpaceShipPortal.h"
#include "GameObj/StaticObj/Portals/ForwardPortal.h"

std::unique_ptr<Static> FactoryFixed::createFixed(ObjectTypes type, World& world, sf::Color color, sf::Vector2f position)
{
    auto it = getFixedMap().find(type);

    if (it == getFixedMap().end()) 
    {
        return nullptr;     //throw
    }
    return it->second(world, color, position); //this is where all the magic happens :) the static object is created here and returned (unique)
}

FixedMap& FactoryFixed::getFixedMap()
{
    static FixedMap m_fixedMap;
    return m_fixedMap;
}

bool FactoryFixed::registeritFixed(ObjectTypes type, std::unique_ptr<Static>(*f)(World&, sf::Color, sf::Vector2f))
{
    getFixedMap().emplace(type, f);
    return true;
}