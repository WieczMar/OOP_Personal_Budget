#include "FileWithRevenues.h"

void FileWithRevenues::appendRevenueToFile(Revenue revenue)
{
	CMarkup xml;

	bool fileExists = xml.Load(getFileName());
	int dateNumber = revenue.getDate();
	string date = AuxiliaryMethods::convertDateIntToString(dateNumber);

	string amount = AuxiliaryMethods::convertFloatToString(revenue.getAmount());

	if(!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
		xml.AddElem("Revenues");
	}

	xml.FindElem();
	xml.IntoElem();
	xml.AddElem("Revenue");
	xml.IntoElem();
	xml.AddElem("RevenueId", revenue.getRevenueId());
	xml.AddElem("UserId", revenue.getUserId());
	xml.AddElem("Date", date);
	xml.AddElem("Item", revenue.getItem());
	xml.AddElem("Amount", amount);
	lastRevenueId++;

	xml.Save(getFileName());
}

vector<Revenue> FileWithRevenues::loadRevenuesFromFile(int loggedInUserId)
{
	CMarkup xml;
	Revenue revenue;
	vector <Revenue> revenues;

	xml.Load(getFileName());

	xml.FindElem();
	xml.IntoElem();
	while (xml.FindElem("Revenue")) {
		xml.IntoElem();

		xml.FindElem("RevenueId");
		MCD_STR strSN = xml.GetData();
		revenue.setRevenueId(AuxiliaryMethods::convertStringToInt(strSN));
		xml.FindElem("UserId");
		strSN = xml.GetData();
		revenue.setUserId(AuxiliaryMethods::convertStringToInt(strSN));

		xml.FindElem("Date");
		strSN = xml.GetData();
		strSN.erase(4, 1);
		strSN.erase(6, 1);
		revenue.setDate(AuxiliaryMethods::convertStringToInt(strSN));

		xml.FindElem("Item");
		strSN = xml.GetData();
		revenue.setItem(strSN);

		xml.FindElem("Amount");
		strSN = xml.GetData();
		revenue.setAmount(AuxiliaryMethods::convertStringToFloat(strSN));
		xml.OutOfElem();

		lastRevenueId++;
		if(loggedInUserId == revenue.getUserId())
			revenues.push_back(revenue);
	}

	return revenues;
}

int FileWithRevenues::getLastRevenueId()
{
	return lastRevenueId;
}
