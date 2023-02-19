#ifndef __TIME
#define __TIME
#include <fstream>
using namespace std;
class Time {
private:
	int hour, minute;
public:
	Time(int hour, int minute)noexcept(false);//constructor
	Time(istream& in);
	friend ostream& operator<<(ostream& os, const Time& other);
	friend istream& operator>>(istream& in,Time& other);
};
#endif