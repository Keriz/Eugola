/*
THIS PROJECT IS UNDER KERIZ' PROPERTY
Eugola - 2013
*/

/*
-Tile.h-
Gère tout les tiles et leur infos relativess.
*/

#ifndef TILEMANAGER
#define TILEMANAGER

#ifndef TILE_SIZE
#define TILE_SIZE 16
#endif

#pragma region Include
#include <vector>
#include "TextureManager.h"
#include "pugixml.h"
#include <iostream>
#include "Tile.h"
#pragma endregion


class TileManager{
	std::vector<Tile> m_Tiles;
public:
	TileManager();
	~TileManager();
	void load_tiles(TextureManager*,Exception*);
	Tile getTile(int ID);
};

#endif