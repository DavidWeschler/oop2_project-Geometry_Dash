#include "ScreenStates/Controller.h"
#include "Singletones/TexturesManger.h"
#include <iostream>

Controller::Controller()
    : m_window(sf::VideoMode(WINDOW_X, WINDOW_Y), "Geometry Dash", sf::Style::None),
     m_menuState(m_choosePlayerState, m_game, *this, m_window), 
     m_game(*this), m_choosePlayerState(*this),
     m_nextLevelWindow(*this, m_game), 
     m_howToPlay(*this),
     m_stats(*this, m_game),
     m_r(130), m_g(130), m_b(223),
     m_transitionSpeed(45.0f)
{
    sf::Image icon;
    m_choosePlayerState.setExitButton(*this);
    if (!icon.loadFromFile("GameIcon.png")) exit(EXIT_FAILURE);

    m_cursorSprite.setTexture(m_resources.getCursor());
    m_window.setMouseCursorVisible(false);

    m_window.setFramerateLimit(120);
    m_window.setVerticalSyncEnabled(true);
    m_window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    m_currentState = &m_menuState;
}

void Controller::run()
{
    int colorPhase = 0;
    while (m_window.isOpen()) 
    {
        sf::Event event;
        while (m_window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed) m_window.close();
            updateCursor(event);
            enableWindowDragging(event);

            m_currentState->handleEvent(event, m_window);
        }

        m_cursorSprite.setPosition(static_cast<float>(sf::Mouse::getPosition(m_window).x), static_cast<float>(sf::Mouse::getPosition(m_window).y));
        m_currentState->update(m_time);
  
        switchColors(colorPhase);
        m_window.clear();
        m_currentState->draw(m_window, m_r, m_g, m_b);
        m_window.draw(m_cursorSprite);
        m_window.display();
        m_time = m_clock.restart();
    }
}

void Controller::updateCursor(const sf::Event& event)
{
    if (event.type == sf::Event::MouseMoved && m_isMouseDragging)
        m_window.setPosition(m_window.getPosition() + sf::Vector2<int>(event.mouseMove.x - m_lastDown.x, event.mouseMove.y - m_lastDown.y));  
}

void Controller::enableWindowDragging(const sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        m_lastDown.x = event.mouseButton.x;
        m_lastDown.y = event.mouseButton.y;
        m_isMouseDragging = true;
    }
    if (event.type == sf::Event::MouseButtonReleased) m_isMouseDragging = false;
    
}

void Controller::switchState(GameStates nextState)
{
    switch (nextState)
    {
    case GameStates::MENU_S:
        if(m_currentState !=&m_choosePlayerState && m_currentState != &m_howToPlay && m_currentState != &m_stats)
            m_menuState.setReplaceMusic(true);
        m_currentState = &m_menuState;
        break;
    case GameStates::GAME_S:
        m_game.setReplaceMusic(true);
        m_currentState = &m_game;
        break;
    case GameStates::CHOOSE_PLAYER_S:
        m_currentState = &m_choosePlayerState;
        break;
    case GameStates::NEXT_LEVEL_S:
        m_currentState = &m_nextLevelWindow;
        m_nextLevelWindow.setReplaceMusic(true);
        break;
    case GameStates::HOW_TO_PLAY_S:
        m_currentState = &m_howToPlay;
        break;
    case GameStates::STATISTICS_S:
        m_currentState = &m_stats;
        break;
    }

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
