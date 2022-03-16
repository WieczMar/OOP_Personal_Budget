#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H
#include <iostream>

#include "UserManager.h"
#include "BudgetManager.h"

using namespace std;

class PersonalBudget
{
	UserManager userManager;
	BudgetManager* budgetManager;
	const string FILE_NAME_WITH_REVENUES;
	const string FILE_NAME_WITH_EXPENSES;
public:
	PersonalBudget(string fileNameWithUsers, string fileNameWithRevenues, string fileNameWithExpenses) :
		userManager(fileNameWithUsers), FILE_NAME_WITH_REVENUES(fileNameWithRevenues), FILE_NAME_WITH_EXPENSES(fileNameWithExpenses)
	{
		budgetManager = NULL;
	};
	~PersonalBudget()
	{
		delete budgetManager;
		budgetManager = NULL;
	}

	char chooseMainMenuOption();
	char chooseUserMenuOption();
	void registerUser();
	void loginUser();
	void addRevenue();
	void addExpense();
	void displayCurrentMonthBalance();
	void displayPreviousMonthBalance();
	void displayChosenPeriodBalance();
	void changePassword();
	void logoutUser();
    bool isUserLoggedIn();
};

#endif
