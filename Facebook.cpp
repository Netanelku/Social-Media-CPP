#pragma warning(disable: 4996)
#include <fstream>
using namespace std;

#include "Facebook.h"

void Facebook::showMainMenu() const
{//This function print the menu options and check if the input is valid.

	const string statusArr[13] = { "Add User","Add fan page","Add Status","Show all statuses","Show 10 most updated statuses","Make friendship","Cancel friendship","Add member to fan page","Remove member from fan page","Show all users and fan pages","Show all related connections","Compare between entities","Exit" };

	cout << "*****************************" << endl
		<< "          Facebook           " << endl
		<< "*****************************" << endl;

	for (int i = 0; i < 13; i++)
	{
		cout << "Press " << i + 1 << " for " << statusArr[i] << endl;
	}
}

void Facebook::run_manager_interface(InputFunctions& input)
{//This function take the choice of the user and transfers the program to the appropriate function.

	bool operation = true;
	while (operation)
	{
		int choice;
		showMainMenu();
		choice = input.getValidMenuChoice(13);
		system("CLS");
		cout << "*****************************" << endl
			<< "          Facebook           " << endl
			<< "*****************************" << endl << endl;
		switch (choice - 1)
		{
		case Add_user:
			addFriend(input);
			break;
		case Add_fan_page:
			addFanPage(input);
			break;
		case Add_Status:
			add_status(input);
			break;
		case Show_all_statuses:
			show_statuses(input);
			break;
		case Show_10_most_updated_statuses:
			show_statuses_member(User::SHOW_10_STATUSES, input);
			break;
		case Make_friendship:
			makeFriendship(input);
			break;
		case Cancel_friendship:
			cancelFriendship(input);
			break;
		case Add_member_to_fan_page:
			addMemberToFanPage(input);
			break;
		case Remove_member_from_fan_page:
			removeMemberFromFanPage(input);
			break;
		case Show_all_users_and_fan_pages:
			showAllMembersAndPages();
			break;
		case Show_all_related_connections:
			showAllFriends(input);
			break;
		case Compare_between_entities:
			compareBetweenEntities(input);
			break;
		case Exit:
			cout << "Thank You for choosing Facebook !\n\n\n\n\n\n\n\n\n\n\n";
			saveData();
			operation = false;
			break;
		}
		cout << endl << endl << "Press Enter to Continue...\n";
		cin.ignore();
		system("CLS");
	}
}

