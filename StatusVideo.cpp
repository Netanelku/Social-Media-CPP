
#include "StatusVideo.h"
#include <fstream>
using namespace std;


void StatusVideo::toOs(ostream& os) const
{
	if (typeid(os) == typeid(ofstream))
		os << videoSource.size() << " " << videoSource;
	else
	{
		os << "Starting the video " << this->videoSource << "...";
		system(this->videoSource.c_str());
		os << endl << endl;
	}
}

bool StatusVideo::operator==(const Status& other) const
{
     if (!Status::operator==(other))
	      return false;

	 const StatusVideo* temp = dynamic_cast<const StatusVideo*>(&other);
	 if (temp)
		 return true;
	 else
		 return false;
}
