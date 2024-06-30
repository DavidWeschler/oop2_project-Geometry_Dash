#pragma once
#pragma region headers
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "GameObj/Object.h"
#include "CollisionHandler.h"
#pragma endregion headers

class ContactListener : public b2ContactListener 
{
public:
    void BeginContact(b2Contact* contact) override;
};