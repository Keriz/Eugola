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
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3;++j)
		{
			int* tileIDArray = m_Chunks[i][j].load(sf::Vector2i(0,0),eHandler,m_TileManager); // premiere etape
			for (int e = 0; e < 1900; e++)
			{
				m_TileID[(i * 1900) + (j * 1900) + (i * j * 1900) + e] = tileIDArray[e];
			}
			//remplissage du tableau globale
			m_Chunks[i][j].giveGoodSurroundingTiles(m_TileID,i,j);//et enfin, mise � jour des orientations
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
	m_Window->draw(m_Chunks[0][0]);
}