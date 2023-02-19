#ifndef __INPUTFUNCTIONS
#define __INPUTFUNCTIONS

#include "User.h"
#include "FanPage.h"
#include "Status.h"
#include "StatusPicture.h"
#include "StatusVideo.h"
#include <String>

class InputFunctions
{
public:
    User&    getNewUser();
    int      getValidMenuChoice(int maxNumber);
    FanPage& getNewFanPage();
    Status*  getNewStatus();
    int      getColor();
    string   getMemeberName();
    string   getPageName();

};
#endif