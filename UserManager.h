#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <windows.h>
#include <vector>

#include "User.h"
#include "FileWithUsers.h"

using namespace std;

class UserManager
{
	int loggedInUserId;
	FileWithUsers fileWithUsers;
	vector<User> users;

	User getNewUserData();
	int getNewUserId();
	bool ifLoginExist(string login);
	void saveAllUsersToFile();


public:
	UserManager(string fileNameWithUsers) : fileWithUsers(fileNameWithUsers) {
		users = fileWithUsers.loadUsersFromFile();
		loggedInUserId = 0;
	};
	void registerUser();
	int loginUser();
    void changePassword();
	void logoutUser();
	bool isUserLoggedIn();
	int getLoggedInUserId();
	char chooseUserMenuOption();
};

#endif
