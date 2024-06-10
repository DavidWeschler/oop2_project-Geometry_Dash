#include "ContactListener.h"

#include "Player.h"
#include "Block.h"

void ContactListener::BeginContact(b2Contact* contact)
{
    int x;
    x = 7;

    b2Body* firstBody = contact->GetFixtureA()->GetBody();
    b2Body* secondBody = contact->GetFixtureB()->GetBody();
    Object* firstObj = reinterpret_cast<Object*>(firstBody->GetUserData().pointer); //sketchy - ask yehezkel
    Object* secondObj = reinterpret_cast<Object*>(secondBody->GetUserData().pointer); //sketchy - ask yehezkel

    processCollision(*firstObj, *secondObj);
}
