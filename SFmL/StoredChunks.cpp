#include "StoredChunks.h"

StoredChunk::StoredChunk()
{
	m_Chunks = new Chunk*[3];
	for (int i = 0; i < 3; i++)
      m_Chunks[i] = new Chunk[3];
	m_TileID = new int[1900*3*3];
}

StoredChunk::~StoredChunk()
{
	for (int i = 0; i < 3;++i)
	{
		delete[] m_Chunks[i];
	}
	delete[] m_Chunks;
	delete[] m_TileID;
	m_TileManager = 0;
	m_Window = 0;
}

void StoredChunk::link_window(sf::RenderWindow* window)
{
	m_Window = window;
}

void StoredChunk::init(Exception* eHandler, TileManager* tileManager, sf::Texture tileset)
{
	m_TileManager = tileManager;
	for (int i = 0; i < 3; ++i) // i vertical
	{
		for (int j = 0; j < 3; ++j) //j horizontal
		{
			int* tileIDArray = m_Chunks[i][j].load(sf::Vector2i(0, 0), eHandler, m_TileManager); // on remplie le tableau des tile du chunk (ici aléatoire donc)

			for (int tileY = 0; tileY < NUMBER_TILES_Y; ++tileY)
			{
				for (int tileX = 0; tileX < NUMBER_TILES_X; ++tileX)
				{
					m_TileID[(i * 150 * 38) + (j * 50) + tileY * 150 + tileX] = tileIDArray[tileX + tileY * 50]; // *3 not sure
					//std::cout << ((i * 150 * 38) + (j * 50) + tileY * 150 + tileX) << std::endl;
				}
			}
		}
	}

	//loop on all the tiles to give them the good surrounding tiles and to build their texture
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; j++)
		{
			m_Chunks[i][j].giveGoodSurroundingTiles(m_TileID, i, j);//et enfin, mise à jour des orientations
			m_Chunks[i][j].setTextureToWorkWith(tileset);
		}
	}
}

void StoredChunk::draw()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3;++j)
		{
				//m_Window->draw(m_Chunks[i][j]); //a remettre
		}
	}
	m_Window->draw(m_Chunks[1][1]);
}