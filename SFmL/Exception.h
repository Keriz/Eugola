/*
THIS PROJECT IS UNDER KERIZ' PROPERTY
Eugola - 2013
*/

/*
-Exception.h-        
Classe servant à la gestion des différentes erreurs du programme.
*/

#ifndef EXCEPTION
#define EXCEPTION

#pragma region Include
#include <fstream>
#pragma endregion

class Engine;

class Exception{
	Engine* m_Engine;
	std::ofstream m_File;
public:
	Exception::Exception();
	Exception::~Exception();
	void bind_engine(Engine* const);
	void write(int, char*);
};

#endif