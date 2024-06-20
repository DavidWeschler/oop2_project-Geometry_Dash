#pragma once
#include "ButtonCommand.h"
#include "Menu.h"

class ChoosePlayerCommand : public ButtonCommand
{
public:
	ChoosePlayerCommand(Menu& menu, int buttonChoice)
		: m_menu(menu), m_chosenSprite(buttonChoice)
	{
	}
	virtual ~ChoosePlayerCommand() = default;
	virtual void excecute()
	{
		m_menu.setChosenPlayer(m_chosenSprite);
	}
private:
	Menu& m_menu;
	int m_chosenSprite;
};