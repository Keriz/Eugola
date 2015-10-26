#include "Chunk.h"
#include <cstdlib> //to remove
#include <time.h> // to remove

Chunk::Chunk()
{
	m_Tiles = new Tile[NUMBER_TILES_IN_A_CHUNK];
}

Chunk::~Chunk()
{
	delete[] m_Tiles;
}

int* Chunk::load(sf::Vector2i chunkToLoad, Exception* eHandler, TileManager* tileManager)
{
	BinaryStream b;
	b.open(std::string(std::to_string(chunkToLoad.x) + "." + std::to_string(chunkToLoad.y) + ".ec"),"r");
	srand(std::time(0)); //to remove
	for (int i = 0; i < NUMBER_TILES_IN_A_CHUNK; ++i)
	{
		if (rand() > 15550) //pour tester seulement, faut rajouter un peu d'aléatoire
			m_Tiles[i] = tileManager->getTile(0);
		else
			m_Tiles[i] = tileManager->getTile(1);
	}
	
	b.close();

	for (int i = 0; i < NUMBER_TILES_IN_A_CHUNK; ++i)
	{
		m_TilesID[i] = m_Tiles[i].getID();
	}

	return m_TilesID;
}

void Chunk::giveGoodSurroundingTiles(int* tileIDArray,int chunkX, int chunkY)
{

	for (int i = 0; i < NUMBER_TILES_IN_A_CHUNK; i++)
	{
		int tilePosition = (chunkX * 150 * 38) + (chunkY * 50) + (i % 50) + 150*(int(i/50));

		if ( (float(tilePosition / 150.0) < 1.00) || ((tilePosition % 150) == 0) || ((tilePosition % 150) == 149) || (float(tilePosition / 150.0) < 13.00) ) 
		{
			m_Tiles[i].setOrientation(tileIDArray[0], tileIDArray[0], tileIDArray[0], tileIDArray[0]);
			//std::cout << tilePosition << std::endl;
			continue;
		}

		int top, left, bot, right;

		right = tilePosition + 1;
		bot = tilePosition + 150;
		top = tilePosition - 150;
		left = tilePosition - 1;

		m_Tiles[i].setOrientation(tileIDArray[top], tileIDArray[right], tileIDArray[bot], tileIDArray[left]);
	}

	createVertexArrayFromTiles();
}

void Chunk::setTextureToWorkWith(sf::Texture tileset)
{
	m_Tileset = tileset;
}

void Chunk::createVertexArrayFromTiles()
{
	m_Vertices.setPrimitiveType(sf::Quads);
    m_Vertices.resize(NUMBER_TILES_X*NUMBER_TILES_Y*4);

    // on remplit le tableau de vertex, avec un quad par tuile
    for (unsigned int i = 0; i < NUMBER_TILES_X; ++i)
        for (unsigned int j = 0; j < NUMBER_TILES_Y; ++j)
        {

            // on récupère un pointeur vers le quad à définir dans le tableau de vertex
            sf::Vertex* quad = &m_Vertices[(i + j * NUMBER_TILES_X) * 4];

			sf::Vector2f textureOffset = (m_Tiles[i + j * NUMBER_TILES_X]).getTexturesOffset();

			int orientation = m_Tiles[i + j * NUMBER_TILES_X].getOrientation();

            // on définit ses quatre coins
            quad[0].position = sf::Vector2f(i * TILE_SIZE, j * TILE_SIZE);
            quad[1].position = sf::Vector2f((i + 1) * TILE_SIZE, j * TILE_SIZE);
            quad[2].position = sf::Vector2f((i + 1) * TILE_SIZE, (j + 1) * TILE_SIZE);
            quad[3].position = sf::Vector2f(i * TILE_SIZE, (j + 1) * TILE_SIZE);

            // on définit ses quatre coordonnées de texture
			quad[0].texCoords = sf::Vector2f(textureOffset.x + orientation * TILE_SIZE,textureOffset.y);
            quad[1].texCoords = sf::Vector2f(textureOffset.x + orientation * TILE_SIZE + TILE_SIZE,textureOffset.y);
            quad[2].texCoords = sf::Vector2f(textureOffset.x + orientation * TILE_SIZE + TILE_SIZE,textureOffset.y + TILE_SIZE);
			quad[3].texCoords = sf::Vector2f(textureOffset.x + orientation * TILE_SIZE, textureOffset.y + TILE_SIZE);
        }
}