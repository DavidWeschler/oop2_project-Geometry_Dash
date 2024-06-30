#pragma once
#pragma region headers
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#pragma endregion headers

class ButtonCommand
{
public:
	virtual ~ButtonCommand() {}
	virtual void execute() = 0;
};