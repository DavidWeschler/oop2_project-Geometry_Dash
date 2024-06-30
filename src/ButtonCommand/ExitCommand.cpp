#include "ButtonCommand/ExitCommand.h"

ExitCommand::ExitCommand(sf::RenderWindow& window)
	: m_window(window)
{}

void ExitCommand::execute()
{
	m_window.close();
}