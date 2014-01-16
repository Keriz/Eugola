/*
THIS PROJECT IS UNDER KERIZ' PROPERTY
Eugola - 2013
*/

/*
-GameplayState.h-        
Classe dont tout les etats vont hérités. Implémente quelques fonctions basiques. NOTE DU 25/07/2013 00:05 | Sert à rien pour le moment.
*/

#pragma region Include
#include "State.h"
#pragma endregion

class BaseState : public State {
public:
	BaseState::BaseState();
	virtual BaseState::~BaseState();
	virtual void render(GameTime const& gameTime);
	virtual void update(GameTime const& gameTime);
	virtual void initialize(sf::RenderWindow*,TextureManager*,Exception*){};
	virtual void load_content(){};
	virtual void pause(){};
};