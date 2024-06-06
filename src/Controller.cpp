#include "Controller.h"
#include<iostream>

Controller::Controller()
    : m_menuState(m_choosePlayerState, m_game), m_game(1)
{
	m_window.create(sf::VideoMode(WINDOW_X, WINDOW_Y), "Geometry Dash", sf::Style::None);
    m_currentState = &m_menuState;
}

void Controller::run()
{
    m_time = m_clock.restart();

    while (m_window.isOpen()) 
    {
        // handle user-input
        sf::Event event;
        while (m_window.pollEvent(event)) 
        {
            GameState* nextState = m_currentState->handleEvent(event, m_window, m_time);        //maybe get rifd of time here
            if (nextState)
            {
                m_currentState = nextState;
            }
        }

        sf::View view(sf::FloatRect(300,300, WINDOW_X/0.4, WINDOW_Y/0.4));
        view.setCenter(WINDOW_X / 0.8, WINDOW_Y/0.8);
        m_window.setView(view);

        // update game world
        m_currentState->update(m_time);
        m_window.clear(sf::Color(204,255,153));
        m_currentState->draw(m_window);
        m_window.display();
    }
}
