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

void Exception::write(int exceptionLevel, std::string loc, std::string exceptionMessage)
{
	switch (exceptionLevel)
	{
	case 1:
		{
			m_Engine->setLastExceptionCode(1);
			m_File << "std::domain_error " << "occured." << loc << ": " << exceptionMessage << std::endl;
			m_Engine->exit_now();
			throw std::domain_error(exceptionMessage);
			break;
		}
	case 2:
		{
			m_Engine->setLastExceptionCode(2);
			m_File << "std::invalid_argument " << "occured." << loc << ": " << exceptionMessage << std::endl;
			m_Engine->exit_now();
			throw std::invalid_argument(exceptionMessage);
			break;
		}
	case 3:
		{
			m_Engine->setLastExceptionCode(3);
			m_File << "std::out_of_range " << "occured." << loc << ": " << exceptionMessage << std::endl;
			m_Engine->exit_now();
			throw std::out_of_range(exceptionMessage);
			break;
		}
	case 4:
		{
			m_Engine->setLastExceptionCode(4);
			m_File << "std::logic_error " << "occured." << loc << ": " << exceptionMessage << std::endl;
			m_Engine->exit_now();
			throw std::logic_error(exceptionMessage);
			break;
		}
	case 5:
		{
			m_Engine->setLastExceptionCode(5);
			m_File << "std::range_error " << "occured." << loc << ": " << exceptionMessage << std::endl;
			m_Engine->exit_now();
			throw std::range_error(exceptionMessage);
			break;
		}
	case 6:
		{
			m_Engine->setLastExceptionCode(6);
			m_File << "std::overflow_error " << "occured." << loc << ": " << exceptionMessage << std::endl;
			m_Engine->exit_now();
			throw std::overflow_error(exceptionMessage);
			break;
		}
	case 7:
		{
			m_Engine->setLastExceptionCode(7);
			m_File << "std::underflow_error " << "occured." << loc << ": " << exceptionMessage << std::endl;
			throw std::underflow_error("underflow_error");
			m_Engine->exit_now();
			break;
		}

	default:
		{
			m_Engine->setLastExceptionCode(8);
			m_File << "std::runtime_error " << "occured." << loc << ": " << exceptionMessage << std::endl;
			break;
		}
	}
}

void Exception::write(const char* type, const char* what)
{
	if (std::string(type) == "class std::domain_error")
	{
		m_Engine->setLastExceptionCode(1);
		m_File << "ENGINE ERROR: std::domain_error " << "exception level occured. Details: " << what << std::endl;
		m_Engine->exit_now();
	}
	else if (std::string(type) == "class std::invalid_argument")
	{
		m_Engine->setLastExceptionCode(2);
		m_File << "ENGINE ERROR: std::invalid_argument " << "exception level occured. Details: " << what << std::endl;
		m_Engine->exit_now();
	}
	else if (std::string(type) == "class std::out_of_range")
	{
		m_Engine->setLastExceptionCode(3);
		m_File << "ENGINE ERROR: std::out_of_range " << "exception level occured. Details: " << what << std::endl;
		m_Engine->exit_now();
	}
	else if (std::string(type) == "class std::logic_error")
	{
		m_Engine->setLastExceptionCode(4);
		m_File << "ENGINE ERROR: std::logic_error " << "exception level occured. Details: " << what << std::endl;
		m_Engine->exit_now();
	}
	else if (std::string(type) == "class std::range_error")
	{
		m_Engine->setLastExceptionCode(5);
		m_File << "ENGINE ERROR: std::range_error " << "exception level occured. Details: " << what << std::endl;
		m_Engine->exit_now();
	}
	else if (std::string(type) == "class std::overflow_error")
	{
		m_Engine->setLastExceptionCode(6);
		m_File << "ENGINE ERROR: std::overflow_error " << "exception level occured. Details: " << what << std::endl;
		m_Engine->exit_now();
	}
	else if (std::string(type) == "class std::underflow_error")
	{
		m_Engine->setLastExceptionCode(7);
		m_File << "ENGINE ERROR: std::underflow_error " << "exception level occured. Details: " << what << std::endl;
		m_Engine->exit_now();
	}

	else
	{
		m_Engine->setLastExceptionCode(8);
		m_File << "ENGINE ERROR: std::runtime_error " << "exception level occured. Details: " << what << std::endl;
		m_Engine->exit_now();
	}
}