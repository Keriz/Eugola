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
#include <stdexcept>
#include <string>
#pragma endregion

//runtime_error lancé par l'utilisateur est l'unique type qui n'arrête pas l'application 
enum error {
	domain_error = 1,
	invalid_argument = 2,
	out_of_range = 3,
	logic_error = 4,
	range_error = 5,
	overflow_error = 6,
	underflow_error = 7,
	runtime_error = 8
};

class Engine;

#define PRINT_LOCATION  {  std::string(" In file " + std::string(__FILE__) + " at line " + std::to_string(__LINE__)) }

class Exception{
	Engine* m_Engine;
	std::ofstream m_File;
public:
	Exception::Exception();
	Exception::~Exception();
	void bind_engine(Engine* const);
	void write(int, std::string,  std::string);
	void write(const char*, const char*);
};

#endif