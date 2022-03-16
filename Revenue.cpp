#include "Revenue.h"

void Revenue::setRevenueId(int newRevenueId)
{
	if(newRevenueId >= 0)
		revenueId = newRevenueId;
}

void Revenue::setUserId(int newUserId)
{
    if(newUserId >= 0)
    userId = newUserId;
}

void Revenue::setDate(int newDate)
{
	date = newDate;
}

void Revenue::setItem(string newItem)
{
	item = newItem;
}

void Revenue::setAmount(float newAmount)
{
	amount = newAmount;
}

int Revenue::getRevenueId()
{
	return revenueId;
}

int Revenue::getUserId()
{
    return userId;
}

int Revenue::getDate()
{
	return date;
}

string Revenue::getItem()
{
	return item;
}

float Revenue::getAmount()
{
	return amount;
}
