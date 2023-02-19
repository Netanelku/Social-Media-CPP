

#include "InputFunctions.h"


User& InputFunctions::getNewUser()
{
	bool isValidData = false;
	User* member = nullptr;
	while (!isValidData)
	{
		string friend_name;
		cout << "Please enter Friend's name: ";
		cin >> friend_name;
		int day, month, year;
		char c_temp;//for read '/' in the date insert.
		cout << "Enter friend birth date (dd/mm/yyyy): ";
		cin >> day >> c_temp >> month >> c_temp >> year;

		try
		{
			Date new_date(day, month, year);
			member = new User(friend_name, new_date);
			isValidData = true;
		}
		catch (DateException& e) {
			cout << e.what() << endl;
		}
		catch (NameException& e) {
			cout << e.what() << endl;
		}
		catch (...)
		{
			cout << "Unknown Error!" << endl;
		}
		if (!isValidData)
			cout << "\n--- You need to enter the data again ---\n";
	}
	return *member;
}

int InputFunctions::getValidMenuChoice(int maxNumber)
{
	int userChoice = 0;
	do
	{
		cout << endl << "Your Choice: ";
		cin >> userChoice;
		if (userChoice > maxNumber || userChoice < 1)
			cout << "\nInvalid Choice! Please choose again! \n" << endl;
	} while (userChoice > maxNumber || userChoice < 1);
	cin.ignore();
	return userChoice;
}

FanPage& InputFunctions::getNewFanPage()
{
	bool isValidData = false;
	FanPage* page = nullptr;
	while (!isValidData)
	{
		string page_name;
		cout << "Please enter Page's name: ";
		cin >> page_name;
		try
		{
			page = new FanPage(page_name);
			isValidData = true;
		}
		catch (NameException& e) {
			cout << e.what() << endl;
		}
		catch (...)
		{
			cout << "Unknown Error!" << endl;
		}
		if (!isValidData)
			cout << "\n--- You need to enter the data again ---\n";
	}
	return *page;
}

Status* InputFunctions::getNewStatus()
{
	cout << "Choose the type of the status:"<< endl;
	cout << "1 - Text" << endl;
	cout << "2 - Picture" << endl;
	cout << "3 - Video" << endl;
	int type=getValidMenuChoice(3);
	 
	Status* status = nullptr;
	int day, month, year, minutes, hours;
	char c_temp;
	bool isValidData = false;
	string text;
	int color;
	while (!isValidData)
	{
		try
		{
			cout << "Enter Status date (dd/mm/yyyy): ";
			cin >> day >> c_temp >> month >> c_temp >> year;
			Date new_date(day, month, year);
			cout << "Enter Time (HH:MM): ";
			cin >> hours >> c_temp >> minutes;
			Time new_time(hours, minutes);
			cout << "Enter your status: ";
			cin.ignore();
			getline(cin, text);
			color = getColor();
			switch (type)
			{
			case 1:
				status= new Status(new_date, new_time, text, color);
				break;
			case 2: //choose picture
			{
				status = new StatusPicture(*(new Status(new_date, new_time, text, color)), PICTURE);//picture
				break;
			}
			case 3: //choose video
			{
				status = new StatusVideo(*(new Status(new_date, new_time, text, color)), VIDEO);//video
				break;
			}
			}
			isValidData = true;
		}
		catch (DateException& e) {
			cout << e.what() << endl;
		}
		catch (TimeException& e) {
			cout << e.what() << endl;
		}
		catch (NameException& e) {
			cout << e.what() << endl;
		}
		catch (...)
		{
			cout << "Unknown Error!" << endl;
		}
		if (!isValidData)
			cout << "\n--- You need to enter the data again ---\n";
	}
	return status;
}

int InputFunctions::getColor()
{ 
	const string colorsArr[3] = {"Blue", "Yellow", "purple" };
	cout << endl << "Please choose color from the following: " << endl;
	for(int i=1; i<=3; i++)
	{
		cout << i << " - "<<  colorsArr[i-1] <<endl;
	}
	int choice = getValidMenuChoice(3);
	return choice-1;
}

string InputFunctions::getMemeberName()
{
	string member_name;
	cout << "Please enter Member's name: ";
	cin >> member_name;
	while ((member_name).size() == 0)
	{
		cout << "Failed while create the name!, name can't be empty" << endl;  
		cout << "Please enter Member's name: ";
	    cin >> member_name;
	}
	return member_name;
}

string InputFunctions::getPageName()
{
	string page_name;
	cout << "Please enter Page's name: ";
	cin>>page_name;

	while (page_name.size() == 0)
	{
		cout << "Failed while create the name!, name can't be empty" << endl;  
		cout << "Please enter Page's name: ";
		cin >> page_name;
	}
	return page_name;
}