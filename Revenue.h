#ifndef REVENUE_H
#define REVENUE_H
#include <iostream>

using namespace std;

class Revenue
{
	int revenueId = 0;
	int userId = 0;
	int date = 0;
	string item = "";
	float amount = 0.0;

public:
	void setRevenueId(int newRevenueId);
	void setUserId(int newUserId);
	void setDate(int newDate);
	void setItem(string newItem);
	void setAmount(float newAmount);

	int getRevenueId();
	int getUserId();
	int getDate();
	string getItem();
	float getAmount();
};

#endif