void Facebook::Load_Data_From_File()///upload data
{//This function has hard coded data.
	
	int number_of_users, number_of_statuses, number_of_pages;
	ifstream inFile("Data.txt");

	inFile >> number_of_users;
	for(int i =0; i <number_of_users ; i++)
	{
		User* LoadedUser = new User(inFile);
		insertNewFriend(*(LoadedUser));
		list<User>::iterator itrU = userList.begin();
		for(int k=0;k<i;k++, ++itrU){}
		inFile >> number_of_statuses;
		for(int j=0; j<number_of_statuses; j++)
		{
			Status* LoadedStatus = loadStatus(inFile);
			(itrU)->insert_new_status(LoadedStatus);
		}
		delete LoadedUser;
	}

	inFile >> number_of_pages;
	for(int i =0; i <number_of_pages ; i++)
	{
		FanPage* LoadedFanPage = new FanPage(inFile);
		insertNewPage(*(LoadedFanPage));
		inFile >> number_of_statuses;
		for(int j=0; j<number_of_statuses; j++)
		{
			Status* LoadedStatus = loadStatus(inFile);
			LoadedFanPage->insert_new_status(LoadedStatus);
		}
		delete LoadedFanPage;
	}

	for (int i = 0; i < number_of_users; i++)
	{
		string user_name, name;
		inFile >> user_name;
		int number_of_friends;
		inFile >> number_of_friends;
		for (int j = 0; j < number_of_friends; j++)
		{
			inFile >> name;
			loadUserConnections(user_name, name);
		}
		int number_of_followerPages;
		inFile >> number_of_followerPages;
		for (int k = 0; k < number_of_followerPages; k++)
		{
			inFile >> name;
			loadPageConnections(user_name, name);
		}
	}

	inFile.close();
	/*
	Date d1(23, 11, 2022);
	insertNewFriend(*(new User("Netanel", Date(19, 8, 1999))));
	insertNewFriend(*(new User("Amit", Date(12, 3, 1999))));
	insertNewFriend(*(new User("Eden", Date(13, 10, 1999))));
	insertNewPage(*(new FanPage("Food")));
	insertNewPage(*(new FanPage("Games")));
	insertNewPage(*(new FanPage("Gym")));
	list<User>::iterator itrU = userList.begin();
	list<User>::iterator tempU;
	list<FanPage>::iterator tempP;
	list<FanPage>::iterator itrP = pageList.begin();
	tempU = itrU;
	*itrP += (*itrU);
	*(++itrP) += (*(itrU));
	*(tempU) += *(++itrU);
	tempU++;
	*(itrU) += *(++tempU);
	itrU = userList.begin();
	itrP = pageList.begin();
	(itrU)->insert_new_status(new StatusVideo(Date(25, 11, 2022), Time(12, 45), "Hello, My name is Netanel",Blue,VIDEO));
	(itrU)->insert_new_status(new StatusPicture(Date(25, 11, 2022), Time(14, 45), "What's up everyone?", Purple,PICTURE));
	(++itrU)->insert_new_status(new Status(Date(27, 11, 2022), Time(13, 20), "Hello, My name is Amit", Blue));
	(itrU)->insert_new_status(new StatusVideo(Date(27, 11, 2022), Time(16, 20), "What's up everyone?", Yellow,VIDEO));
	(++itrU)->insert_new_status(new StatusPicture(Date(28, 11, 2022), Time(12, 45), "Hello, My name is Eden",Purple,PICTURE));
	(itrU)->insert_new_status(new Status(Date(29, 11, 2022), Time(15, 45), "What's up everyone?", Blue));
	(itrP)->insert_new_status(new StatusVideo(Date(26, 11, 2022), Time(13, 13), "Everyone likes Food", Yellow,VIDEO));
	(itrP)->insert_new_status(new StatusPicture(Date(27, 11, 2022), Time(20, 12), "Follow this page for more recipes:)", Purple, PICTURE));
	(++itrP)->insert_new_status(new Status(Date(28, 11, 2022), Time(15, 10), "What is the best game you played?", Blue));
	(itrP)->insert_new_status(new StatusPicture(Date(29, 11, 2022), Time(20, 50), "Stay updated with the most recent news of the games world!", Purple, PICTURE));
	(++itrP)->insert_new_status(new StatusVideo(Date(16, 12, 2022), Time(16, 20), "What is the best game you played?",Blue, VIDEO));
	(itrP)->insert_new_status(new Status(Date(17, 12, 2022), Time(15, 40), "Stay updated with the most recent news of the games world!", Purple));
	*/
}

Status* Facebook::loadStatus(ifstream& in)
{
	Status* status;
	Date date(in);
	int color;
	in >> color ;
	Time time(in);
	string type, text;
	char delimiter;
	in >> type>> delimiter;
	getline(in, text);

	if (type.compare(typeid(Status).name() + 6) == 0)
	{
		status = new Status(date, time, text, color);
	}
	else if(type.compare(typeid(StatusPicture).name() + 6) == 0)
	{
       status = new StatusPicture(date, time, text, color, PICTURE);
	}
	else
	{
	   status = new StatusVideo(date, time, text, color, VIDEO);
	}
	return status;
}

void Facebook::loadUserConnections(string name1, string name2)
{
    int friend1 = findUser(name1);
	int friend2 = findUser(name2);
    list<User>::iterator tr1 = userList.begin();
	list<User>::iterator tr2 = userList.begin();
	for (int i = 0; i < friend1; i++)
		++tr1;
	for (int i = 0; i < friend2; i++)
		++tr2;
	if ((tr1)->is_friendship_exist((tr2)->getName()) == User::NOT_FOUND)
	{
	    *(tr1) += *(tr2);//use of operator +=
	}
}

