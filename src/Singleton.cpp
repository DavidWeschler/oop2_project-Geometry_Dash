#include "Singleton.h"
#include <iostream>

Singleton::Singleton()
{
	LoadFromFile();
}

sf::Texture& Singleton::getMenuBackground()
{
	return m_menusTexture;
}

//sf::Texture& Singleton::getGameBackground()
//{
//	return m_gameBackground;
//}
//
//sf::Texture& Singleton::getFileNotFound()
//{
//	return m_fileNotFound;
//}
//
//sf::Texture& Singleton::getWinScreen()
//{
//	return m_winScreen;
//}
//
//sf::Texture& Singleton::getLoseScreen()
//{
//	return m_loseScreen;
//}
//
Singleton& Singleton::instance()
{
	static Singleton Singleton;
	return Singleton;
}

sf::Texture& Singleton::getButtonTextures(int num)
{
	return m_buttonTextures[num];
}

sf::Texture& Singleton::getSetButtonTexture(int num)
{
	return m_setsTextures[num];
}

sf::Texture& Singleton::getBackButtonTexture(int num)
{
	return m_backButtonTextures[num];
}

sf::Texture& Singleton::getMenuButtonTexture(int num)
{
	return m_menuButtonTextures[num];
}

Buttons Singleton::getButtonName(int i) const
{
	return m_names[i];
}

Buttons Singleton::getSetsNames(int i) const
{
	return m_setNames[i];
}

void Singleton::LoadFromFile()
{
	//Load exit & return Buttons
	if (!(m_menusTexture.loadFromFile(m_menunName)))
	{
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < 2; i++)
	{
		m_backButtonTextures.push_back(sf::Texture());
		if (!(m_backButtonTextures[i].loadFromFile(m_backButtNames[i])))
		{
			exit(EXIT_FAILURE);
		}
	}

	//Load Menu buttons
	for (int i = 0; i < 5; i++)
	{
		m_menuButtonTextures.push_back(sf::Texture());
		if (!(m_menuButtonTextures[i].loadFromFile(m_menuButtonsNames[i])))
		{
			std::cerr << "cannot load textures\n";
			exit(EXIT_FAILURE);
		}
	}

	//Load sets
	for (int i = 0; i < NUM_OF_CHOOSE_SETS; i++)
	{
		m_setsTextures.push_back(sf::Texture());
		if (!(m_setsTextures[i].loadFromFile(m_setsNames[i])))
		{
			std::cerr << "cannot load textures\n";
			exit(EXIT_FAILURE);
		}
	}

	//for (int num = START; num <= MENU; num++)
	//{
	//	m_buttonTextures.push_back(sf::Texture());
	//	if (!(m_buttonTextures[num].loadFromFile(m_buttonNames[num])))
	//	{
	//		std::cerr << "cannot load textures\n";
	//		exit(EXIT_FAILURE);
	//	}
	//}

	//if (!m_font.loadFromFile("Font.ttf"))
	//{
	//	std::cerr << "cannot load font\n";
	//	exit(EXIT_FAILURE);
	//}

	//if (!m_menuBackground.loadFromFile(m_nameOfBackgrounds[0]) ||
	//	!m_gameBackground.loadFromFile(m_nameOfBackgrounds[1]) ||
	//	!m_fileNotFound.loadFromFile(m_nameOfExemption) ||
	//	!m_winScreen.loadFromFile(m_endScreens[0]) ||
	//	!m_loseScreen.loadFromFile(m_endScreens[1]))

	//{
	//	std::cerr << "cannot load textures\n";
	//	exit(EXIT_FAILURE);
	//}
}
//
//const sf::Font& Singleton::getFont() const
//{
//	return m_font;
//}