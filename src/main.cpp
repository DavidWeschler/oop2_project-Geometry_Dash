#include "Controller.h"

int main() try {

	Controller controller;
	controller.run();
	return EXIT_SUCCESS;
}
catch (...) {
	/////a
}

//#include <SFML/Graphics.hpp>
//#include <Box2D/Box2D.h>
//
//#define SCALE       30.0f  // Conversion factor between box2D units and pixels

//int main() 
//{
//    // Create the window
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Box2D SFML Example");
//
//    // Create the Box2D world
//    b2Vec2 gravity(0.0f, 18.81f);  // Set gravity
//    b2World world(gravity);
//
//    // Create a dynamic box
//    b2BodyDef bodyDef;
//    bodyDef.type = b2_dynamicBody;
//    bodyDef.position.Set(window.getSize().x / (2.0f * SCALE), window.getSize().y / (2.0f * SCALE));
//    b2Body* box = world.CreateBody(&bodyDef);
//
//    // Define the shape of the box
//    b2PolygonShape boxShape;
//    boxShape.SetAsBox(2.0f, 1.0f);  // Half-width and half-height
//
//    // Add the shape to the body and set mass/density
//    b2FixtureDef fixtureDef;
//    fixtureDef.shape = &boxShape;
//    fixtureDef.density = 1.0f;
//    box->CreateFixture(&fixtureDef);
//
//    // Create a clock for delta time calculation
//    sf::Clock clock;
//
//    while (window.isOpen()) 
//    {
//        sf::Event event;
//        while (window.pollEvent(event)) 
//        {
//            if (event.type == sf::Event::Closed) {
//                window.close();
//            }
//        }
//
//        // Get delta time since last frame
//        float dt = clock.restart().asSeconds();
//
//        // Move the box based on user input (replace with your desired movement logic)
//        const float force = 5.0f;
//        if (true || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
//            box->ApplyLinearImpulseToCenter(b2Vec2(-force * dt - 0.1, 0.0f), true);
//        }
//        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
//            box->ApplyLinearImpulseToCenter(b2Vec2(force * dt + 0.1, 0.0f), true);
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
//            box->ApplyLinearImpulseToCenter(b2Vec2(0.0f, force * dt - 0.1f), true);  // Adjust vertical force
//        }
//        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
//            box->ApplyLinearImpulseToCenter(b2Vec2(0.0f, -force * dt + 0.1f), true);  // Adjust vertical force
//        }
//        // Simulate the Box2D world
//        world.Step(dt, 8, 3);
//
//        // Clear the window
//        window.clear();
//
//        // Get the position of the box in pixels
//        b2Vec2 position = box->GetPosition();
//        position.x *= SCALE;
//        position.y *= SCALE;
//
//        // Create a rectangle to represent the box visually
//        sf::RectangleShape boxSprite(sf::Vector2f(40.0f, 20.0f));  // Adjust size based on box shape
//        boxSprite.setPosition(position.x, position.y);
//        boxSprite.setFillColor(sf::Color::Red);
//
//
//        sf::View view(sf::FloatRect(300, 300, WINDOW_X / 3, WINDOW_Y / 3));
//        window.setView(view);
//        view.setCenter(position.x, position.y);
//        window.setView(view);
//
//        // Draw the box
//        window.draw(boxSprite);
//
//        window.display();
//    }
//
//    return 0;
//}
