#include "ContactListener.h"

void ContactListener::BeginContact(b2Contact* contact)
{
    // Get colliding fixtures
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    // Get user data associated with fixtures (e.g., pointers to game objects)
    b2FixtureUserData& userDataA = fixtureA->GetUserData();
    b2FixtureUserData& userDataB = fixtureB->GetUserData();

    auto n = std::rand() % 200;
    if (n == 37) { puts("good"); }

    // Handle collision based on user data or fixture properties
    // Your collision handling logic goes here
}
