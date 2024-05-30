#include "ChoosePlayer.h"

ChoosePlayer::ChoosePlayer(sf::Vector2i windowSize)
	: m_winSize(windowSize), m_exitButton(sf::Vector2f(m_winSize.x * 157 / 160, m_winSize.y / 30), sf::Vector2f(m_winSize.x / 32, m_winSize.x / 32), RETURN, m_resources.getButtonTextures(0))
{
	setButtons();
}

void ChoosePlayer::setButtons()
{
	for (int i = 0; i <NUM_OF_CHOOSE_BUTTONS; i++)
	{
		m_setsButtons.push_back(Button(sf::Vector2f(i*100 + m_winSize.x * 3 / 4, m_winSize.y / 4), sf::Vector2f(m_winSize.x / 5, m_winSize.x / 7), DEFAULT, m_resources.getSetButtonName(i)));
	}
}

void ChoosePlayer::go(sf::RenderWindow& window)
{
	while (window.isOpen())
	{
		window.clear(sf::Color(230,194,73));
		draw(window);
		window.display();

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
					return;
				break;

			case sf::Event::MouseButtonPressed:
				auto ret = false;
				handleChoice(event.mouseButton, ret);
				if (ret) return;
				break;
			}
		}
		m_exitButton.getGlobalBound().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) ?
												m_exitButton.setScale(1.1f, 1.1f) : m_exitButton.setScale(1.0f, 1.0f);
		for (int i = 0; i < NUM_OF_CHOOSE_SETS; i++)
		{
			m_setsButtons[i].getGlobalBound().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) ?
													   m_setsButtons[i].setScale(1.1f, 1.1f) : m_setsButtons[i].setScale(1.0f, 1.0f);
		}
	}
}

void ChoosePlayer::handleChoice(const sf::Event::MouseButtonEvent& event, bool& ret)
{
	for (int i = 0; i < NUM_OF_CHOOSE_BUTTONS; i++)
	{
		if (m_buttons[i].getGlobalBound().contains(event.x, event.y))
		{
			if (m_buttons[i].getType() == RETURN) {
				puts("RETURN");
				ret = true;
			}
		}
	}
}

void ChoosePlayer::draw(sf::RenderWindow& window)
{
	for (auto i = 0; i < m_buttons.size(); i++)
	{
		m_buttons[i].draw(window);
	}
}