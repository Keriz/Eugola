/*
THIS PROJECT IS UNDER KERIZ' PROPERTY
Eugola - 2013
*/

/*
-Tile.h-
Tile contient tout ce qui permet de definir un tile //TODO
SUJET A DE NOMBREUX CHANGEMENTS
*/

#ifndef TILE
#define TILE

#ifndef TILE_SIZE
#define TILE_SIZE 16
#endif

#pragma region Include
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Exception.h"
#pragma endregion

class Tile{
	std::string m_Name;
	int m_ID;
	int m_Type;
	int m_xTextureOffset; //* TILE_SIZE
	int m_yTextureOffset; //* TILE_SIZE
	int m_Frames;
	int m_Orientation;
	sf::Vector2f m_TexturesOffset;

public:
	Tile(std::string, int, int, int, int, int);
	Tile();

	~Tile();

	void defineTexture(sf::Image, Exception*);
	void setOrientation(int,int,int,int);
	int getID();
	int getOrientation();
	sf::Vector2f getTexturesOffset();

	Tile& operator=(const Tile& t);
};
#endif
