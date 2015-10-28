#include "main.h"

using namespace std;

int main(int argc, char* argv[])
{
	Engine engine;

	try 
	{
		engine.init();
		try
		{
			engine.run();
		}

		catch (exception const& e)
		{
			engine.write_error(typeid(e).name(), e.what());
			MessageBoxA(NULL,
				LPCTSTR(string(string(typeid(e).name()) + string(" exception occured.\n\n\nPlease send your log to the developer at guillaume.thivolet@gmail.com")).c_str()),
				"Eugola catched an exception",
				MB_OK | MB_ICONERROR);
		}
	}
	catch(exception const& e)
	{
		engine.write_error(typeid(e).name(), e.what());
		MessageBoxA(NULL,
			LPCTSTR(string(string(typeid(e).name()) + string(" exception occured. Could not load the game.\n\n\nPlease send your log to the developer at guillaume.thivolet@gmail.com")).c_str()),
			"Eugola catched an exception",
			MB_OK | MB_ICONERROR);
	}
    return engine.getLastExceptionCode(); //0 by default
}