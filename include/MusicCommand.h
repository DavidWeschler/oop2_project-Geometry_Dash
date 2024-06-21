#pragma once
#include "ButtonCommand.h"
#include "MusicManager.h"

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
