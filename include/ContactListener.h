#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class ContactListener : public b2ContactListener 
{
public:
    ContactListener() { puts("creating listener\n"); }

    void BeginContact(b2Contact* contact) override
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
private:
};

//https://stackoverflow.com/questions/7864037/box2d-contact-listener