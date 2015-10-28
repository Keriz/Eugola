/*
THIS PROJECT IS UNDER KERIZ' PROPERTY
Eugola - 2013
*/

/*
-Chunk.h-
Gère un chunk(50*38 tile) permettant d'acceder à des tiles spéciaux, de modifier ceux-ci. gère aussi l'accès aux fichiers.
*/

#ifndef CHUNK
#define CHUNK

#ifndef NUMBER_TILE_X
#define NUMBER_TILES_X 50
#endif

#ifndef NUMBER_TILES_Y
#define NUMBER_TILES_Y 38
#endif

#ifndef NUMBER_TILES_IN_A_CHUNK
#define NUMBER_TILES_IN_A_CHUNK NUMBER_TILES_X*NUMBER_TILES_Y
#endif

#ifndef TILE_SIZE
#define TILE_SIZE 16
#endif


#pragma region Include
#include "BinaryStream.h"
#include "Tile.h"
#include <SFML/Graphics.hpp>
#include "Exception.h"
#include "TileManager.h"
#pragma endregion

class Chunk: public sf::Drawable, public sf::Transformable {
	Tile* m_Tiles; 
	int m_TilesID[NUMBER_TILES_IN_A_CHUNK];
	sf::VertexArray m_Vertices;
	sf::Texture m_Tileset;
	virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const
	{
		states.transform *= getTransform();

        states.texture = &m_Tileset;

        target.draw(m_Vertices, states);	
	};
	void createVertexArrayFromTiles();
public:
	Chunk();
	~Chunk();

	Tile getTile(sf::Vector2f){};
	void setTile(Tile& tile){};

	void giveGoodSurroundingTiles(int*,int,int);

	int* load(sf::Vector2i,Exception*,TileManager*);
	void setTextureToWorkWith(sf::Texture);
};

#endif