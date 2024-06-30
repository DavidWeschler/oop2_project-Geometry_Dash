#pragma once	
#pragma region headers
#include "SFML/Graphics.hpp"
#include "ButtonCommand/Button.h"
#include "Singletones/TexturesManger.h"
#include "ScreenStates/GameState.h"
#include "ButtonCommand/ChoosePlayerCommand.h"
#pragma endregion headers

class Controller;
class Menu;

class ChoosePlayer : public GameState
{
public:
	ChoosePlayer(Controller& controller);

	virtual void handleEvent(const sf::Event& event, sf::RenderWindow& window);
	virtual void update(sf::Time) {};
	virtual void draw(sf::RenderWindow& windowint, int r, int g, int b);
	virtual void switchMusic() {};

	void setStates(Menu* menu);
	void setExitButton(Controller& controller);
private:
	void setButtons(Controller& controller);

	TexturesManger& m_resources = TexturesManger::instance();

	Menu* m_menuState;

	sf::RenderWindow* m_window;
	sf::RectangleShape m_background;
	sf::RectangleShape m_backgroundText;

	std::unique_ptr<Button> m_exitButton;
	std::vector<Button> m_setsButtons;
};