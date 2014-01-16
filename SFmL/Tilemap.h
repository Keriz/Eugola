/*
THIS PROJECT IS UNDER KERIZ' PROPERTY
Eugola - 2013
*/

/*
-Tilemap.h-
Gère les chunks, l'affichage des tiles, et //TODO
*/

#ifndef TILEMAP
#define TILEMAP

#ifndef TILE_SIZE
#define TILE_SIZE 16
#endif

#pragma region Include
#include "TextureManager.h"
#include "TileManager.h"
#include "StoredChunks.h"
#pragma endregion


class Tilemap{
	TileManager m_TileManager;
	StoredChunk m_ChunkManager;
	sf::RenderWindow* m_Window;
public:
	Tilemap();
	~Tilemap();
	void link_window(sf::RenderWindow*);
	void load_tiles(TextureManager*,Exception*);
	void draw();
};
#endif