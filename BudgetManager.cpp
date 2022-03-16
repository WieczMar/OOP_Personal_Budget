#include "BudgetManager.h"

void BudgetManager::addRevenue()
{
    Revenue revenue = enterNewRevenueData();
    revenues.push_back(revenue);
    fileWithRevenues.appendRevenueToFile(revenue);

    cout << endl << "Your revenue has been added." << endl;
    system("pause");
}

void BudgetManager::addExpense()
{
    Expense expense = enterNewExpenseData();
    expenses.push_back(expense);
    fileWithExpenses.appendExpenseToFile(expense);

    cout << endl << "Your expense has been added." << endl;
    system("pause");
}

Revenue BudgetManager::enterNewRevenueData()
{
    Revenue revenue;
    int revenueId = 0, userId = 0, currentDate = 0;
    string item = "", enteredAmount = "";
    float amount = 0.0;

    cout << "          REVENUES MENU          " << endl;
    cout << "---------------------------------" << endl;
    cout << "1. Add revenue with today's date" << endl;
    cout << "2. Add revenue with another date" << endl;

    char choice = AuxiliaryMethods::enterChar();
    if (choice == '1')
    {
        currentDate = getCurrentDate();
    }
    else if (choice == '2')
    {
        currentDate = enterDate();
        cin.ignore();
    }

    cout << "Write revenue description : ";
    item = AuxiliaryMethods::enterLine();
    revenue.setItem(item);

    cout << "Write amount of the revenue: ";
    cin >> enteredAmount;
    cin.ignore();
    enteredAmount = changeCommaToDot(enteredAmount);
    amount = AuxiliaryMethods::convertStringToFloat(enteredAmount);

    revenue.setRevenueId(fileWithRevenues.getLastRevenueId() + 1);
    revenue.setUserId(LOGGED_IN_USER_ID);
    revenue.setDate(currentDate);
    revenue.setItem(item);
    revenue.setAmount(amount);

    return revenue;
}

Expense BudgetManager::enterNewExpenseData()
{
    Expense expense;
    int expenseId = 0, userId = 0, currentDate = 0;
    string item = "", enteredAmount = "";
    float amount = 0.0;

    cout << "           EXPENSES MENU         " << endl;
    cout << "---------------------------------" << endl;
    cout << "1. Add expense with today's date" << endl;
    cout << "2. Add expense with another date" << endl;

    char choice = AuxiliaryMethods::enterChar();
    if (choice == '1')
    {
        currentDate = getCurrentDate();
    }
    else if (choice == '2')
    {
        currentDate = enterDate();
        cin.ignore();
    }

    cout << "Write expense description : ";
    item = AuxiliaryMethods::enterLine();
    expense.setItem(item);

    cout << "Write amount of the expense: ";
    cin >> enteredAmount;
    cin.ignore();
    enteredAmount = changeCommaToDot(enteredAmount);
    amount = AuxiliaryMethods::convertStringToFloat(enteredAmount);

    expense.setExpenseId(fileWithExpenses.getLastExpenseId() + 1);
    expense.setUserId(LOGGED_IN_USER_ID);
    expense.setDate(currentDate);
    expense.setItem(item);
    expense.setAmount(amount);

    return expense;
}

void BudgetManager::displayCurrentMonthBalance()
{
    int currentDate = getCurrentDate();
    string startDateString, endDateString;
    int startDate, endDate;

    startDateString = AuxiliaryMethods::convertIntToString(currentDate);
    startDateString.replace(6, 2, "01");

    endDateString = startDateString;
    endDateString.replace(6, 2, "31");

    startDate = AuxiliaryMethods::convertStringToInt(startDateString);
    endDate = AuxiliaryMethods::convertStringToInt(endDateString);

    revenues = sortRevenuesByDate(revenues);
    expenses = sortExpensesByDate(expenses);
    displayRevenuesAndExpenses(startDate, endDate);
}

