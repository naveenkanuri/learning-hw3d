#pragma once

#include <unordered_map>
#include <Windows.h>

class WindowsMessageMap
{
public:
	WindowsMessageMap( );
	std::wstring operator()( DWORD msg, WPARAM wp, LPARAM lp ) const noexcept;
private:
	std::unordered_map<DWORD, std::string> map;
};