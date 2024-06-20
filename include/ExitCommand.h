#pragma once
#include "ButtonCommand.h"

class ExitCommand : public ButtonCommand
{
public:
	ExitCommand(sf::RenderWindow& window)
		: m_window(window)
	{

	}
	virtual void excecute()
	{
		m_window.close();
	}
	virtual ~ExitCommand() = default;
private:
	sf::RenderWindow& m_window;
};