void BudgetManager::displayPreviousMonthBalance()
{
    string startDateString, endDateString, currentDateString, month;
    int startDate, endDate;

    int currentDate = getCurrentDate();
    currentDateString = AuxiliaryMethods::convertIntToString(currentDate);
    month = currentDateString.substr(4, 2);

    map<string, string> months;
    months = {
        {"01", "12"},
        {"02", "01"},
        {"03", "02"},
        {"04", "03"},
        {"05", "04"},
        {"06", "05"},
        {"07", "06"},
        {"08", "07"},
        {"09", "08"},
        {"10", "09"},
        {"11", "10"},
        {"12", "11"}
    };

    map<string, string>::iterator itr = months.find(month);
    if (itr != months.end())
        {
        month = itr->second;
    }

    startDateString = AuxiliaryMethods::convertIntToString(currentDate);
    startDateString.replace(4, 2, month);
    startDateString.replace(6, 2, "01");

    endDateString = startDateString;
    endDateString.replace(6, 2, "31");

    startDate = AuxiliaryMethods::convertStringToInt(startDateString);
    endDate = AuxiliaryMethods::convertStringToInt(endDateString);

    revenues = sortRevenuesByDate(revenues);
    expenses = sortExpensesByDate(expenses);
    displayRevenuesAndExpenses(startDate, endDate);
}

void BudgetManager::displayChosenPeriodBalance()
{
    int startDate, endDate;
    cout << "Enter start date and then enter end date in chosen period." << endl;
    startDate = enterDate();
    endDate = enterDate();
    cin.ignore();

    revenues = sortRevenuesByDate(revenues);
    expenses = sortExpensesByDate(expenses);

    cout << endl;
    displayRevenuesAndExpenses(startDate, endDate);
}

vector<Revenue> BudgetManager::sortRevenuesByDate(vector<Revenue> revenues)
{
	sort(revenues.begin(), revenues.end(), compareRevenuesDates);

	return revenues;
}

vector<Expense> BudgetManager::sortExpensesByDate(vector<Expense> expenses)
{
	sort(expenses.begin(), expenses.end(), compareExpensesDates);

	return expenses;
}

bool BudgetManager::compareRevenuesDates(Revenue firstRevenue, Revenue secondRevenue)
{
    return firstRevenue.getDate() > secondRevenue.getDate();
}

bool BudgetManager::compareExpensesDates(Expense firstExpense, Expense secondExpense)
{
    return firstExpense.getDate() > secondExpense.getDate();
}

void BudgetManager::displayRevenuesAndExpenses(int startDate, int endDate)
{
    float totalRevenue = 0.0, totalExpense = 0.0, balance = 0.0;

    if (!revenues.empty())
    {
        cout << "                                REVENUES                                    " << endl;
        cout << "----------------------------------------------------------------------------" << endl;
        for (vector<Revenue>::iterator itr = revenues.begin(); itr != revenues.end(); itr++)
        {
            if (itr->getDate() >= startDate && itr->getDate() <= endDate)
            {
                totalRevenue += itr->getAmount();
                displayRevenue(*itr);
            }
        }
        cout << endl;
    }
    else
    {
        cout << endl << " There is no revenues yet." << endl << endl;
    }

    if (!expenses.empty())
    {
        cout << "                                EXPENSES                                    " << endl;
        cout << "----------------------------------------------------------------------------" << endl;
        for (vector<Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            if (itr->getDate() >= startDate && itr->getDate() <= endDate)
            {
                totalExpense += itr->getAmount();
                displayExpense(*itr);
            }
        }
        cout << endl;
    }
    else
    {
        cout << endl << " There is no expenses yet." << endl << endl;
    }
    cout << "----------------------------------------------------------------------------" << endl;
    cout << " Total revenues in this period: " << fixed << setprecision(2) << totalRevenue << endl;
    cout << " Total expenses in this period: " << fixed << setprecision(2) << totalExpense << endl;
    balance = totalRevenue - totalExpense;
    cout << " Total balance in this period:  " << fixed << setprecision(2) << balance << endl << endl;
    system("pause");
}

