#pragma once
#include "ButtonCommand.h"
#include "GameState.h"
#include "Controller.h"

class NextStateCommand : public ButtonCommand
{
public:
	NextStateCommand(Controller& controller, GameState& nextState)
		: m_controller(controller), m_nextState(nextState)
	{
	}
	virtual ~NextStateCommand() = default;
	virtual void excecute()
	{
		m_controller.switchState(&m_nextState);
	}

private:
	Controller& m_controller;
	GameState& m_nextState;
};