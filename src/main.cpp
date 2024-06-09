#include "Controller.h"

int main() try {

	Controller controller;
	controller.run();
	return EXIT_SUCCESS;
}
catch (std::exception e) {
	std::cout << e.what();
}

//#include <SFML/Graphics.hpp>
//#include <Box2D/Box2D.h>
//
//const float SCALE = 30.0f; // Box2D to pixel scale
//
//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML + Box2D - Flappy Bird Style");
//
//    // Create Box2D world
//    b2Vec2 gravity(0.0f, 9.8f);
//    b2World world(gravity);
//
//    // Create ground
//    b2BodyDef groundBodyDef;
//    groundBodyDef.position.Set(400.0f / SCALE, 500.0f / SCALE); // Bottom of window
//    b2Body* groundBody = world.CreateBody(&groundBodyDef);
//    b2PolygonShape groundBox;
//    groundBox.SetAsBox(400.0f / SCALE, 10.0f / SCALE); // Half-width, half-height
//    groundBody->CreateFixture(&groundBox, 0.0f);
//
//    // Create dynamic body (the red box)
//    b2BodyDef dynamicBodyDef;
//    dynamicBodyDef.type = b2_dynamicBody;
//    dynamicBodyDef.position.Set(100.0f / SCALE, 100.0f / SCALE); // Initial position
//    b2Body* dynamicBody = world.CreateBody(&dynamicBodyDef);
//    b2PolygonShape dynamicBox;
//    dynamicBox.SetAsBox(20.0f / SCALE, 20.0f / SCALE); // Half-width, half-height
//    b2FixtureDef fixtureDef;
//    fixtureDef.shape = &dynamicBox;
//    fixtureDef.density = 1.0f;
//    fixtureDef.friction = 0.3f;
//    dynamicBody->CreateFixture(&fixtureDef);
//
//    sf::RectangleShape boxShape(sf::Vector2f(40.0f, 40.0f));
//    boxShape.setFillColor(sf::Color::Red);
//
//    sf::Clock clock;
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
//            {
//                dynamicBody->ApplyLinearImpulse(b2Vec2(0, -0.2f), dynamicBody->GetWorldCenter(), true);
//            }
//        }
//
//        window.clear(sf::Color::White);
//
//        // Step Box2D world
//        world.Step(clock.restart().asSeconds(), 8, 3);
//
//        // Update SFML shape position
//        b2Vec2 pos = dynamicBody->GetPosition();
//        boxShape.setPosition(pos.x * SCALE - 20.0f, pos.y * SCALE - 20.0f);
//
//        window.draw(boxShape);
//        window.display();
//    }
//
//    return 0;
//}
//
