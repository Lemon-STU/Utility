#include "DateTime.h"
#include <chrono>
#include "StringHelper.h"
long long LemonSTU::DateTime::Tick()
{
    LARGE_INTEGER freq_;
    QueryPerformanceFrequency(&freq_);
    LARGE_INTEGER begin_time;
    QueryPerformanceCounter(&begin_time);
    return begin_time.QuadPart*1000 / freq_.QuadPart;
}

LemonSTU::DateTime LemonSTU::DateTime::Now()
{
    time_t now_time = time(nullptr);
    // 将time_t 转换为tm结构
    std::tm time;
    localtime_s(&time, &now_time);
    auto year= time.tm_year + 1900;
    auto month = time.tm_mon+1;
    auto day = time.tm_mday;
    auto hour = time.tm_hour;
    auto minute = time.tm_min;
    auto second = time.tm_sec;
   
    return DateTime(year,month,day,hour,minute,second);
}
/// <summary>
/// 2024-9-20 17:52:10
/// </summary>
/// <param name="datetime"></param>
LemonSTU::DateTime::DateTime(const char* datetime):DateTime()
{
    std::vector<std::string> vec = LemonSTU::StringHelper::Split(datetime, ' ');
    std::vector<std::string> date = LemonSTU::StringHelper::Split(vec.at(0).c_str(), '-');
    std::vector<std::string> time = LemonSTU::StringHelper::Split(vec.at(1).c_str(), ':');
    auto year = std::stoi(date[0]);
    auto month = std::stoi(date[1]);
    auto day = std::stoi(date[2]);
    auto hour = std::stoi(time[0]);
    auto minute = std::stoi(time[1]);
    auto second = std::stoi(time[2]);
    _Year = year;
    _Month = month;
    _Day = day;
    _Hour = hour;
    _Minutes = minute;
    _Seconds = second;
}

std::string LemonSTU::DateTime::ToString()
{
    std::stringstream ss;
    ss << _Year << "-" << _Month << "-" << _Day << " " << _Hour << ":" << _Minutes << ":" << _Seconds;
    return ss.str();
}

double LemonSTU::DateTime::operator-(const DateTime& datetime)
{
    std::tm tm1 = *this;
    std::tm tm2 = datetime;
    time_t time1 = mktime(&tm1);
    time_t time2 = mktime(&tm2);
    double seconds= difftime(time1, time2);
    return seconds/60/60;
}

LemonSTU::DateTime::operator tm() const
{
    std::tm tm1;
    tm1.tm_year = _Year - 1900;
    tm1.tm_mon = _Month - 1;
    tm1.tm_mday = _Day;
    tm1.tm_hour = _Hour;
    tm1.tm_min = _Minutes;
    tm1.tm_sec = _Seconds;
    return tm1;
}