void Facebook::loadPageConnections(string user_name, string page_name)
{
    int user = findUser(user_name);
	int page = findPage(page_name);
    list<User>::iterator tr1 = userList.begin();
	list<FanPage>::iterator tr2 = pageList.begin();
	for (int i = 0; i < user; i++)
		++tr1;
	for (int i = 0; i < page; i++)
		++tr2;
	if ((tr1)->is_friendship_exist((tr2)->getName()) == User::NOT_FOUND)
	{
	    *(tr1) += *(tr2);//use of operator +=
	}
}

void Facebook::addFriend(InputFunctions& input)
{//This function add new member to facebook.

	int index;
	User* member = nullptr;
	do
	{
		member = &(input.getNewUser());
		index = findUser(member->getName());
		if (index != User::NOT_FOUND)
		{
			cout << "The requested name is not avialible" << endl;
			cout << "\n--- You need to enter the data again ---" << endl;
			delete member;
		}

	} while (index != User::NOT_FOUND);
	insertNewFriend(*member);
	delete member;
	cin.ignore();
}
int  Facebook::findUser(const string& name) const
{//This function search for member in the members array of facebook. 
 //If the member in the array the function return the index else return -1.

	string current_name;
	int i = 0, found = -1;
	list<User>::const_iterator itr = userList.begin();
	list<User>::const_iterator itrEnd = userList.end();
	while (itr != itrEnd && found == -1)
	{
		current_name = itr->getName();
		if (name.compare(current_name) == 0)
		{
			found = i;
		}
		itr++;
		i++;
	}
	return found;
}
void Facebook::insertNewFriend(User& member)
{//This function insert the new member in to the members array of facebook.
	userList.push_back(member);
}

void Facebook::addFanPage(InputFunctions& input)
{//This function add new fanPage to facebook.

	int index;
	FanPage* page;
	do {
		page = &(input.getNewFanPage());
		index = findPage(page->getName());
		if (index != User::NOT_FOUND)
		{
			cout << "The requested name is not avialible" << endl;
			cout << "\n--- You need to enter the data again ---" << endl;
			delete page;
		}
	} while (index != User::NOT_FOUND);

	insertNewPage(*page);
	delete page;
	cin.ignore();
}

int  Facebook::findPage(const string& namePage) const
{//This function search for fanPage in the fanPages array of facebook. 
 //If the fanPage in the array the function return the index else return -1.

	string current_name;
	int i = 0, found = -1;
	list<FanPage>::const_iterator tr = pageList.begin();
	list<FanPage>::const_iterator trEnd = pageList.end();
	while (tr != trEnd && found == -1)
	{
		current_name = tr->getName();
		if (namePage.compare(current_name) == 0)
			found = i;
		tr++;
		i++;
	}
	return found;
}
void Facebook::insertNewPage(FanPage& page)
{//This function insert the new page in to the pages array of facebook.
	pageList.push_back(page);
}

void Facebook::add_status(InputFunctions& input)
{//This function is the total function of add status to member or fanPage.

	cout << "Please enter which entity you want:" << endl
		<< "1 - Member" << endl
		<< "2 - Page" << endl
		<< "3 - Back to menu" << endl << endl;
	int choice = input.getValidMenuChoice(3);

	switch (choice)
	{
	case 1:
		add_status_member(input);
		break;
	case 2:
		add_status_page(input);
		break;
	case 3:
		return;
		break;
	}
}
void Facebook::add_status_member(InputFunctions& input)
{//This function add status to status array of requested member.

	string member_name = std::move(input.getMemeberName());
	int index_member = findUser(member_name);
	while (index_member == User::NOT_FOUND)
	{
		cout << "Could not find the requsted member!, please try again" << endl << endl;
		member_name = std::move(input.getMemeberName());
		index_member = findUser(member_name);
	}
	list<User>::iterator tr = userList.begin();
	for (int i = 0; i < index_member; i++)
		++tr;
	Status* status = input.getNewStatus();
	(tr)->insert_new_status(status);
}
void Facebook::add_status_page(InputFunctions& input)
{//This function add status to status fanPage of requested fanPage. 

	string page_name = std::move(input.getPageName());
	int index_friend = findPage(page_name);
	while (index_friend == User::NOT_FOUND)
	{
		cout << "Could not find the requsted page!, please try again" << endl << endl;
		page_name = std::move(input.getPageName());
		index_friend = findPage(page_name);
	}

	list<FanPage>::iterator tr = pageList.begin();
	for (int i = 0; i < index_friend; i++)
		++tr;
	Status* status = input.getNewStatus();
	(tr)->insert_new_status(status);
}

