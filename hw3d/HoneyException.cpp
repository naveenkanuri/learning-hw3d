#include "HoneyException.h"
#include <sstream>

HoneyException::HoneyException( int line, const char* file ) noexcept
	:
	 line( line )
	,file( file )
{ }

const char* HoneyException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< GetOriginString();
	
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* HoneyException::GetType() const noexcept
{
	return "Honey Exception";
}

int HoneyException::GetLine() const noexcept
{
	return line;
}

const std::string& HoneyException::GetFile() const noexcept
{
	return file;
}

std::string HoneyException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << std::endl
		<< "[Line] " << line;

	return oss.str();
}
