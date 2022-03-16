#include "UserManager.h"

char UserManager::chooseUserMenuOption()
{
	char choice;

	system("cls");
	cout << "             USER MENU              " << endl;
	cout << "------------------------------------" << endl;
	cout << "1. Add revenue" << endl;
	cout << "2. Add expense" << endl;
	cout << "3. Display current month balance" << endl;
	cout << "4. Display previous month balance" << endl;
	cout << "5. Display balance from chosen period" << endl;
	cout << "6. Change your password" << endl;
	cout << "9. Logout" << endl;
	cout << "-------------------------------------" << endl;
	cout << "Your choice: ";
	choice = AuxiliaryMethods::enterChar();
	cout << endl;

	return choice;
}

void UserManager::registerUser()
{
	User user = getNewUserData();
	users.push_back(user);
	fileWithUsers.appendUserToFile(user);

	cout << endl << "Your account has been set up." << endl << endl;
	system("pause");
}

User UserManager::getNewUserData()
{
	User user;

	user.setId(getNewUserId());

	string login = "", password = "", firstName = "", secondName = "";
	do{
		cout << "Enter your login: ";
		cin >> login;
		user.setLogin(login);
	}while (ifLoginExist(user.getLogin()) == true);

	cout << "Enter your password: ";
	cin >> password;
	user.setPassword(password);

	cout << "Enter your first name: ";
    cin.ignore();
	firstName = AuxiliaryMethods::enterLine();
	user.setFirstName(firstName);

	cout << "Enter your second name: ";
	secondName = AuxiliaryMethods::enterLine();
	user.setSecondName(secondName);

	return user;
}

int UserManager::getNewUserId()
{
	if (users.empty() == true)
		return 1;
	else
		return users.back().getId() + 1;
}

bool UserManager::ifLoginExist(string login)
{
	for (int i = 0; i < users.size(); i++) {
		if (users[i].getLogin() == login) {
			cout << "Login is already taken." << endl;
			return true;
		}
	}
	return false;
}

int UserManager::getLoggedInUserId()
{
	return loggedInUserId;
}

int UserManager::loginUser()
{
	User user;
	string login = "", password = "";

	cout << "Enter your login: ";
	cin >> login;
	cin.ignore();

	vector <User>::iterator itr = users.begin();
	while (itr != users.end()) {
		if (itr->getLogin() == login) {
			for (int attempts = 3; attempts > 0; attempts--) {
				cout << "Enter your password ? Attempts left: " << attempts << ": ";
				cin >> password;
				cin.ignore();
				user.setPassword(password);

				if (itr->getPassword() == password) {
					cout << endl << "You have successfully logged in." << endl << endl;
					system("pause");
					loggedInUserId = itr->getId();
					return loggedInUserId;
				}
			}
			cout << "You entered 3 times wrong password." << endl;
			system("pause");
			return 0;
		}
		itr++;
	}
	cout << "There is no user with such login." << endl << endl;
	system("pause");
	return 0;
}

bool UserManager::isUserLoggedIn()
{
	if (loggedInUserId > 0)
		return true;
	else
		return false;
}

void UserManager::logoutUser()
{
	loggedInUserId = 0;
}

void UserManager::changePassword()
{
	string newPassword = "";
	cout << "Enter new password: ";
	cin >> newPassword;
	cin.ignore();

	for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++){
		if (itr->getId() == loggedInUserId){
			itr->setPassword(newPassword);
			cout << "Your password has been changed." << endl << endl;
			system("pause");
		}
	}

	saveAllUsersToFile();
}

void UserManager::saveAllUsersToFile()
{
	fileWithUsers.saveAllUsersToFile(users);
}
