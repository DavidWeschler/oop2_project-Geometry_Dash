#pragma once

#include "ButtonCommand.h"

class Button
{
public:
	//Button(sf::Vector2f, sf::Vector2f, enum Buttons, sf::Texture*);	//needs to go
	Button(sf::Vector2f, sf::Vector2f, enum Buttons, sf::Texture*, std::unique_ptr<ButtonCommand> myCommand);

	void setScale(float, float);
	void setOutlineThickness(float margin);
	void setOutlineColor(sf::Color color);
	sf::FloatRect getGlobalBound() const;
	enum Buttons getType() const;
	void draw(sf::RenderWindow&) const;
	void execute(const sf::Event& event);

private:
	sf::RectangleShape m_shape;
	enum Buttons m_type;

	std::unique_ptr<ButtonCommand> m_command;
};