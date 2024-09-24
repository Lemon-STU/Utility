// UtilityDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DateTime.h"
#include <thread>
#include <chrono>
#include "StringHelper.h"

const char* test()
{
    const char tmp[] = "hello,world";//0x00007FF600C9AE88
    char newtmp[15]{ 0 };
    memcpy(newtmp, tmp, sizeof(tmp));//0x000000E8229CF5D8
    const char* ptmp = "hello,world";
    return ptmp;
}

int* itest()
{
    int j=100;//0x000000B9BCEFF3D4
    return &j;//0x000000B9BCEFF3D4         
}
int main()
{
    LemonSTU::DateTime time1("2024-09-24   9:45:0");
    LemonSTU::DateTime time2("2024-09-24   10:0:0");
    auto ret = LemonSTU::DateTime::Now() - time1;
    //auto mj = itest();
    auto mstr = test();
    std::cout << mstr << std::endl;
   // const char* str = u8"01Äã01hello,jack,welcome";//e4 bd a0
    const char* str1 = "01Äã01hello,jack,welcome";//c4 e3 30
    const char * code = "0Öª0";

    int len = 0;
    //LemonSTU::StringHelper::ANSI2UTF8(code, nullptr, len);
    //char* ccode = new char[len];
    char buffer[1024]{ 0 };
    LemonSTU::StringHelper::ANSI2UTF8(code,buffer, len);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
