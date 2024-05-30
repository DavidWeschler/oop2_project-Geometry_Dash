#include "Controller.h"

Controller::Controller()
    : m_menuState(m_choosePlayerState)
{
	m_window.create(sf::VideoMode(WINDOW_X, WINDOW_Y), "Geometry Dash", sf::Style::None);
    m_currentState = &m_menuState;
}

void Controller::run()
{
    while (m_window.isOpen()) 
    {
        // handle user-input
        sf::Event event;
        while (m_window.pollEvent(event)) 
        {
            GameState* nextState = m_currentState->handleEvent(event, m_window);
            if (nextState)
            {
                m_currentState = nextState;
            }
        }

        // update game world
        //m_currentState->update();
        m_window.clear();
        m_currentState->draw(m_window);
        m_window.display();
    }
}
