#pragma once
#include<functional>
#include <Windows.h>
#include <string>
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

		DateTime& AddDays(const int days);
		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		std::string ToString();
		/// <summary>
		/// get the time diff, unit hour
		/// </summary>
		/// <param name="datetime"></param>
		/// <returns></returns>
		double operator -(const DateTime& datetime);

	private:
		operator tm() const;
	};

	
}


