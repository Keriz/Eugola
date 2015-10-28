#include "TileManager.h"

TileManager::TileManager()
{

}

TileManager::~TileManager()
{

}

void TileManager::load_tiles(TextureManager* textureManager, Exception* eHandler)
{
	pugi::xml_document tilesetDoc;

	if(!tilesetDoc.load_file("data/tileset.xml"))
	{
		eHandler->write(error::invalid_argument, PRINT_LOCATION, "Tileset.xml couldn't be loaded.");
		return;
	}

	pugi::xml_node tileset = tilesetDoc.child("Tileset");

	sf::Image tilesetImage;

	for (pugi::xml_node_iterator it = tileset.begin(); it != tileset.end(); ++it)
	{
		std::string name = it->name();

		if (name == "tiles")
		{
			for (pugi::xml_node tileit = tileset.child("tiles").child("tile"); tileit; tileit = tileit.next_sibling("tile"))
			{
				Tile tileInstance(tileit.attribute("name").as_string(),
								tileit.attribute("id").as_int(),
								tileit.attribute("type").as_int(),
								tileit.attribute("xoffset").as_int(),
								tileit.attribute("yoffset").as_int(),
								tileit.attribute("frames").as_int());
				tileInstance.defineTexture(tilesetImage, eHandler);
				m_Tiles.push_back(tileInstance);
			}
		}

		else if (name == "path")
		{
			tilesetImage = textureManager->registerTexture("tileset", it->attributes_begin()->as_string()).copyToImage();
		}
	}
}

Tile TileManager::getTile(int ID)
{
	return m_Tiles[ID];
}
