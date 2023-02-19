#ifndef __FACEBOOK_H
#define __FACEBOOK_H

#include <list>
#include <string.h>
#include "FanPage.h"
#include "User.h"
#include "Status.h"
#include "InputFunctions.h"
#include "Exception.h"


enum menuChoice {Add_user, Add_fan_page, Add_Status, Show_all_statuses, Show_10_most_updated_statuses, Make_friendship, Cancel_friendship, Add_member_to_fan_page, Remove_member_from_fan_page, Show_all_users_and_fan_pages, Show_all_related_connections, Compare_between_entities, Exit };
class Facebook//no need to implement constructor,distractor,copy
{
private:
	list<User>userList;
	list<FanPage> pageList;

public:
	Facebook() = default;
	Facebook(Facebook const& other) = delete; //Copy constructor
	void showMainMenu() const;
	void run_manager_interface(InputFunctions& input);
	void Load_Data_From_File();
	Status* loadStatus(ifstream& in);
	void loadUserConnections(string name1, string name2);
	void loadPageConnections(string user_name, string page_name);
	void addFriend(InputFunctions& input);//ex.1
	int  findUser(const string& name) const;
	void insertNewFriend(User& member);
	void addFanPage(InputFunctions& input);//ex.2
	int  findPage(const string& namePage) const;
	void insertNewPage(FanPage& page);
	void add_status(InputFunctions& input);//ex.3
	void add_status_member(InputFunctions& input);
	void add_status_page(InputFunctions& input);
	void show_statuses(InputFunctions& input) const;//ex.4
	void show_statuses_member(int option, InputFunctions& input) const;//ex.5
	void show_statuses_fanPage(int option, InputFunctions& input) const;
	void makeFriendship(InputFunctions& input);//ex.6
	void cancelFriendship(InputFunctions& input);//ex.7
	void addMemberToFanPage(InputFunctions& input);//ex.8             
	void removeMemberFromFanPage(InputFunctions& input);//ex.9          
	void showAllMembersAndPages()const;//ex.10        
	void showAllFriends(InputFunctions& input) const;//ex.11
	void show_member_friends(InputFunctions& input) const;
	void show_fanPage_friends(InputFunctions& input) const;
	void compareBetweenEntities(InputFunctions& input) const;
	void compareMembers(InputFunctions& input) const;
	void comparePages(InputFunctions& input) const;
	void compareMemberAndPage(InputFunctions& input, int typeOfOperator) const;
	void saveData()const ;

};
void newTerminate();

#endif