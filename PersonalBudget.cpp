#include "PersonalBudget.h"

char PersonalBudget::chooseMainMenuOption()
{
    char choice;

	system("cls");
	cout << "       MAIN  MENU        " << endl;
	cout << "-------------------------" << endl;
	cout << "1. Registration          " << endl;
	cout << "2. Log in                " << endl;
	cout << "9. Exit program          " << endl;
	cout << "-------------------------" << endl;
	cout << "Your choice: ";
	choice = AuxiliaryMethods::enterChar();

	return choice;
}

char PersonalBudget::chooseUserMenuOption()
{
	return userManager.chooseUserMenuOption();
}

void PersonalBudget::registerUser()
{
	userManager.registerUser();
}

void PersonalBudget::loginUser()
{
	userManager.loginUser();

	if(userManager.isUserLoggedIn())
	{
		budgetManager = new BudgetManager(FILE_NAME_WITH_REVENUES, FILE_NAME_WITH_EXPENSES, userManager.getLoggedInUserId());
	}
}

void PersonalBudget::logoutUser()
{
	userManager.logoutUser();
	delete budgetManager;
	budgetManager = NULL;
}

void PersonalBudget::changePassword()
{
	userManager.changePassword();
}

bool PersonalBudget::isUserLoggedIn()
{
	return userManager.isUserLoggedIn();
}

void PersonalBudget::addRevenue()
{
	if(isUserLoggedIn())
    {
		budgetManager->addRevenue();
	}
	else
	{
		cout << "You have to login to add revenue." << endl;
		system("pause");
	}
}

void PersonalBudget::addExpense()
{
	if(isUserLoggedIn())
    {
		budgetManager->addExpense();
	}
	else
        {
		cout << "You have to login to add expense." << endl;
		system("pause");
	}
}

void PersonalBudget::displayCurrentMonthBalance()
{
	budgetManager->displayCurrentMonthBalance();
}

void PersonalBudget::displayPreviousMonthBalance()
{
	budgetManager->displayPreviousMonthBalance();
}

void PersonalBudget::displayChosenPeriodBalance()
{
	budgetManager->displayChosenPeriodBalance();
}