void Facebook::show_statuses(InputFunctions& input) const
{//This function is the total function of print status of member or fanPage.

	cout << "Please enter which entity you want:" << endl
		<< "1 - Member" << endl
		<< "2 - Page" << endl
		<< "3 - Back to menu" << endl << endl;
	int choice = input.getValidMenuChoice(3);

	switch (choice)
	{
	case 1:
		show_statuses_member(User::SHOW_ALL_STATUSES, input);
		break;
	case 2:
		show_statuses_fanPage(User::SHOW_ALL_STATUSES, input);
		break;
	case 3:
		return;
		break;
	}
}
void Facebook::show_statuses_member(int option, InputFunctions& input) const
{//This function print the statuses of requested member.

	string member_name = std::move(input.getMemeberName());
	cin.ignore();
	int ind = findUser(member_name);
	while (ind == User::NOT_FOUND)
	{
		cout << "Could not find the requsted member!" << endl << endl;;
		member_name = std::move(input.getMemeberName());
		ind = findUser(member_name);
		cin.ignore();
	}

	list<User>::const_iterator tr = userList.begin();
	for (int i = 0; i < ind; i++)
		++tr;

	if (option == User::SHOW_ALL_STATUSES)
		(tr)->print_statuses(User::SHOW_ALL_STATUSES);
	else
		(tr)->print_Friends_statuses();
}
void Facebook::show_statuses_fanPage(int option, InputFunctions& input) const
{//This function print the statuses of requested fanPage.

	string page_name = std::move(input.getPageName());
	int ind = findPage(page_name);
	cin.ignore();
	list<FanPage>::const_iterator tr = pageList.begin();

	while (ind == User::NOT_FOUND)
	{
		cout << "Could not find the requsted Page!, please try again" << endl << endl;
		page_name = std::move(input.getPageName());
		ind = findPage(page_name);
		cin.ignore();
	}
	for (int i = 0; i < ind; i++)
		++tr;

	(tr)->print_fanPage(option);
}

void Facebook::makeFriendship(InputFunctions& input)
{//This function make connection between 2 members.

	cout << "Please select two members to be friends:\n\n";
	int friend1, friend2;
	string friend_name;
	do
	{
		friend_name = std::move(input.getMemeberName());
		friend1 = findUser(friend_name);
		friend_name = std::move(input.getMemeberName());
		friend2 = findUser(friend_name);
		if (friend1 == User::NOT_FOUND || friend2 == User::NOT_FOUND)
			cout << endl << "At least one of the request member is not valid, plaese try again" << endl;
		else if (friend1 == friend2)
			cout << endl << "You can't make friendship with yourself, plaese try again" << endl;
	} while (friend1 == User::NOT_FOUND || friend2 == User::NOT_FOUND || friend1 == friend2);

	list<User>::iterator tr1 = userList.begin();
	list<User>::iterator tr2 = userList.begin();
	for (int i = 0; i < friend1; i++)
		++tr1;
	for (int i = 0; i < friend2; i++)
		++tr2;
	cout << "\n******************************************\n";
	cin.ignore();
	if ((tr1)->is_friendship_exist((tr2)->getName()) == User::NOT_FOUND)
	{
		*(tr1) += *(tr2);//use of operator +=
		cout << (tr1)->getName() << " and " << (tr2)->getName() << " are friends right now!";
	}
	else
		cout << (tr1)->getName() << " and " << (tr2)->getName() << " are already friends !";
	cout << "\n******************************************";

}

