#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Object.h"
#include "CollisionHandler.h"

class ContactListener : public b2ContactListener 
{
public:
    void BeginContact(b2Contact* contact) override;

private:
};

//https://stackoverflow.com/questions/7864037/box2d-contact-listener