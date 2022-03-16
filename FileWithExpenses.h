#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H
#include <iostream>
#include <vector>
#include <sstream>

#include "Expense.h"
#include "Markup.h"
#include "File.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithExpenses: File
{
	int lastExpenseId;

public:
	FileWithExpenses(string fileNameWithExpenses) : File(fileNameWithExpenses)
	{
	    lastExpenseId = 0;
	};

	void appendExpenseToFile(Expense expense);
	vector <Expense> loadExpensesFromFile(int loggedInUserId);
	int getLastExpenseId();
};

#endif
