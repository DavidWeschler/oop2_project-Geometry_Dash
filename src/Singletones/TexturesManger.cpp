#include "Singletones/TexturesManger.h"
#include <iostream>

TexturesManger::TexturesManger()
{
	LoadFromFile();
}

sf::Texture& TexturesManger::getMenuBackground(int i)
{
	return m_menusTextures[i];
}

sf::Texture& TexturesManger::getPlayerTexture(int num)
{
	return m_playerTextures[num];
}

sf::Texture& TexturesManger::getObjTexture(int num)
{
	return m_objTextures[num];
}

 sf::Image TexturesManger::getImage(int i) const
 {
	 return m_images[i];
 }

 sf::Texture& TexturesManger::getCursor()
 {
	 return m_cursor;
 }

 sf::Texture& TexturesManger::getUrlButtonTexture(int i)
 {
	 return m_urlTexture[i];
 }

 sf::Texture& TexturesManger::getHowToPlayTexture(int num)
 {
	 if (num == -1)
	 {
		 return m_howToPlayBackground;
	 }
	 return m_howToPlay[num];
 }

 sf::Texture& TexturesManger::getBulletTexture(int num)
 {
	 return m_bulletsTex[num];
 }

 sf::Texture& TexturesManger::getWellDoneTexture()
 {
	 return m_wellDone;
 }

 sf::Texture& TexturesManger::getStatsTexture()
 {
	 return m_statsBackground;
 }

 const sf::Font& TexturesManger::getFont() const
 {
	 return m_font;
 }

TexturesManger& TexturesManger::instance()
{
	static TexturesManger TexturesManger;
	return TexturesManger;
}

sf::Texture& TexturesManger::getButtonTextures(int num)
{
	return m_buttonTextures[num];
}

sf::Texture& TexturesManger::getSetButtonTexture(int num)
{
	return m_setsTextures[num];
}

sf::Texture& TexturesManger::getBackButtonTexture(int num)
{
	return m_backButtonTextures[num];
}

sf::Texture& TexturesManger::getMenuButtonTexture(int num)
{
	return m_menuButtonTextures[num];
}

Buttons TexturesManger::getButtonName(int i) const
{
	return m_names[i];
}

Buttons TexturesManger::getSetsNames(int i) const
{
	return m_setNames[i];
}

void TexturesManger::LoadFromFile()
{
	//Load exit & return Buttons
	for (int i = 0; i < 3; i++)
	{
		m_menusTextures.push_back(sf::Texture());
		if (!(m_menusTextures[i].loadFromFile(m_menunTools[i])))
		{
			exit(EXIT_FAILURE);
		}
	}

	for (int i = 0; i < 3; i++)
	{
		m_backButtonTextures.push_back(sf::Texture());
		if (!(m_backButtonTextures[i].loadFromFile(m_backButtNames[i])))
		{
			exit(EXIT_FAILURE);
		}
	}

	//Load Menu buttons
	for (int i = 0; i < NUM_OF_MENU_BUTTONS; i++)
	{
		m_menuButtonTextures.push_back(sf::Texture());
		if (!(m_menuButtonTextures[i].loadFromFile(m_menuButtonsNames[i])))
		{
			std::cerr << "cannot load textures\n";
			exit(EXIT_FAILURE);
		}
	}

	//Load Player Faces and ships
	for (int i = 0; i < NUM_OF_PLAYERS; i++)
	{
		m_playerTextures.push_back(sf::Texture());
		if (!(m_playerTextures[i].loadFromFile(m_playerNames[i])))
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


	//load images
	for (int i = 0; i < NUM_OF_LEVELS; i++)
	{
		m_images.push_back(sf::Image());
		if (!(m_images[i].loadFromFile(m_levelNames[i])))
		{
			exit(EXIT_FAILURE);
		}
	}

	if (!(m_cursor.loadFromFile("cursor.png")))
	{
		exit(EXIT_FAILURE);
	}


	//Load objects
	for (int i = 0; i < NUM_OF_OBJ; i++)
	{
		m_objTextures.push_back(sf::Texture());
		if (!(m_objTextures[i].loadFromFile(m_objNames[i])))
		{
			exit(EXIT_FAILURE);
		}
	}

	//Load How To Play
	for (int i = 0; i < NUM_OF_HOW_TO_PLAY; i++)
	{
		m_howToPlay.push_back(sf::Texture());
		if (!(m_howToPlay[i].loadFromFile(m_slides[i])))
		{
			exit(EXIT_FAILURE);
		}
	}
	if (!m_howToPlayBackground.loadFromFile("HowToPlayBackground.png"))
	{
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < URL_BUTTON_NAME; i++)
	{
		m_urlTexture.push_back(sf::Texture());
		if (!(m_urlTexture[i].loadFromFile(m_urlNames[i])))
		{
			exit(EXIT_FAILURE);
		}
	}

	//load bullets:
	for (int i = 0; i < NUM_OF_BULLETS; i++)
	{
		m_bulletsTex.push_back(sf::Texture());
		if (!(m_bulletsTex[i].loadFromFile(m_bulletNames[i])))
		{
			exit(EXIT_FAILURE);
		}
	}

	//well done
	if (!m_wellDone.loadFromFile("WellDone.png"))
	{
		exit(EXIT_FAILURE);
	}

	//load font
	if (!m_font.loadFromFile("font.ttf"))
	{
		exit(EXIT_FAILURE);
	}

	if (!m_statsBackground.loadFromFile("statsBackground.png"))
	{
		exit(EXIT_FAILURE);
	}

	m_data.push_back(robotData());
}

AnimationData TexturesManger::robotData()
{
	const auto size = sf::Vector2i(3601/11, 330);
	const auto initSpace = sf::Vector2i(0, 0);
	const auto middleSpace = sf::Vector2i(0, 0);

	AnimationData robot;
	auto currentStart = initSpace;

	auto nextStart = [&]()
		{
			//currentStart += middleSpace;
			currentStart.x += size.x;
			return currentStart;
		};

	robot.m_data[Direction::Right].emplace_back(currentStart, size);
	robot.m_data[Direction::Right].emplace_back(nextStart(), size);
	robot.m_data[Direction::Left].emplace_back(nextStart(), size);
	robot.m_data[Direction::Left].emplace_back(nextStart(), size);

	return robot;
}