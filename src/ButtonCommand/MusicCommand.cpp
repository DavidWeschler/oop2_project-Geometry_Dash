#include "ButtonCommand/MusicCommand.h"
#include "ScreenStates/Controller.h"

MusicCommand::MusicCommand(Controller& controller, sf::Music& backgroundMusic)
	: m_controller(controller), m_backgroundMusic(backgroundMusic)
{
}
void MusicCommand::execute()
{
	m_backgroundMusic.getStatus() != sf::Music::Playing ? m_backgroundMusic.play() : m_backgroundMusic.pause();
	m_musicHandler.setMuteAll(!(m_backgroundMusic.getStatus() == sf::Music::Playing));
}