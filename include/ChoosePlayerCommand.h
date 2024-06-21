#pragma once
#include "ButtonCommand.h"

class Controller;
class Menu;

class ChoosePlayerCommand : public ButtonCommand
{
public:
	ChoosePlayerCommand(Menu& menu, Controller& controller, int buttonChoice);
	virtual ~ChoosePlayerCommand() = default;
	virtual void execute();
private:
	Menu& m_menu;
	Controller& m_controller;
	int m_chosenSprite;
};