#pragma warning(disable: 4996)
using namespace std;

#include "Time.h"
#include "Exception.h"

Time::Time(int hour, int minute)noexcept(false)//Constructor
{
	if (hour < 0 || hour>23)
		throw HourException(hour);
	if (minute < 0 || minute>59)
		throw MinutesException(minute);
	this->hour = hour;
	this->minute = minute;
}

Time::Time(istream& in)
{
	in >> *this;
}

ostream& operator<<(ostream& os, const Time& other)
{
	os << other.hour << ":" << other.minute;
	return os;
}

istream& operator>>(istream& in, Time& other)
{
	 char delimeter;
	 in >> other.hour >> delimeter >> other.minute;
	 return in;
}