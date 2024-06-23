#pragma once
#include "ButtonCommand/ButtonCommand.h"

class ExitCommand : public ButtonCommand
{
public:
	ExitCommand(sf::RenderWindow& window);
	virtual ~ExitCommand() = default;
	virtual void execute();
private:
	sf::RenderWindow& m_window;
};