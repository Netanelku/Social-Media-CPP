#ifndef __FANPAGE_H
#define __FANPAGE_H

class User;
class Status;

#include <vector>
#include <list>
#include <String>
#include "Exception.h"
#include "fstream"
class FanPage
{
private:
	string name;
	vector<User*> friendsList;
	vector<Status*> statusBoard;

public:
	FanPage(const string& name)noexcept(false);//Constructor
	FanPage(const FanPage& other)noexcept(false);//Copy constructor
	FanPage(const FanPage&& other)noexcept(false);
	FanPage(istream& in)noexcept(false);
	~FanPage();//Distractor

	const  string& getName() const;
	int    getFriendsListSize()const;
	void   insert_new_status(Status* requsted_status);
	void   print_fanPage(int option) const;
	bool   is_connected_exist(const User& member) const;
	int    find_friend_ind(const User& member) const;
	bool   removeMember(User* member);

	const  FanPage& operator+=(User& other);
	bool   operator>(const FanPage& other)const;//returns boolean var,doesnt change the object that excutes the function and no need to copy 'other' var
	bool   operator>(const User& other)const;
	friend ostream& operator<<(ostream& os, const FanPage& page);
	friend istream& operator>>(istream& in, FanPage& page);
};

#endif