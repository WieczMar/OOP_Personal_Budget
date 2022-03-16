#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H
#include <iostream>
#include <vector>
#include <time.h>
#include <string>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;
#include "Revenue.h"
#include "Expense.h"
#include "UserManager.h"
#include "FileWithRevenues.h"
#include "FileWithExpenses.h"
#include "AuxiliaryMethods.h"

class BudgetManager
{
	const int LOGGED_IN_USER_ID;
	vector<Revenue> revenues;
	vector<Expense> expenses;
    FileWithRevenues fileWithRevenues;
	FileWithExpenses fileWithExpenses;

    Revenue enterNewRevenueData();
	Expense enterNewExpenseData();
    int getCurrentDate();
	int enterDate();
	void displayRevenuesAndExpenses(int startDate, int endDate);
	void displayRevenue(Revenue revenue);
	void displayExpense(Expense expense);
	bool isLeapYear(int year);
	string changeCommaToDot(string amount);
	bool checkIfDateIsInCorrectFormat(string date);

	vector<Revenue> sortRevenuesByDate(vector<Revenue> revenues);
	vector<Expense> sortExpensesByDate(vector<Expense> expenses);
	static bool compareRevenuesDates(Revenue firstRevenue, Revenue secondRevenue);
	static bool compareExpensesDates(Expense firstExpense, Expense secondExpense);

public:
	BudgetManager(string fileNameWithRevenues, string fileNameWithExpenses, int loggedInUserId) :
		fileWithRevenues(fileNameWithRevenues), fileWithExpenses(fileNameWithExpenses), LOGGED_IN_USER_ID(loggedInUserId)
	{
		revenues = fileWithRevenues.loadRevenuesFromFile(LOGGED_IN_USER_ID);
		expenses = fileWithExpenses.loadExpensesFromFile(LOGGED_IN_USER_ID);
	};

	void addRevenue();
	void addExpense();
	void displayCurrentMonthBalance();
	void displayPreviousMonthBalance();
	void displayChosenPeriodBalance();
};

#endif
