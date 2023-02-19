#pragma warning(disable: 4996)

#include "Status.h"
#include "Date.h"
#include "Time.h"
#include "Exception.h"
Status::Status(const Date& date, const Time& time, string text, int color) :date(date), time(time)//Constructor
{
	if (text.size() == 0)
		throw NameException();
	this->text = text;
	this->color = color;
}
Status::Status(const Status& other) : date(other.date), time(other.time)
{
	this->text = other.text;
	this->color = other.color;
}
Status::Status(const Status&& other) : date(other.date), time(other.time)
{
	this->text = std::move(other.text);
	this->color = std::move(other.color);
}
ostream& operator<<(ostream& os, const Status& other)
{
	if (typeid(os) == typeid(ofstream))
	{
		os << other.date << " " << other.color << " " << other.time << " " << typeid(other).name() + 6 << endl; 
		os << "/" << other.text << endl;
	}
	else
	{
		switch (other.color)
		{
		case Blue:
			os << "\033[1;34m";
			break;
		case Yellow:
			os << "\033[1;33m";
			break;
		case Purple:
			os << "\033[1;35m";
			break;
		}
		os << "\n************************************";
		os << "\nDate: " << other.date << " Time: " << other.time;
		os << "\nText: " << other.text << endl;
		os << "************************************" << endl << endl;
		other.toOs(os);
		os << "\033[0m";
	}
	return os;
}

bool Status::operator==(const Status& other)const
{

	return (text.compare(other.text) == 0)&&(((strcmp(typeid(*this).name(),typeid(Status).name())==0)
	     	&&(strcmp(typeid(other).name(), typeid(Status).name()) == 0))|| (strcmp(typeid(*this).name(), typeid(Status).name()) != 0));
}

bool Status::operator!=(const Status& other)const
{
	return !(*this == other);
}
