#pragma warning(disable: 4996)

#include "Date.h"
#include "Exception.h"

Date::Date(int day, int month, int year)noexcept(false)//constructor
{
	if (day < 1 || day>31)
		throw DayException(day);
	if (month < 1 || month>12)
		throw MonthException(month);
	if (year < 0 || year > 2023)
		throw YearException(year);
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::Date(ifstream& in)
{
	in >> *this;
}

 ostream& operator<<(ostream& os, const Date& other)
{
	os << other.day << "/" << other.month << "/" << other.year;
	return os;
}

 istream& operator>>(istream& in, Date& date)
 {
	 if (typeid(in) == typeid(ifstream))
	 {
		char delimeter;
		in >> date.day >> delimeter >> date.month >> delimeter >> date.year;
	 }
	 return in;
 }