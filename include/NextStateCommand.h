#pragma once
#include "ButtonCommand.h"

class Controller;
class GameState;

class NextStateCommand : public ButtonCommand
{
public:
	NextStateCommand(Controller& controller, GameState& nextState);
	virtual ~NextStateCommand() = default;
	virtual void execute();

private:
	Controller& m_controller;
	GameState& m_nextState;
};