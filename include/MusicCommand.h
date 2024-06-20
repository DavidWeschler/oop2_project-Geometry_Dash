#pragma once
#include "ButtonCommand.h"
#include "MusicManager.h"
#include "Controller.h"

class MusicCommand : public ButtonCommand
{
public:
	MusicCommand(Controller& controller)
		: m_controller(controller)
	{
	};
	virtual ~MusicCommand() = default;
	virtual void excecute()
	{
		m_controller.playMusic() ? m_controller.muteMusic() : m_controller.resumeMusic();
	}
private:
	Controller& m_controller;
};
