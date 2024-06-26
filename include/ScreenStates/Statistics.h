#pragma once

#include "SFML/Graphics.hpp"
#include "ScreenStates/GameState.h"
#include "Singletones/GlobalConsts.h"
#include "Singletones/TexturesManger.h"
#include "ButtonCommand/NextStateCommand.h"
#include "ButtonCommand/Button.h"

class Controller;

class Statistics : public GameState
{
public:
    Statistics(Controller& controller);
    virtual void handleEvent(const sf::Event&, sf::RenderWindow&, sf::Time time);
    virtual void update(sf::Time) {};
    virtual void draw(sf::RenderWindow&, int, int, int);
    virtual void setSwitchMusic() {};
    virtual ~Statistics() = default;
private:
    void setButtons(Controller& controller);
    TexturesManger& m_resources = TexturesManger::instance();
    sf::RectangleShape m_background;
    sf::Text m_stats;
    std::vector<Button> m_buttons;
    Controller& m_controller;
};

//for screenshot:
/*#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Screenshot Example");
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S) {
                // Capture the screen and save it as a PNG file
                sf::Texture texture;
                texture.create(window.getSize().x, window.getSize().y);
                texture.update(window);
                sf::Image screenshot = texture.copyToImage();
                screenshot.flipVertically(); // SFML stores images upside-down
                stbi_write_png("screenshot.png", screenshot.getSize().x, screenshot.getSize().y, 4, screenshot.getPixelsPtr(), 0);
                printf("Screenshot saved as screenshot.png\n");
            }
        }

        window.clear(sf::Color::White);
        // draw your content here
        window.display();
    }

    return 0;
}
*/      //for screenshot