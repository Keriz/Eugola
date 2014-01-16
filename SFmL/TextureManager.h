/*
THIS PROJECT IS UNDER KERIZ' PROPERTY
Eugola - 2013
*/

/*
-TextureManager.h-
Gère et classe toute les différents textures. S'utilise dans les states et est contenu dans le StateManager.
*/

#ifndef TEXTUREMANAGER
#define TEXTUREMANAGER

#pragma region Include
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include "Exception.h"
#include <iostream>
#pragma endregion

class TextureManager{
	std::vector<sf::Texture> m_TextureList;
	std::map<std::string, sf::Texture> m_Textures;
	Exception* m_EHandler;
public:
	TextureManager::TextureManager();
	TextureManager::~TextureManager();
	sf::Texture registerTexture(std::string, std::string);
	void bind(Exception*);
	sf::Texture getTexture(std::string);
};

#endif 