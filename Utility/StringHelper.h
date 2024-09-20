#pragma once
#include <string>
#include <sstream>
#include <vector>
namespace LemonSTU
{
	class StringHelper
	{
	public:
		static std::vector<std::string> Split(const char* str, const char delimiter);
		static void ANSI2Unicode(const char* ansi, wchar_t* unicode,int& len);
		static void Unicode2ANSI(const wchar_t* unicode, char* ansi,int& len);
		static void Unicode2UTF8(const wchar_t* unicode, char* utf8, int& len);
		static void UTF82Unicode(const char* utf8, wchar_t* unicode, int& len);
		static void ANSI2UTF8(const char* ansi,char*utf8, int& len);
		static void UTF82ANSI(const char* utf8, char* ansi, int& len);

		static std::wstring to_wstring(const std::string& input);
		static std::string to_string(const std::wstring& input);
	};
}


