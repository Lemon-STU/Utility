#pragma once
#include<functional>
#include <Windows.h>
namespace LemonSTU
{
	class DateTime
	{
	private:
		int _Year;
		int _Month;
		int _Day;
		int _Hour;
		int _Minutes;
		int _Seconds;
	public:
		/// <summary>
		/// MillionSeconds
		/// </summary>
		/// <returns></returns>
		static long long Tick();
		static DateTime Now();

	public:
		DateTime(int year, int month, int day, int hour, int minute, int second)
			:_Year(year), _Month(month), _Day(day), _Hour(hour), _Minutes(minute), _Seconds(second) {};
		DateTime(int year, int month, int day) :DateTime(year, month, day, 0, 0, 0) {};
		DateTime() :DateTime(0, 0, 0) {}
		DateTime(const char* datetime);


		
		const char* ToString();

		int operator -(DateTime datetime);
	};

	
}


