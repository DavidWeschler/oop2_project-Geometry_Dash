#pragma region headers
#include "ScreenStates/Menu.h"
#include <iostream>
#include "ScreenStates/ChoosePlayer.h"
#include "ScreenStates/Game.h"
#include "ScreenStates/Controller.h"
#include "ScreenStates/GameState.h"
#pragma endregion headers

Menu::Menu(ChoosePlayer& choosePlayerState, Game& game, Controller& controller, sf::RenderWindow& window)
	: m_choosePlayer(choosePlayerState), m_game(game)
{
	m_background.setSize(sf::Vector2f(WINDOW_X, WINDOW_Y));
	m_background.setTexture(&m_resources.getMenuBackground(0));

	m_backgroundText.setSize(sf::Vector2f(WINDOW_X, WINDOW_Y));
	m_backgroundText.setTexture(&m_resources.getMenuBackground(1));
	m_choosePlayer.setStates(this);

	setView(sf::FloatRect(0, 0, WINDOW_X, WINDOW_Y));
	setCenterView((float)WINDOW_X / 2, (float)WINDOW_Y / 2);

	setButtons(controller, window);
}

void Menu::setChosenPlayer(int i)
{
	m_game.setChosenPlayer(i);
}

void Menu::setButtons(Controller& controller, sf::RenderWindow& window)
{	
	m_buttonCommands.push_back(std::move(std::make_unique<NextStateCommand>(controller, GameStates::CHOOSE_PLAYER_S)));				//ChoosePlayer Button
	m_buttonCommands.push_back(std::move(std::make_unique<NextStateCommand>(controller, GameStates::GAME_S)));				//The game Button
	m_buttonCommands.push_back(std::move(std::make_unique<MusicCommand>(controller, m_musicHandler.getMusicTrack(0))));							//Music Button
	m_buttonCommands.push_back(std::move(std::make_unique<NextStateCommand>(controller, GameStates::STATISTICS_S)));	// high Score Button
	m_buttonCommands.push_back(std::move(std::make_unique<NextStateCommand>(controller, GameStates::HOW_TO_PLAY_S)));// How to play Button
	m_buttonCommands.push_back(std::move(std::make_unique<ExitCommand>(window)));							//Exit Button
	m_buttonCommands.push_back(std::move(std::make_unique<UrlCommand>("https://www.linkedin.com/in/david-weschler/"))); //Davids's LinkedIn
	m_buttonCommands.push_back(std::move(std::make_unique<UrlCommand>("https://www.linkedin.com/in/ron-avital/")));	// Ron's LinkedIn
	m_buttonCommands.push_back(std::move(std::make_unique<UrlCommand>("https://github.com/DavidWeschler"))); //Davids's git
	m_buttonCommands.push_back(std::move(std::make_unique<UrlCommand>("https://github.com/ron-avital29")));	// Ron's git
	m_buttonCommands.push_back(std::move(std::make_unique<UrlCommand>("https://www.youtube.com/watch?v=Pa6xTSWr5qo"))); //Davids's yt
	m_buttonCommands.push_back(std::move(std::make_unique<UrlCommand>("https://www.youtube.com/watch?v=aJ3BER0DOTw")));	// Ron's yt
	
	// top 3
	for (int i = 1; i <= 3; i++)
	{
		auto j = (i == 2) ? 1.5 : 1;
		m_buttons.push_back(Button(
			sf::Vector2f((i*WINDOW_X /4.f) * 1.f, (WINDOW_Y *2.f/5.f+80.f) * 1.f),
			sf::Vector2f((j* WINDOW_X *1.f/9.f) * 1.f, (j* WINDOW_X *1.f/9.f) * 1.f),
			&m_resources.getMenuButtonTexture(i-1), 
			std::move(m_buttonCommands[i-1])));
	}
	// button 2
	for (int i = 1; i <=2; i++)
	{
		m_buttons.push_back(Button(
			sf::Vector2f((2*i*1.f + 1.f) * WINDOW_X / 8.f, (WINDOW_Y * 3.f / 4.f)),
			sf::Vector2f(WINDOW_X * 3.f/32.f, WINDOW_X * 3.f/32.f),
			&m_resources.getMenuButtonTexture(i+2),
			std::move(m_buttonCommands[2+i])));
	}

	//exit button
	m_buttons.push_back(Button(
		sf::Vector2f(WINDOW_X * 157/160, WINDOW_Y/30), 
		sf::Vector2f(WINDOW_X / 32, WINDOW_X / 32), 
		&m_resources.getBackButtonTexture(0),
		std::move(m_buttonCommands[5])));

	//linkedIn Buttons
	m_buttons.push_back(Button(sf::Vector2f((WINDOW_X * 27.f /32.f) * 1.f, (WINDOW_Y*44.f /45.f) * 1.f), sf::Vector2f(35.f, 35.f), &m_resources.getUrlButtonTexture(0), std::move(m_buttonCommands[6])));
	m_buttons.push_back(Button(sf::Vector2f((WINDOW_X*187.f /1600.f), (WINDOW_Y*44.f /45.f) * 1.f), sf::Vector2f(35.f, 35.f), &m_resources.getUrlButtonTexture(0), std::move(m_buttonCommands[7])));

	//git Buttons
	m_buttons.push_back(Button(sf::Vector2f((WINDOW_X * 27.f / 32.f) * 1.f, (WINDOW_Y * 42 / 45) * 1.f), sf::Vector2f(35.f, 35.f), &m_resources.getUrlButtonTexture(1), std::move(m_buttonCommands[8])));
	m_buttons.push_back(Button(sf::Vector2f((WINDOW_X * 187.f / 1600.f) * 1.f, (WINDOW_Y * 42 / 45) * 1.f), sf::Vector2f(35.f, 35.f), &m_resources.getUrlButtonTexture(1), std::move(m_buttonCommands[9])));
	
	//yt Buttons
	m_buttons.push_back(Button(sf::Vector2f((WINDOW_X * 28.f / 32.f) * 1.f, (WINDOW_Y * 42.f / 45.f) * 1.f), sf::Vector2f(35.f, 35.f), &m_resources.getUrlButtonTexture(2), std::move(m_buttonCommands[10])));
	m_buttons.push_back(Button(sf::Vector2f((WINDOW_X * 2.7f / 32.f) * 1.f, (WINDOW_Y * 42.f / 45.f) * 1.f), sf::Vector2f(35.f, 35.f), &m_resources.getUrlButtonTexture(2), std::move(m_buttonCommands[11])));
}

