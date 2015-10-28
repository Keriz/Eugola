#include "TextureManager.h"

TextureManager::TextureManager()
{
	sf::Image image;
	image.loadFromFile("img/NULL.png");
	sf::Texture texture;
	texture.loadFromImage(image);
	m_TextureList.push_back(texture);
	m_Textures.insert(std::make_pair("NULL", m_TextureList.at(m_TextureList.size()-1)));
}

TextureManager::~TextureManager()
{
	/*for (size_t i = 0; i <= m_TextureList.size(); ++i)
	{
		delete m_TextureList[i];
	}*/
	m_EHandler = 0;
}

void TextureManager::bind(Exception* eHandler)
{
	m_EHandler = eHandler;
}

sf::Texture TextureManager::registerTexture(std::string textureName, std::string texturePath)
{
	sf::Image image;

	if(!image.loadFromFile(texturePath))
	{
		if (textureName == "tileset")
		{
			m_EHandler->write(error::invalid_argument, PRINT_LOCATION, std::string("Tileset failed to load at p. We must exit (WRONGPATH_CODE)."));
		}

		m_EHandler->write(error::runtime_error, PRINT_LOCATION, std::string("Could not load " + texturePath + "."));
		return getTexture("NULL");
	}
	sf::Texture texture;
	texture.loadFromImage(image);

	m_TextureList.push_back(texture);
	
	m_Textures.insert(std::make_pair(textureName, m_TextureList.at(m_TextureList.size()-1)));
	return getTexture(textureName);
}

sf::Texture TextureManager::getTexture(std::string textureName)
{
	return m_Textures[textureName];
}