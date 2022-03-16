#include "FileWithExpenses.h"

void FileWithExpenses::appendExpenseToFile(Expense expense)
{
	CMarkup xml;

	bool fileExists = xml.Load(getFileName());
	int dateNumber = expense.getDate();
	string date = AuxiliaryMethods::convertDateIntToString(dateNumber);

	string amount = AuxiliaryMethods::convertFloatToString(expense.getAmount());

	if(!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
		xml.AddElem("Expenses");
	}

	xml.FindElem();
	xml.IntoElem();
	xml.AddElem("Expense");
	xml.IntoElem();
	xml.AddElem("ExpenseId", expense.getExpenseId());
	xml.AddElem("UserId", expense.getUserId());
	xml.AddElem("Date", date);
	xml.AddElem("Item", expense.getItem());
	xml.AddElem("Amount", amount);
	lastExpenseId++;

	xml.Save(getFileName());
}

vector<Expense> FileWithExpenses::loadExpensesFromFile(int loggedInUserId)
{
	CMarkup xml;
	Expense expense;
	vector <Expense> expenses;

	xml.Load(getFileName());

	xml.FindElem();
	xml.IntoElem();
	while (xml.FindElem("Expense")) {
		xml.IntoElem();

		xml.FindElem("ExpenseId");
		MCD_STR strSN = xml.GetData();
		expense.setExpenseId(AuxiliaryMethods::convertStringToInt(strSN));
		xml.FindElem("UserId");
		strSN = xml.GetData();
		expense.setUserId(AuxiliaryMethods::convertStringToInt(strSN));

		xml.FindElem("Date");
		strSN = xml.GetData();
		strSN.erase(4, 1);
		strSN.erase(6, 1);
		expense.setDate(AuxiliaryMethods::convertStringToInt(strSN));

		xml.FindElem("Item");
		strSN = xml.GetData();
		expense.setItem(strSN);

		xml.FindElem("Amount");
		strSN = xml.GetData();
		expense.setAmount(AuxiliaryMethods::convertStringToFloat(strSN));
		xml.OutOfElem();

		lastExpenseId++;
		if(loggedInUserId == expense.getUserId())
			expenses.push_back(expense);
	}

	return expenses;
}

int FileWithExpenses::getLastExpenseId()
{
	return lastExpenseId;
}
