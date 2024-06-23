#pragma once
#include "ButtonCommand.h"

class Controller;
class GameState;

class NextStateCommand : public ButtonCommand
{
public:
	NextStateCommand(Controller& controller, GameState& nextState);	//this needs to go
	virtual ~NextStateCommand() = default;
	virtual void execute();

private:
	Controller& m_controller;
	GameState& m_nextState;
	GameStates m_nextStateType;
};