#pragma once
#pragma region headers
#include "Singletones/MusicManager.h"
#include "ButtonCommand/ButtonCommand.h"
#pragma endregion headers

class Controller;

class MusicCommand : public ButtonCommand
{
public:
	MusicCommand(Controller& controller, sf::Music& backgroundMusic);
	virtual ~MusicCommand() = default;
	virtual void execute();
private:
	Controller& m_controller;
	MusicManager& m_musicHandler = MusicManager::instance();
	sf::Music& m_backgroundMusic;
};