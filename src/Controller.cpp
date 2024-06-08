#include "Controller.h"
#include<iostream>

Controller::Controller()
    : m_menuState(m_choosePlayerState, m_game), m_game(1)
{
	m_window.create(sf::VideoMode(WINDOW_X, WINDOW_Y), "Geometry Dash", sf::Style::None);
    m_currentState = &m_menuState;
    m_transitionSpeed = 10.0f;
}

void Controller::run()
{
    float r = 130.0f, g = 130.0f, b = 223.0f;
    int phase = 0;

    while (m_window.isOpen()) {
        m_time = m_clock.restart();

        // Handle user-input
        sf::Event event;
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                m_window.close();
            }

            GameState* nextState = m_currentState->handleEvent(event, m_window, m_time);
            if (nextState) {
                m_currentState = nextState;
            }
        }

        // Update game world
        m_currentState->update(m_time);

        switchColors(phase, r, g, b);

        sf::Color color(static_cast<sf::Uint8>(r), static_cast<sf::Uint8>(g), static_cast<sf::Uint8>(b));
        m_window.clear(color);
        m_currentState->draw(m_window);
        m_window.display();
    }
}

void Controller::switchColors(int& phase, float&r, float&g, float&b)
{
    switch (phase) {
    case 0: // Red to Yellow
        r = 255;
        g += m_transitionSpeed * m_time.asSeconds();
        if (g >= 255) {
            g = 255;
            phase = 1;
        }
        break;
    case 1: // Yellow to Green
        g = 255;
        r -= m_transitionSpeed * m_time.asSeconds();
        if (r <= 0) {
            r = 0;
            phase = 2;
        }
        break;
    case 2: // Green to Cyan
        g = 255;
        b += m_transitionSpeed * m_time.asSeconds();
        if (b >= 255) {
            b = 255;
            phase = 3;
        }
        break;
    case 3: // Cyan to Blue
        b = 255;
        g -= m_transitionSpeed * m_time.asSeconds();
        if (g <= 0) {
            g = 0;
            phase = 4;
        }
        break;
    case 4: // Blue to Magenta
        b = 255;
        r += m_transitionSpeed * m_time.asSeconds();
        if (r >= 255) {
            r = 255;
            phase = 5;
        }
        break;
    case 5: // Magenta to Red
        r = 255;
        b -= m_transitionSpeed * m_time.asSeconds();
        if (b <= 0) {
            b = 0;
            phase = 0;
        }
        break;
    }
}
