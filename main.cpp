#pragma warning(disable: 4996)
#include <iostream>
using namespace std;

#include "Facebook.h"
#include "InputFunctions.h"

/*
* Created by:
* Eden Ismah-Moshe 209524628 Group Num. 12111955
* Netanel Kuchma   209344365 Group Num. 12111955
*/

int main()
{
	set_terminate(newTerminate);
	Facebook system;
	InputFunctions input;
	system.Load_Data_From_File();
	system.run_manager_interface(input);

}