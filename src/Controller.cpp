#include "Controller.h"
#include "Singleton.h"
#include <iostream>

Controller::Controller()
    : m_window(sf::VideoMode(WINDOW_X, WINDOW_Y), "Geometry Dash"),// , sf::Style::None);
     m_backgroundMusic(m_musicHandler.getMusicTrack(0)), 
     m_menuState(m_choosePlayerState, m_game, *this, m_musicHandler.getMusicTrack(0), m_window), 
     m_game(1, *this, m_menuState, m_backgroundMusic), m_choosePlayerState(*this)
{
    m_choosePlayerState.setExitButton(*this);
    sf::Image icon;
    if (!icon.loadFromFile("GameIcon.png"))
    {
        exit(EXIT_FAILURE);
    }
    m_window.setMouseCursorVisible(false);

    m_cursorSprite.setTexture(m_resources.getCursor());

    m_window.setFramerateLimit(120);
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

    /*m_backgroundMusic.play();
    m_backgroundMusic.setVolume(100);
    m_backgroundMusic.setLoop(true);*/

    while (m_window.isOpen()) 
    {
        sf::Event event;
        while (m_window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed) {
                m_window.close();
            }
            m_currentState->handleEvent(event, m_window, m_time);
        }

        m_cursorSprite.setPosition(static_cast<float>(sf::Mouse::getPosition(m_window).x), static_cast<float>(sf::Mouse::getPosition(m_window).y));
        // Update game world
        m_currentState->update(m_time);
        sf::Color color(m_r, m_g, m_b);
  
        switchColors(phase);
        m_window.clear(color);
        m_currentState->draw(m_window, m_r, m_g, m_b);
        m_window.draw(m_cursorSprite);
        m_window.display();
        m_time = m_clock.restart();
    }
}

void Controller::switchState(GameState* nextState)
{
    m_currentState = nextState;
}

bool Controller::playMusic() const
{
    return m_musicHandler.getBackMusicPlaying() && m_backgroundMusic.getStatus() != sf::Music::Playing;
}

void Controller::muteMusic()
{
    m_backgroundMusic.pause();
}

void Controller::resumeMusic()
{
    m_backgroundMusic.play();
}

void Controller::switchTrack(int track)
{
    //
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
