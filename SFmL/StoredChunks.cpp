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
	for (int k = 1; k < 3; k++)
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				int* tileIDArray = m_Chunks[i][j].load(sf::Vector2i(0, 0), eHandler, m_TileManager); // premiere etape -> HERE IS THE PROBLEM 

				for (int e = 0; e < 1900; e++)
				{
					m_TileID[(1900 * j * i * k) + e] = tileIDArray[e];
					std::cout << tileIDArray[e] << std::endl;

					if (((1900 * j * i * k) + e) > 17100)
						std::cout << (1900 * j * i * k) + e << std::endl;
				}
				m_Chunks[i][j].giveGoodSurroundingTiles(m_TileID, i, j);//et enfin, mise à jour des orientations
				m_Chunks[i][j].setTextureToWorkWith(tileset);
			
			}
		}
	}
}

void StoredChunk::draw()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3;++j)
		{
				m_Window->draw(m_Chunks[i][j]); //a remettre
		}
	}
	//m_Window->draw(m_Chunks[0][0]);
}