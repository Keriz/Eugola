/*
THIS PROJECT IS UNDER KERIZ' PROPERTY
Eugola - 2013
*/

/*
-StoredChunk.h-
Gère toutes les tranches au niveau du chargements, de leur modifs, pour récuperer un tile...
*/

#ifndef STOREDCHUNK
#define STOREDCHUNK

#pragma region Include
#include "Chunk.h"
#pragma endregion

class StoredChunk{
	TileManager* m_TileManager;
	Chunk** m_Chunks;
	int* m_TileID;
	sf::RenderWindow* m_Window; //:(
public:
	StoredChunk();
	~StoredChunk();
	void link_window(sf::RenderWindow*);
	void init(Exception*,TileManager*,sf::Texture);
	void draw();
};

#endif