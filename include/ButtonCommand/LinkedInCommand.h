#pragma once
#include "ButtonCommand/ButtonCommand.h"
#include "windows.h"
#include <string>

class LinkedInCommand : public ButtonCommand
{
public:
	LinkedInCommand(const std::string& url) : m_url(url) {}
	virtual ~LinkedInCommand() = default;
	virtual void execute();
private:
	std::string m_url;
};
