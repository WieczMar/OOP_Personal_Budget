#include "Expense.h"

void Expense::setExpenseId(int newExpenseId)
{
    if(newExpenseId >= 0)
	expenseId = newExpenseId;
}

void Expense::setUserId(int newUserId)
{
    if(newUserId >= 0)
    userId = newUserId;
}

void Expense::setDate(int newDate)
{
	date = newDate;
}

void Expense::setItem(string newItem)
{
	item = newItem;
}

void Expense::setAmount(float newAmount)
{
	amount = newAmount;
}

int Expense::getExpenseId()
{
	return expenseId;
}

int Expense::getUserId()
{
    return userId;
}

int Expense::getDate()
{
	return date;
}

string Expense::getItem()
{
	return item;
}

float Expense::getAmount()
{
	return amount;
}
