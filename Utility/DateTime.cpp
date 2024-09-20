#include "DateTime.h"
#include <chrono>

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
    return DateTime();
}

LemonSTU::DateTime::DateTime(const char* datetime):DateTime()
{

}

const char* LemonSTU::DateTime::ToString()
{
    return nullptr;
}

int LemonSTU::DateTime::operator-(DateTime datetime)
{
    return 0;
}
