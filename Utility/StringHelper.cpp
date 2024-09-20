#include "StringHelper.h"

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
