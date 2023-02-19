#ifndef __EXCEPTION
#define __EXCEPTION

#include <iostream>


class DateException : public std::exception
{
public:
	virtual const char* what() const override
	{
		return "Failed because you entered invalid date!\n";
	}
};
class DayException : public DateException
{
	int day;
public:
	DayException(int day) :day(day) {}
	virtual const char* what() const override
	{
		return "Failed because you enter invalid day!\n";
	}
};

class MonthException : public DateException
{
	int month;
public:
	MonthException(int month) :month(month) {}
	virtual const char* what() const override
	{
		return "Failed because you enter invalid month!\n";
	}
};

class YearException : public DateException
{
	int year;
public:
	YearException(int year) :year(year) {}
	virtual const char* what() const override
	{
		return "Failed because you enter invalid year!\n";
	}

};

class NameException : public std::exception
{
public:

	virtual const char* what() const override
	{
		return "Failed while create the name, name can't be empty!\n";
	}

};

class TimeException : public std::exception
{
public:

	virtual const char* what() const override
	{
		return "Failed because you enter invalid time!\n";
	}

};

class HourException : public TimeException
{
	int hour;
public:
	HourException(int hour) :hour(hour) {}
	virtual const char* what() const override
	{
		return "Failed because you enter invalid hour value!\n";
	}

};

class MinutesException : public TimeException
{
    int minutes;
public:
	MinutesException(int minutes) :minutes(minutes) {}
	virtual const char* what() const override
	{
		return "Failed because you enter invalid minutes value!\n";
	}

};


#endif





