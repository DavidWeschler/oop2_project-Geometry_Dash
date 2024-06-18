#include "Controller.h"
#include "Singleton.h"
#include <iostream>

Controller::Controller()
    : m_menuState(m_choosePlayerState, m_game), m_game(1), m_backgroundMusic(m_musicHandler.getMusicTrack(0))
{
    puts("Controller");
    sf::Image icon;
    if (!icon.loadFromFile("GameIcon.png"))
    {
        exit(EXIT_FAILURE);
    }
    m_window.setFramerateLimit(120);
    m_window.create(sf::VideoMode(WINDOW_X, WINDOW_Y), "Geometry Dash");// , sf::Style::None);
    m_window.setVerticalSyncEnabled(true);

    m_window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    m_currentState = &m_menuState;
    m_transitionSpeed = 45.0f;
    m_r = 130.0f; 
    m_g = 130.0f;
    m_b = 223.0f;
}

void Controller::run()
{
    int phase = 0;

    m_backgroundMusic.play();
    //m_backgroundMusic.setVolume(3);
    m_backgroundMusic.setLoop(true);


    while (m_window.isOpen()) 
    {

        if (playMusic()) m_backgroundMusic.play();
        if (pauseMusic()) m_backgroundMusic.pause();

        sf::Event event;
        while (m_window.pollEvent(event)) 
        {
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


        //sf::Color color(static_cast<sf::Uint8>(m_r), static_cast<sf::Uint8>(m_g), static_cast<sf::Uint8>(m_b));
        sf::Color color(m_r, m_g, m_b);

  
        switchColors(phase);
        m_window.clear(color);
        m_currentState->draw(m_window, m_r, m_g, m_b);
        m_window.display();
        m_time = m_clock.restart();
    }
}

bool Controller::playMusic() const
{
    return m_musicHandler.getBackMusicPlaying() && m_backgroundMusic.getStatus() != sf::Music::Playing;
}

bool Controller::pauseMusic() const
{
    return !m_musicHandler.getBackMusicPlaying();
}

void Controller::switchColors(int& phase)
{
    switch (phase) {
    case 0: // Red to Yellow
        m_r = RGB_UPPER_LIMIT;
        m_g += m_transitionSpeed * m_time.asSeconds();
        if (m_g >= RGB_UPPER_LIMIT) {
            m_g = RGB_UPPER_LIMIT;
            phase = 1;
        }
        break;
    case 1: // Yellow to Green
        m_g = RGB_UPPER_LIMIT;
        m_r -= m_transitionSpeed * m_time.asSeconds();
        if (m_r <= RGB_LOWER_LIMIT) {
            m_r = RGB_LOWER_LIMIT;
            phase = 2;
        }
        break;
    case 2: // Green to Cyan
        m_g = RGB_UPPER_LIMIT;
        m_b += m_transitionSpeed * m_time.asSeconds();
        if (m_b >= RGB_UPPER_LIMIT) {
            m_b = RGB_UPPER_LIMIT;
            phase = 3;
        }
        break;
    case 3: // Cyan to Blue
        m_b = RGB_UPPER_LIMIT;
        m_g -= m_transitionSpeed * m_time.asSeconds();
        if (m_g <= RGB_LOWER_LIMIT) {
            m_g = RGB_LOWER_LIMIT;
            phase = 4;
        }
        break;
    case 4: // Blue to Magenta
        m_b = RGB_UPPER_LIMIT;
        m_r += m_transitionSpeed * m_time.asSeconds();
        if (m_r >= RGB_UPPER_LIMIT) {
            m_r = RGB_UPPER_LIMIT;
            phase = 5;
        }
        break;
    case 5: // Magenta to Red
        m_r = RGB_UPPER_LIMIT;
        m_b -= m_transitionSpeed * m_time.asSeconds();
        if (m_b <= RGB_LOWER_LIMIT) {
            m_b = RGB_LOWER_LIMIT;
            phase = 0;
        }
        break;
    }
}
