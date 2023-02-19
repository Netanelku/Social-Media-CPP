#ifndef __DATE
#define __DATE

#include <fstream>
using namespace std;

class Date {
private:
	int day, month, year;
public:
	Date(int day, int month, int year)noexcept(false);//constructor
	Date(ifstream& in);
	friend ostream& operator<<(ostream& os, const Date& other);
	friend istream& operator>>(istream& in, Date& date);
};
#endif