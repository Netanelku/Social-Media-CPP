#ifndef __STATUSVIDEO_H
#define __STATUSVIDEO_H

#include "Status.h"

const string VIDEO = "breakComputer.mp4";

class StatusVideo : public Status
{
private:
	string videoSource;
public:
	StatusVideo(const Date& date, const Time& time, string text, int color, string videoSource) :Status(date, time,text, color), videoSource(videoSource){};
	StatusVideo(const Status& other, string videoSource) :Status(other), videoSource(videoSource) {};
	StatusVideo(const StatusVideo& other) : Status(other), videoSource(videoSource) {};
	virtual ~StatusVideo() = default;
	virtual void toOs(ostream& os) const override;
	virtual bool operator==(const Status& other) const override;
	


};



#endif
