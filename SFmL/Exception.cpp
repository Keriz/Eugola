#include "Exception.h"
#include "Engine.h"

Exception::Exception()
{
	m_File.open("log.txt", std::ios::out | std::ios::app);
}

Exception::~Exception()
{
	m_File.close();
	m_Engine = 0;
}

void Exception::bind_engine(Engine* const engine)
{
	m_Engine = engine;
}

void Exception::write(int exceptionLevel, char* exceptionMessage)
{
	switch (exceptionLevel)
	{
	case 1:
		{
			m_Engine->setLastExceptionCode(1);
			m_File << exceptionLevel << " exception level occured. Message: " << exceptionMessage << std::endl;
			break;
		}

	default:
		{
			m_Engine->setLastExceptionCode(2);
			m_File << exceptionLevel << " exception level occured. Message: " << exceptionMessage << std::endl;
			m_Engine->exit_now(exceptionLevel,exceptionMessage);
			break;
		}
	}
}