void Facebook::cancelFriendship(InputFunctions& input)
{//This function cancel the connection between 2 members.

	cout << "Please select two members to cancel thier friendship:\n\n";
	string friend_name;
	int friend1, friend2;
	do
	{
		friend_name = std::move(input.getMemeberName());
		friend1 = findUser(friend_name);
		friend_name = std::move(input.getMemeberName());
		friend2 = findUser(friend_name);
		if (friend1 == User::NOT_FOUND || friend2 == User::NOT_FOUND)
			cout << endl << "At least one of the request member is not valid, plaese try again" << endl;
		else if (friend1 == friend2)
			cout << endl << "You can't cancel friendship with yourself, plaese try again" << endl;
	} while (friend1 == User::NOT_FOUND || friend2 == User::NOT_FOUND || friend1 == friend2);

	list<User>::iterator tr1 = userList.begin();
	list<User>::iterator tr2 = userList.begin();
	for (int i = 0; i < friend1; i++)
		++tr1;
	for (int i = 0; i < friend2; i++)
		++tr2;
	cin.ignore();
	cout << "\n******************************************\n";
	if ((tr1)->cancelfriendShip(&(*(tr2))))
		cout << (tr1)->getName() << " and " << (tr2)->getName() << " are not friends right now!";
	else
		cout << (tr1)->getName() << " and " << (tr2)->getName() << " were not friends!";
	cout << "\n******************************************";
}

void Facebook::addMemberToFanPage(InputFunctions& input)
{//This function make the connection between member and fanPage.

	cout << "Please select a fanPage and member to connect them:\n\n";
	int fanPageInd, friendInd;
	string page_name, friend_name;
	do
	{
		page_name = std::move(input.getPageName());
		fanPageInd = findPage(page_name);
		friend_name = std::move(input.getMemeberName());
		friendInd = findUser(friend_name);
		if (fanPageInd == User::NOT_FOUND || friendInd == User::NOT_FOUND)
			cout << endl << "At least one of the request names of member or fanpage is not valid, plaese try again" << endl;
	} while (fanPageInd == User::NOT_FOUND || friendInd == User::NOT_FOUND);
	cin.ignore();
	cout << "\n******************************************\n";
	list<FanPage>::iterator trPage = pageList.begin();
	list<User>::iterator trUser = userList.begin();
	for (int i = 0; i < fanPageInd; i++)
		++trPage;
	for (int i = 0; i < friendInd; i++)
		++trUser;
	if (!((trPage)->is_connected_exist(*(trUser))))
	{
		*(trPage) += (*(trUser));
		cout << (trPage)->getName() << " and " << (trUser)->getName() << " are connected right now!";
	}
	else
		cout << (trPage)->getName() << " and " << (trUser)->getName() << " were already connected !";
	cout << "\n******************************************";

}
void Facebook::removeMemberFromFanPage(InputFunctions& input)
{//This function cancel the connection between member and fanPage.

	cout << "Please select a fanPage and member to cancel their connection:\n\n";
	int fanPageInd, friendInd;
	string page_name, friend_name;
	do
	{
		page_name = std::move(input.getPageName());
		fanPageInd = findPage(page_name);
		friend_name = std::move(input.getMemeberName());
		friendInd = findUser(friend_name);
		if (fanPageInd == User::NOT_FOUND || friendInd == User::NOT_FOUND)
			cout << endl << "At least one of the request names of member or fanpage is not valid, plaese try again" << endl;
	} while (fanPageInd == User::NOT_FOUND || friendInd == User::NOT_FOUND);
	list<FanPage>::iterator trPage = pageList.begin();
	list<User>::iterator trUser = userList.begin();
	for (int i = 0; i < fanPageInd; i++)
		++trPage;
	for (int i = 0; i < friendInd; i++)
		++trUser;
	cin.ignore();
	cout << "\n******************************************\n";
	if ((trPage)->removeMember(&(*(trUser))))
		cout << (trPage)->getName() << " and " << (trUser)->getName() << " are not connected right now!";
	else
		cout << (trPage)->getName() << " and " << (trUser)->getName() << " were not connected!";
	cout << "\n******************************************";
}
void Facebook::showAllMembersAndPages()const
{//This function print all the members and fanPages in facebook.
	list<FanPage>::const_iterator trPage = pageList.begin();
	list<User>::const_iterator trUser = userList.begin();
	list<FanPage>::const_iterator trPageEnd = pageList.end();
	list<User>::const_iterator trUserEnd = userList.end();

	cout << "These are all the members who are on Facebook: \n" << endl;
	for (int i = 0; trUser != trUserEnd; trUser++, i++)
		cout << i + 1 << ")" << (trUser)->getName() << endl;
	
	cout << "\n\nThese are all the fanPages on Facebook: \n" << endl;
	for (int i = 0; trPage != trPageEnd; trPage++, i++)
		cout << i + 1 << ")" << trPage->getName() << endl;
}

