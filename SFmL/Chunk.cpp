#include "Chunk.h"

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
	for (int i = 0; i < NUMBER_TILES_IN_A_CHUNK; ++i)
	{
		m_Tiles[i] = tileManager->getTile(0);
	}
	
	b.close();
	createVertexArrayFromTiles();

	int arrayToFill[NUMBER_TILES_IN_A_CHUNK] = {};

	for (int i = 0; i < NUMBER_TILES_IN_A_CHUNK; ++i)
	{
		arrayToFill[i] = m_Tiles[i].getID();
	}

	return arrayToFill;
}

void Chunk::giveGoodSurroundingTiles(int* tileIDArray,int chunkX, int chunkY)
{
	//(i * 1900) + (j * 1900) + (i * j * 1900)
	for (int i = 0; i < NUMBER_TILES_IN_A_CHUNK; i++)
	{
		int top, left, bot, right;

		if ((i - 50) < 0)
		{
			top = i;
			bot = i + 50;
			right = i + 1;
			left = i;
		}

		else if ((i + 50) >= 1900)
		{
			right = i;
			bot = i;
			top = i - 50;
			left = i - 1;
		}

		else
		{
			top = i - 50;
			bot = i + 50;
			right = i + 1;
			left = i - 1;
		}

		//if

		//top = -50
		//bot = +50
		m_Tiles[i].setOrientation(m_Tiles[top].getID(),m_Tiles[right].getID(),m_Tiles[bot].getID(),m_Tiles[left].getID());
	}
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

			sf::Vector2f textureOffset = m_Tiles[i * NUMBER_TILES_X + j * NUMBER_TILES_Y].getTexturesOffset();

			int orientation = m_Tiles[i + j * NUMBER_TILES_X].getOrientation();

			std::cout << (i + j * NUMBER_TILES_X) << std::endl;

            // on définit ses quatre coins
            quad[0].position = sf::Vector2f(i * TILE_SIZE, j * TILE_SIZE);
            quad[1].position = sf::Vector2f((i + 1) * TILE_SIZE, j * TILE_SIZE);
            quad[2].position = sf::Vector2f((i + 1) * TILE_SIZE, (j + 1) * TILE_SIZE);
            quad[3].position = sf::Vector2f(i * TILE_SIZE, (j + 1) * TILE_SIZE);

            // on définit ses quatre coordonnées de texture
			quad[0].texCoords = sf::Vector2f(textureOffset.x + orientation * TILE_SIZE,textureOffset.y);
            quad[1].texCoords = sf::Vector2f(textureOffset.x + orientation * TILE_SIZE + TILE_SIZE,textureOffset.y);
            quad[2].texCoords = sf::Vector2f(textureOffset.x + orientation * TILE_SIZE + TILE_SIZE,textureOffset.y + TILE_SIZE);
            quad[3].texCoords = sf::Vector2f(textureOffset.x + orientation * TILE_SIZE,textureOffset.y + TILE_SIZE);
        }
}