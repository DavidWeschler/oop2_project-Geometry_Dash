#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory> /////////

class ButtonCommand
{
public:
	virtual ~ButtonCommand() {}
	virtual void execute() = 0;
};