#include "CollisionHandler.h"

#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>

#include "Player.h"
#include "Block.h"
#include "Spike.h"
#include "Arrow.h"
#include "SpaceShipPortal.h"
#include "ForwardPortal.h"
#include "GravityPortal.h"
#include "Movable.h"
#include "Static.h"
#include "AirJump.h"
#include "GroundJump.h"

//and many more

namespace // anonymous namespace — the standard way to make function "static"
{
    // primary collision-processing functions
    void playerSpike(Object& player, Object& spike)
    {
        static_cast<Player&>(player).setSpiked(true);
        static_cast<Player&>(player).setState(PlayerState::FORWARD_S);
    }

    void spikePlayer(Object& spike, Object& player)
    {
        playerSpike(player, spike);
    }

    void playerBlock(Object& player, Object& block)
    {
        Player *p = &static_cast<Player&>(player);
        p->setOnGround(true);
        p->setGroundJumpDelta(0); //voids the groung jump effect

        sf::FloatRect playerRect = player.getShapeGlobalBounds();
        sf::FloatRect blockRect = block.getShapeGlobalBounds();

        bool isCollidingFromTop = (p->getStateType() == PlayerState::UPSIDEDOWN_S) ? 
            playerRect.top + playerRect.height > blockRect.top + 60 :
            playerRect.top + playerRect.height < blockRect.top + 60;

        if (!isCollidingFromTop)
        {
            playerSpike(player, block);
        }
    }

    void blockPlayer(Object& block, Object& player)
    {
        playerBlock(player, block);
    }


    void playerArrow(Object& player, Object& arrow)
    {
        static_cast<Player&>(player).arrowTouch(true);
    }

    void arrowPlayer(Object& arrow, Object& player)
    {
        playerArrow(player, arrow);
    }

    void playerSpaceShipPortal(Object& player, Object& spaceShipPortal)
    {
        static_cast<Player&>(player).setState(PlayerState::SPACESHIP_S);
    }

    void spaceShipPortalPlayer(Object& spaceShipPortal, Object& player)
    {
        playerSpaceShipPortal(player, spaceShipPortal);
    }

    void playerForwardPortal(Object& player, Object& forwardPortal)
    {
        static_cast<Player&>(player).setState(PlayerState::FORWARD_S);
    }

    void ForwardPortalPlayer(Object& forwardPortal, Object& player)
    {
        playerForwardPortal(player, forwardPortal);
    }

    void playerGravityPortal(Object& player, Object& forwardPortal)
    {
        static_cast<Player&>(player).setState(PlayerState::UPSIDEDOWN_S);
    }

    void GravityPortalPlayer(Object& forwardPortal, Object& player)
    {
        playerGravityPortal(player, forwardPortal);
    }

    void playerAirJump(Object& player, Object& airJump)
    {
        Player *p = &static_cast<Player&>(player);
        p->setGroundJumpDelta(-25);
        p->setOnGround(true);
        /*   if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || 
            sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
        }  */      
    }

    void AirJumpPlayer(Object& airJump, Object& player)
    {
        playerAirJump(player, airJump);
    }

    void playerGroundJumpJump(Object& player, Object& groundJump)
    {
        Player* p = &static_cast<Player&>(player);
        p->setJumping(true);
        p->setGroundJumpDelta(-30);
    }

    void GroundJumpJumpPlayer(Object& groundJump, Object& player)
    {
        playerGroundJumpJump(player, groundJump);
    }



    using HitFunctionPtr = void (*)(Object&, Object&);
    // typedef void (*HitFunctionPtr)(GameObject&, GameObject&);
    using Key = std::pair<std::type_index, std::type_index>;
    // std::unordered_map is better, but it requires defining good hash function for pair
    using HitMap = std::map<Key, HitFunctionPtr>;
    
    HitMap initializeCollisionMap()
    {
        HitMap phm;
        phm[Key(typeid(Player), typeid(Block))] = &playerBlock;
        phm[Key(typeid(Block), typeid(Player))] = &blockPlayer;
        phm[Key(typeid(Player), typeid(Spike))] = &playerSpike;
        phm[Key(typeid(Spike), typeid(Player))] = &spikePlayer;       
        phm[Key(typeid(Player), typeid(Arrow))] = &playerArrow;
        phm[Key(typeid(Arrow), typeid(Player))] = &arrowPlayer;
        phm[Key(typeid(Player), typeid(SpaceShipPortal))] = &playerSpaceShipPortal;
        phm[Key(typeid(SpaceShipPortal), typeid(Player))] = &spaceShipPortalPlayer;
        phm[Key(typeid(Player), typeid(ForwardPortal))] = &playerForwardPortal;
        phm[Key(typeid(ForwardPortal), typeid(Player))] = &ForwardPortalPlayer;
        phm[Key(typeid(Player), typeid(GravityPortal))] = &playerGravityPortal;
        phm[Key(typeid(GravityPortal), typeid(Player))] = &GravityPortalPlayer;
        phm[Key(typeid(Player), typeid(AirJump))] = &playerAirJump;
        phm[Key(typeid(AirJump), typeid(Player))] = &AirJumpPlayer;
        phm[Key(typeid(Player), typeid(GroundJump))] = &playerGroundJumpJump;
        phm[Key(typeid(GroundJump), typeid(Player))] = &GroundJumpJumpPlayer;

        //add more

        /*phm[Key(typeid(SpaceShip), typeid(SpaceStation))] = &shipStation;
        phm[Key(typeid(Asteroid), typeid(SpaceStation))] = &asteroidStation;*/
        //...
        return phm;
    }

    HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
    {
        static HitMap collisionMap = initializeCollisionMap();
        auto mapEntry = collisionMap.find(std::make_pair(class1, class2));

        //std::cout << "end: " << class1.name() << " with " << class2.name() << std::endl;
        if (mapEntry == collisionMap.end())
        {
            return nullptr;
        }
        return mapEntry->second;
    }
}

void processCollision(Object& object1, Object& object2)
{
    auto phf = lookup(typeid(object1), typeid(object2));

    if (!phf)
    {
        return; //erase
        //throw UnknownCollision(object1, object2);
    }
    phf(object1, object2);
}