void Menu::switchMusic()
{
	sf::Music& newMusic = m_musicHandler.getMusicTrack(0);
	m_musicHandler.stopBackgroundMusic();
	m_musicHandler.setCurrMusic(0);
	newMusic.setLoop(true);
	newMusic.setVolume(90);
	if (!m_musicHandler.getMuteAllState()) newMusic.play();
}

void Menu::handleEvent(const sf::Event& event, sf::RenderWindow& window)
{
	for (auto& button : m_buttons) button.execute(event);
	
	markButton(window);
}

void Menu::markButton(sf::RenderWindow& window)
{
	auto x = sf::Mouse::getPosition(window).x;
	auto y = sf::Mouse::getPosition(window).y;

	for (int i = 0; i < NUM_OF_MENU_BUTTONS+ URL_BUTTON_NAME; i++)
	{
		if (m_buttons[i].getGlobalBound().contains(x, y))
			m_buttons[i].setScale(1.1f, 1.1f);
		else
			m_buttons[i].setScale(1.0f, 1.0f);
	}
}
   
void Menu::draw(sf::RenderWindow& window, int r, int g, int b)
{
	window.clear();
	m_background.setFillColor(sf::Color(r, g, b));
	window.setView(getView());
	window.draw(m_background);
	window.draw(m_backgroundText);

	for (auto& button : m_buttons) button.draw(window);
}

void Menu::update(sf::Time)
{
	if (getReplaceMusic())
	{
		switchMusic();
		setReplaceMusic(false);
	}
}
