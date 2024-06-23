#pragma once	

#include "SFML/Graphics.hpp"
#include "Button.h"
#include "Singleton.h"
#include "GameState.h"
#include "ChoosePlayerCommand.h"

class Controller;
class Menu;

class ChoosePlayer : public GameState
{
public:
	ChoosePlayer(Controller& controller);

	//virtual GameState* handleEvent(const sf::Event&, sf::RenderWindow&, sf::Time time);
	virtual void handleEvent(const sf::Event&, sf::RenderWindow&, sf::Time time);
	virtual void update(sf::Time) {};
	virtual void draw(sf::RenderWindow& windowint, int r, int g, int b);
	virtual void setSwitchMusic() {};

	void setStates(Menu* menu);
	void setExitButton(Controller& controller);
	//void markChoice(sf::RenderWindow& window);
private:
	void setButtons(Controller& controller);
	//void handleChoice(const sf::Event::MouseButtonEvent&, sf::RenderWindow&);

	Singleton& m_resources = Singleton::instance();

	Menu* m_menuState;

	sf::RenderWindow* m_window;
	sf::RectangleShape m_background;
	sf::RectangleShape m_backgroundText;

	std::unique_ptr<Button> m_exitButton;
	std::vector<Button> m_setsButtons;
};