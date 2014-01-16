/*
THIS PROJECT IS UNDER KERIZ' PROPERTY
Eugola - 2013
*/

/*
-State.h-
Classe mère des states
*/
#ifndef STATE
#define STATE

#pragma region Include
#include "GameTime.h"
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#pragma endregion

class State{
protected:
	sf::RenderWindow* m_WindowContext;
	TextureManager* m_TextureManager;
	Exception* m_EHandler;
public:
	State::State();
	virtual State::~State();
	virtual void pause();
	virtual void render(GameTime const& gameTime) = 0;
	virtual void update(GameTime const& gameTime) = 0;
	virtual void initialize(sf::RenderWindow*,TextureManager*,Exception*){};
	virtual void load_content(){};
};

#endif