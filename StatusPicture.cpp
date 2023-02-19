#include "StatusPicture.h"
#include <fstream>
using namespace std;

void StatusPicture::toOs(ostream& os) const
{
	if (typeid(os) == typeid(ofstream))
		os << pictureSource.size() << " " << pictureSource;
	else
	{
		os << "starting the picture " << this->pictureSource << " ...";
		system(this->pictureSource.c_str());
		os << endl << endl;
	}
}
bool StatusPicture::operator==(const Status& other) const
{
	if (!Status::operator==(other))
		return false;

	const StatusPicture* temp = dynamic_cast<const StatusPicture*>(&other);
	 if (temp)
		 return true;
	 else
		 return false;
}