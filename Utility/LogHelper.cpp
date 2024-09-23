#include "LogHelper.h"
#include <fstream>

namespace LemonSTU {
    inline std::string BuildLog(std::string msg)
    {
        time_t now_time = time(nullptr);
        // 将time_t 转换为tm结构
        std::tm time;
        localtime_s(&time,&now_time);
        std::stringstream ss;
        ss << "[";
        char systime[40];
        strftime(systime, 40, "%Y-%m-%d %H:%M:%S", &time);
        ss << systime;
        ss << "]:" << msg << std::endl;
        return ss.str();
    }

    void Logger::log(std::string msg)
    {
        std::ofstream f("log.log", std::ios::app);
        f << BuildLog(msg);
        f.flush();
        f.close();
    }  
}