void Facebook::showAllFriends(InputFunctions& input) const
{//This the total function that prints all the friends of requested member or page. 

	cout << "Please enter which entity you want:" << endl
		<< "1 - Member" << endl
		<< "2 - Page" << endl
		<< "3 - Back to menu" << endl << endl;
	int choice = input.getValidMenuChoice(3);

	switch (choice)
	{
	case 1:
		show_member_friends(input);
		break;
	case 2:
		show_fanPage_friends(input);
		break;
	case 3:
		return;
		break;
	}
}
void Facebook::show_member_friends(InputFunctions& input) const
{//This function print all the friends of requested member.

	string friend_name = std::move(input.getMemeberName());
	cin.ignore();
	int ind = findUser(friend_name);
	list<User>::const_iterator trUser = userList.begin();
	while (ind == User::NOT_FOUND)
	{
		cout << "Could not find the requsted member!, please try again" << endl << endl;
		friend_name = std::move(input.getMemeberName());
		ind = findUser(friend_name);
		cin.ignore();
	}
	for (int i = 0; i < ind; i++)
		++trUser;

	cout << *(trUser);

}
void Facebook::show_fanPage_friends(InputFunctions& input) const
{//This function print all the friends of requested page. 
	list<FanPage>::const_iterator trPage = pageList.begin();

	string page_name = std::move(input.getPageName());
	cin.ignore();
	int ind = findPage(page_name);
	while (ind == User::NOT_FOUND)
	{
		cout << "Could not find the requsted fanPage!, please try again" << endl << endl;
		page_name = std::move(input.getPageName());
		ind = findPage(page_name);
		cin.ignore();
	}
	for (int i = 0; i < ind; i++)
		++trPage;
	cout << (*trPage);

}

