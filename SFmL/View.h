#pragma once

#ifndef VIEW
#define VIEW

#pragma region Include
#include "TextureManager.h"
#include "Exception.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#pragma endregion

#endif

class View
{
private:
	sf::Texture m_CursorTexture;
	sf::Sprite m_CursorSprite;

	sf::View m_View; //p-t qu'il va être renommé
	
	sf::RenderWindow* m_WindowContext;
public:
	View();
	~View();

	void register_cursor(sf::RenderWindow*, TextureManager* textureManager, Exception* eHandler);
	void update_cursor(const sf::Vector2<float>);
	void link_window(sf::RenderWindow* window);
	void move(sf::Keyboard::Key, sf::Time);
	void update_position();
	void draw();
};

