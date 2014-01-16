#include "main.h"

using namespace std;

int main(int argc, char* argv[])
{
	Engine engine;

	try	{
		engine.run();
	}
	catch (...)
	{
		MessageBoxA(NULL, "Unknow exception occured, please send your log to the developer at guillaume.thivolet@gmail.com", "Eugola catched a fatal exception", MB_OK | MB_ICONERROR);
	}
	if (engine.getLastExceptionCode() > 1 )
		return MessageBoxA(NULL, 
						LPCTSTR(string("Exception code: " +  to_string(engine.getLastExceptionCode()) + "\n" + engine.getExitMessage() +"\nPlease, send your log to the developer at guillaume.thivolet@gmail.com").c_str()),
						LPCTSTR(("Eugola: " + to_string(engine.getLastExceptionCode())).c_str()), 
						MB_OK | MB_ICONERROR);
	//"//LPCTSTR(string("Exception code: " +  to_string(engine.getLastExceptionCode()) + "\n" + engine.getExitMessage() + "\nPlease, send your log to the developer at guillaume.thivolet@gmail.com").c_str()), "Eugola error " + engine.getLastExceptionCode(), MB_OK | MB_ICONERROR);
    return engine.getLastExceptionCode(); //0 by default
}