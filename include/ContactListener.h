#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class ContactListener : public b2ContactListener 
{
public:
    ContactListener() { puts("creating listener\n"); }

    void BeginContact(b2Contact* contact) override;

private:
};

//https://stackoverflow.com/questions/7864037/box2d-contact-listener