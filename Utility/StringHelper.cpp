#include "StringHelper.h"
#include <Windows.h>
std::vector<std::string> LemonSTU::StringHelper::Split(const char* str, const char delimiter)
{
    std::vector<std::string> vec;
    std::stringstream strstream(str);
    std::string strbuff;
    while (std::getline(strstream, strbuff, delimiter))
    {
        vec.push_back(strbuff);
    }
    return vec;
}

void LemonSTU::StringHelper::ANSI2Unicode(const char* ansi, wchar_t* unicode, int& len)
{
    int wlen = ::MultiByteToWideChar(CP_ACP, 0, ansi, -1, nullptr, 0);
    len = wlen;
    if (unicode == nullptr)       
        return;
    ::MultiByteToWideChar(CP_ACP, 0, ansi, -1, unicode, wlen);
}

void LemonSTU::StringHelper::Unicode2ANSI(const wchar_t* unicode, char* ansi, int& len)
{
    int alen = ::WideCharToMultiByte(CP_ACP, 0, unicode, -1, nullptr, 0, nullptr, nullptr);
    len = alen;
    if (ansi == nullptr)
        return;
    ::WideCharToMultiByte(CP_ACP, 0, unicode, -1, ansi,alen, nullptr, nullptr);
}

void LemonSTU::StringHelper::Unicode2UTF8(const wchar_t* unicode, char* utf8, int& len)
{
    int u8len = ::WideCharToMultiByte(CP_UTF8, 0, unicode, -1, nullptr, 0, nullptr, nullptr);
    len = u8len;
    if (utf8 == nullptr)
        return;
    ::WideCharToMultiByte(CP_UTF8, 0, unicode, -1, utf8, u8len, nullptr, nullptr);
}

void LemonSTU::StringHelper::UTF82Unicode(const char* utf8, wchar_t* unicode, int& len)
{
    int wlen = ::MultiByteToWideChar(CP_UTF8, 0, utf8, -1, nullptr, 0);
    len = wlen;
    if (unicode == nullptr)
        return;
    ::MultiByteToWideChar(CP_UTF8, 0,utf8, -1, unicode, wlen);
}

void LemonSTU::StringHelper::ANSI2UTF8(const char* ansi, char* utf8, int& len)
{
    int wlen = 0;
    ANSI2Unicode(ansi, nullptr, wlen);
    wchar_t* unicode=new wchar_t[wlen];
    ANSI2Unicode(ansi, unicode, wlen);
    int u8len = 0;
    Unicode2UTF8(unicode, nullptr, u8len);
    if (utf8 == nullptr)
        return;
    Unicode2UTF8(unicode, utf8, u8len);
}

void LemonSTU::StringHelper::UTF82ANSI(const char* utf8, char* ansi, int& len)
{
    int wlen = 0;
    UTF82Unicode(ansi, nullptr, wlen);
    wchar_t* unicode = new wchar_t[wlen];
    ANSI2Unicode(ansi, unicode, wlen);
    int u8len = 0;
    Unicode2ANSI(unicode, nullptr, u8len);
    if (utf8 == nullptr)
        return;
    Unicode2ANSI(unicode, ansi, u8len);
}
