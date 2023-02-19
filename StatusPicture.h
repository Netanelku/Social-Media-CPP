#ifndef __STATUSPICTURE_H
#define __STATUSPICTURE_H

#include "Status.h"

const  string PICTURE = "hello_world.png";

class StatusPicture : public Status
{
private:
	string pictureSource;
public:
	StatusPicture(const Date& date, const Time& time, string text, int color, string pictureSource) :Status(date, time, text, color), pictureSource(pictureSource) {}
	StatusPicture(const Status& other, string pictureSource) :Status(other), pictureSource(pictureSource) {};
	StatusPicture(const StatusPicture& other) :Status(other), pictureSource(pictureSource) {};
	virtual ~StatusPicture() = default;
	virtual void toOs(ostream& os) const override;
	virtual bool operator==(const Status& other) const override;

};

#endif
