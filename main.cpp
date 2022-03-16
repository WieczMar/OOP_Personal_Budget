#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget("Users.xml", "Revenues.xml", "Expenses.xml");
    char choice;

    while (true)
    {
        if (!personalBudget.isUserLoggedIn())
        {
            choice = personalBudget.chooseMainMenuOption();

            switch (choice)
            {
            case '1':
                personalBudget.registerUser();
                break;
            case '2':
                personalBudget.loginUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "There is no such option in Menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = personalBudget.chooseUserMenuOption();

            switch (choice)
            {
            case '1':
                personalBudget.addRevenue();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.displayCurrentMonthBalance();
                break;
            case '4':
                personalBudget.displayPreviousMonthBalance();
                break;
            case '5':
                personalBudget.displayChosenPeriodBalance();
                break;
            case '6':
                personalBudget.changePassword();
                break;
            case '9':
                personalBudget.logoutUser();
                break;
            default:
                cout << endl << "There is no such option in Menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}
