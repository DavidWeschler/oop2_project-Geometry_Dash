#pragma once

#pragma region headers

#include "ButtonCommand/ButtonCommand.h"
#include "windows.h"
#include <string>

#pragma endregion headers

class UrlCommand : public ButtonCommand
{
public:
	UrlCommand(const std::string& url);
	virtual ~UrlCommand() = default;
	virtual void execute();
private:
	std::string m_url;
};
