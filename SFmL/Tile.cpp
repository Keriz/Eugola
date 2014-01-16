#include "Tile.h"

Tile::Tile(std::string name, int ID, int type, int xTextureOffset, int yTextureOffset, int frames)
	:m_Name(name), m_ID(ID), m_Type(type), m_xTextureOffset(xTextureOffset), m_yTextureOffset(yTextureOffset)
{
	m_Frames = (m_Type) ? frames : 9;
	m_Orientation = 0;
	std::cout << "Tile :" + m_Name + " with ID " + std::to_string(m_ID) + " has been registered in the tile database." << std::endl;
}

Tile::Tile()
{
	//POSSIBLE FUTURE BUG, CHECK IT OUT FURTHER
}

Tile::~Tile()
{
	//POSSIBLE FUTURE BUG, CHECK IT OUT FURTHER
}

Tile& Tile::operator=(const Tile& t)
{
	m_Name = t.m_Name;
	m_ID = t.m_ID;
	m_Type = t.m_Type;
	m_xTextureOffset = t.m_xTextureOffset;
	m_yTextureOffset = t.m_yTextureOffset; 
	m_Frames = t.m_Frames;
	m_TexturesOffset = t.m_TexturesOffset;
	m_Orientation = t.m_Orientation;
	return *this;
}

void Tile::defineTexture(sf::Image image, Exception* eHandler)
{
	//sf::Texture texture;
	//texture.create(16,16);
	//for (int i = 0; i < m_Frames; i++)
	//{
	//	if(!texture.loadFromImage(image, sf::IntRect(m_xTextureOffset * TILE_SIZE + i * TILE_SIZE, m_yTextureOffset * TILE_SIZE,TILE_SIZE,TILE_SIZE)))
	//	{
	//		eHandler->write(2, const_cast<char*>(std::string("tileset.xml file, tile " + m_Name + ", couldn't create texture for frame " + std::to_string(i) + ".").c_str()));
	//		return;
	//	}
	//}
	m_TexturesOffset.x = m_xTextureOffset * TILE_SIZE;
	m_TexturesOffset.y = m_yTextureOffset * TILE_SIZE;
	m_Orientation = 0;
}

void Tile::setOrientation(int top, int right, int bot, int left)
{
	if (top == m_ID && right == m_ID && bot == m_ID && left == m_ID)
	{
		m_Orientation = 0;
		return;
	}

	else if(top == m_ID && right != m_ID && bot != m_ID && left == m_ID)
	{
		m_Orientation = 1;
		return;
	}

	else if(top != m_ID && right != m_ID && bot == m_ID && left == m_ID)
	{
		m_Orientation = 2;
		return;
	}

	else if(top == m_ID && right == m_ID && bot != m_ID && left != m_ID)
	{
		m_Orientation = 3;
		return;
	}

	else if(top != m_ID && right != m_ID && bot == m_ID && left == m_ID)
	{
		m_Orientation = 4;
		return;
	}

	else if(top != m_ID && right != m_ID && bot != m_ID && left == m_ID)
	{
		m_Orientation = 5;
		return;
	}

	else if(top != m_ID && right != m_ID && bot == m_ID && left != m_ID)
	{
		m_Orientation = 6;
		return;
	}

	else if(top != m_ID && right == m_ID && bot != m_ID && left != m_ID)
	{
		m_Orientation = 7;
		return;
	}

	else if(top == m_ID && right != m_ID && bot != m_ID && left != m_ID)
	{
		m_Orientation = 8;
		return;
	}
}

int Tile::getID()
{
	return m_ID;
}

int Tile::getOrientation()
{
	return m_Orientation;
}

sf::Vector2f Tile::getTexturesOffset()
{
//	return m_TexturesOffset;
	return sf::Vector2f(0,0);
}