void Facebook::compareBetweenEntities(InputFunctions& input) const
{//This  function compare between requested entities.
	cout << "Please enter which compare you want:" << endl
		<< "1 - Between two members" << endl
		<< "2 - Between two Pages" << endl
		<< "3 - Between member and page" << endl
		<< "4 - Between page and member" << endl
		<< "5 - Back to menu" << endl << endl;
	int choice = input.getValidMenuChoice(5);

	switch (choice)
	{
	case 1:
		compareMembers(input);
		break;
	case 2:
		comparePages(input);
		break;
	case 3:
		compareMemberAndPage(input, choice);
		break;
	case 4:
		compareMemberAndPage(input, choice);
		break;
	case 5:
		return;
		break;
	}
}
void Facebook::compareMembers(InputFunctions& input) const
{//This function compare between the amount of friends of 2 requested members.
	cout << "\nPlease select two member to copmare between them:" << endl << endl;
	int member1, member2;
	string member1_name, member2_name;
	do
	{
		member1_name = std::move(input.getMemeberName());
		member1 = findUser(member1_name);
		member2_name = std::move(input.getMemeberName());
		member2 = findUser(member2_name);
		if (member1 == User::NOT_FOUND || member2 == User::NOT_FOUND)
			cout << endl << "At least one of the request members is not valid, plaese try again" << endl;
		else if (member1 == member2)
			cout << endl << "You can't compare between the same member!, plaese try again" << endl;
	} while (member1 == User::NOT_FOUND || member2 == User::NOT_FOUND || member1 == member2);
	list<User>::const_iterator itr1 = userList.begin();
	list<User>::const_iterator itr2 = userList.begin();
	for (int i = 0; i < member1; i++)
		++itr1;
	for (int i = 0; i < member2; i++)
		++itr2;
	cin.ignore();
	cout << "\n*******************************************************************\n";
	if (*itr1 > *itr2)
		cout << "The member:" << member1_name << " has more friends " << endl;
	else
		cout << "The member:" << member2_name << " has more friend" << endl;
	cout << "*******************************************************************\n";
}
void Facebook::comparePages(InputFunctions& input) const
{//This function compare between the amount of friends of 2 requested pages.
	cout << "\nPlease select two pages to copmare between them: " << endl << endl;
	int page1, page2;
	string page1_name, page2_name;
	do
	{
		page1_name = std::move(input.getPageName());
		page1 = findPage(page1_name);
		page2_name = std::move(input.getPageName());
		page2 = findPage(page2_name);
		if (page1 == User::NOT_FOUND || page2 == User::NOT_FOUND)
			cout << endl << "At least one of the request pages is not valid, plaese try again" << endl;
		else if (page1 == page2)
			cout << endl << "You can't compare between the same page!, plaese try again" << endl;
	} while (page1 == User::NOT_FOUND || page2 == User::NOT_FOUND || page1 == page2);
	list<FanPage>::const_iterator itr1 = pageList.begin();
	list<FanPage>::const_iterator itr2 = pageList.begin();
	for (int i = 0; i < page1; i++)
		++itr1;
	for (int i = 0; i < page2; i++)
		++itr2;
	cin.ignore();
	cout << "\n*******************************************************************\n";
	if (*itr1 > *itr2)
		cout << "The page:" << page1_name << " has more friends "<< endl;
	else
		cout << "The page:" << page2_name << " has more friends "<< endl;
	cout << "*******************************************************************\n";
}
void Facebook::compareMemberAndPage(InputFunctions& input, int typeOfOperator) const
{//This function compare between the amount of friends of requested member and page.
	cout << "\nPlease select member and page to copmare between them: " << endl << endl;
	int page, friendInd;
	string page_name, friend_name;
	do
	{
		friend_name = std::move(input.getMemeberName());
		friendInd = findUser(friend_name);
		page_name = std::move(input.getPageName());
		page = findPage(page_name);
		if (page == User::NOT_FOUND || friendInd == User::NOT_FOUND)
			cout << endl << "At least one of the request page or member is not valid, plaese try again" << endl;
	} while (page == User::NOT_FOUND || friendInd == User::NOT_FOUND);
	list<FanPage>::const_iterator itr1 = pageList.begin();
	list<User>::const_iterator itr2 = userList.begin();
	for (int i = 0; i < page; i++)
		++itr1;
	for (int i = 0; i < friendInd; i++)
		++itr2;
	cin.ignore();
	cout << "\n*******************************************************************\n";
	string result;
	switch (typeOfOperator)
	{
	case 3:
		if (*itr2 > *itr1)
			result = friend_name;
		else
			result = page_name;
		break;
	case 4:
		if (*itr1 > *itr2)
			result = page_name;
		else
			result = friend_name;
		break;
	}
	cout << "The entity:" << result << " has more friends " << endl;
	cout << "*******************************************************************\n";

}


void Facebook::saveData()const
{
	ofstream  outFile("Data.txt", ios::trunc);
	int size = userList.size();
	outFile << size <<endl;
	list<User>::const_iterator trS = userList.begin();
	list<User>::const_iterator trSend = userList.end();
	for(; trS!=trSend; ++trS)
	{
		outFile << *trS;
	}
	size = pageList.size();
	outFile << size <<endl;
	list<FanPage>::const_iterator ptrS = pageList.begin();
	list<FanPage>::const_iterator ptrSend = pageList.end();
	for(; ptrS!=ptrSend; ++ptrS)
	{
		outFile << *ptrS;
	}
	list<User>::const_iterator itrS = userList.begin();
	list<User>::const_iterator itrSend = userList.end();
	for (; itrS != itrSend; ++itrS)
	{
		(*itrS).loadFriendships(outFile);
	}
	outFile.close();
}

void newTerminate()
{
	cout << "A problem occured, please call support!" << endl;
	exit(1);
}


