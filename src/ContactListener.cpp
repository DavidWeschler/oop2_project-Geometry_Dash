#include "ContactListener.h"

void ContactListener::BeginContact(b2Contact* contact)
{
    // Get colliding fixtures
    b2Body* firstBody = contact->GetFixtureA()->GetBody();
    b2Body* secondBody = contact->GetFixtureB()->GetBody();
    Object* firstObj = (Object*)(firstBody->GetUserData().pointer); //sketchy - ask yehezkel
    Object* secondObj = (Object*)(secondBody->GetUserData().pointer); //sketchy - ask yehezkel

    auto n = std::rand() % 200;
    if (n == 37) { puts("good"); }

    
    processCollision(*firstObj, *secondObj);

    // Handle collision based on user data or fixture properties
    // Your collision handling logic goes here
}
