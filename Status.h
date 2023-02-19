#ifndef __STATUS
#define __STATUS

#include <fstream>


#include "Time.h"
#include "Date.h"
#include <string>
enum color { Blue, Yellow, Purple };

class Status
{
private:
	string text;//use of string library so need to implement distractor
	int color;
	Date date;
	Time time;
public:
	Status(const Date& date, const Time& time, string text, int color);//Constructor
	Status(const Status& other);//Copy constructor
	Status(const Status&& other);
	virtual ~Status()=default;
	virtual void toOs(ostream& os)const  {};
	friend ostream& operator<<(ostream& os, const Status& other);
	virtual bool operator==(const Status& other)const;
	virtual bool operator!=(const Status& other)const;
};
#endif