#include "Tilemap.h"

Tilemap::Tilemap()
{

}

Tilemap::~Tilemap()
{
	m_Window = 0;
}

void Tilemap::link_window(sf::RenderWindow* window)
{
	m_Window = window;
	m_ChunkManager.link_window(window);
}

void Tilemap::load_tiles(TextureManager* textureManager, Exception* eHandler)
{
	m_TileManager.load_tiles(textureManager, eHandler);
	m_ChunkManager.init(eHandler,&m_TileManager,textureManager->getTexture("tileset"));
}

void Tilemap::draw()
{
	m_ChunkManager.draw();
}