int BudgetManager::getCurrentDate()
{
    time_t t;
    struct tm* ptr;
    time(&t);
    ptr = localtime(&t);
    string date = asctime(ptr);
    string year, month, day;
    year = date.substr(20, 4);
    month = date.substr(4, 3);
    day = date.substr(8, 2);

    map<string, string> months;
    months = {
        {"Jan", "01"},
        {"Feb", "02"},
        {"Mar", "03"},
        {"Apr", "04"},
        {"May", "05"},
        {"Jun", "06"},
        {"Jul", "07"},
        {"Aug", "08"},
        {"Sep", "09"},
        {"Oct", "10"},
        {"Nov", "11"},
        {"Dec", "12"}
    };

    map<string, string>::iterator itr = months.find(month);
    if (itr != months.end())
    {
        month = itr->second;
    }

    date = year + month + day;

    return AuxiliaryMethods::convertStringToInt(date);
}

int BudgetManager::enterDate()
{
    string enteredDate;
    int date;

    do {
        cout << "Write date since 2000 year in format rrrr-mm-dd: ";
        cin >> enteredDate;

        if (checkIfDateIsInCorrectFormat(enteredDate))
            break;
        else
            cout << "Wrong date format entered." << endl;

    } while (true);

    enteredDate.erase(4, 1);
    enteredDate.erase(6, 1);
    date = AuxiliaryMethods::convertStringToInt(enteredDate);

    return date;
}

void BudgetManager::displayRevenue(Revenue revenue)
{
    cout << " Date: " << AuxiliaryMethods::convertDateIntToString(revenue.getDate());
    cout << ";  Description: ";
    cout << left << setw(20);
    cout << revenue.getItem();
    cout << ";  Amount: " << fixed << setprecision(2) << revenue.getAmount() << endl;
}

void BudgetManager::displayExpense(Expense expense)
{
    cout << " Date: " << AuxiliaryMethods::convertDateIntToString(expense.getDate());
    cout << ";  Description: ";
    cout << left << setw(20);
    cout << expense.getItem();
    cout << ";  Amount: " << fixed << setprecision(2) << expense.getAmount() << endl;
}

bool BudgetManager::checkIfDateIsInCorrectFormat(string date)
{
    bool isDateInCorrectFormat = true;

    if(date.length() == 10 && date[4] == '-' && date[7] == '-')
    {
        date.erase(4, 1);
        date.erase(6, 1);

        for (int signPosition = 0; signPosition < 8; signPosition++)
        {
            if(!AuxiliaryMethods::isDigit(date[signPosition]))
            {
                isDateInCorrectFormat = false;
                return isDateInCorrectFormat;
            }
        }
    }
    else
    {
        isDateInCorrectFormat = false;
        return isDateInCorrectFormat;
    }

    int year, month, day;
    year = AuxiliaryMethods::convertStringToInt(date.substr(0, 4));
    month = AuxiliaryMethods::convertStringToInt(date.substr(4, 2));
    day = AuxiliaryMethods::convertStringToInt(date.substr(6, 2));

    map<int,int> numberOfDaysInMonth;
    numberOfDaysInMonth = {
        {1, 31},
        {3, 31},
        {4, 30},
        {5, 31},
        {6, 30},
        {7, 31},
        {8, 31},
        {9, 30},
        {10, 31},
        {11, 30},
        {12, 31}
    };
    if (isLeapYear(year))
        numberOfDaysInMonth[2]=29;
    else
        numberOfDaysInMonth[2]=28;

    if (day < 1 || day > numberOfDaysInMonth[month])
    {
        isDateInCorrectFormat = false;
    }
    else if ((year < 2000) || (month < 1) || (month > 12)) // Date should since 2000-01-01
    {
        isDateInCorrectFormat = false;
    }

    return isDateInCorrectFormat;
}

bool BudgetManager::isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

string BudgetManager::changeCommaToDot(string amount)
{
    string amountWithDot = "";

    for(int charPosition = 0; charPosition < amount.size(); charPosition++)
    {
        if (amount[charPosition] == ',')
        {
            amountWithDot += ".";
        }
        else
        {
            amountWithDot += amount[charPosition];
        }
    }
    return amountWithDot;
}
