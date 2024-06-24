#pragma once
#include "ButtonCommand/ButtonCommand.h"

class HowToPlayCommand : public ButtonCommand
{
public:
	HowToPlayCommand(int& index, int dir);
	virtual ~HowToPlayCommand() = default;
	virtual void execute();
private:
	int& m_explanationIndex;
	int m_dir;
};