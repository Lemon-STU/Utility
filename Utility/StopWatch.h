#pragma once
#include<functional>
#include <Windows.h>

namespace LemonSTU
{
    class StopWatch
    {
        LARGE_INTEGER freq_;
        LARGE_INTEGER begin_time_;
        long long elapsed_;
        std::function<void(long long)> _func = nullptr;
    public:
        StopWatch() :elapsed_(0) {
            QueryPerformanceFrequency(&freq_);
        }

        StopWatch(std::function<void(long long)> func) :StopWatch()
        {
            _func = func;
            Start();
        }
        ~StopWatch()
        {
            Stop();
            if (_func)
                _func(elapsed_ / 1000.0);
        }
        void Start()
        {
            QueryPerformanceCounter(&begin_time_);
        }
        void Stop()
        {
            LARGE_INTEGER end_time;
            QueryPerformanceCounter(&end_time);
            elapsed_ += (end_time.QuadPart - begin_time_.QuadPart) * 1000000 / freq_.QuadPart;
        }
        void Restart()
        {
            elapsed_ = 0;
            Start();
        }
        //Œ¢√Î
        double Elapsed()
        {
            return static_cast<double>(elapsed_);
        }
        //∫¡√Î
        double Elapsed_ms()
        {
            return elapsed_ / 1000.0;
        }
        //√Î
        double Elapsed_second()
        {
            return elapsed_ / 1000000.0;
        }
    };
}

