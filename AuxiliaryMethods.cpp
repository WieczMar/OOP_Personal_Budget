#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int AuxiliaryMethods::convertStringToInt(string numberString)
{
    int numberInt;
    istringstream iss(numberString);
    iss >> numberInt;

    return numberInt;
}

string AuxiliaryMethods::convertFloatToString(float number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

float AuxiliaryMethods::convertStringToFloat(string number)
{
	float floatNumber;
	istringstream fss(number);
	fss >> floatNumber;
	return floatNumber;
}

string AuxiliaryMethods::convertDateIntToString(int dateNumber)
{
    string hyphen = "-";
	ostringstream ss;
	ss << dateNumber;
	string str = ss.str();
	str.insert(4, hyphen);
	str.insert(7, hyphen);

	return str;
}

char AuxiliaryMethods::enterChar()
{
    string entry = "";
    char character  = {0};

    while (true)
    {
        getline(cin, entry);

        if (entry.length() == 1)
        {
            character = entry[0];
            break;
        }
        cout << "It is not a single character. Type again." << endl;
    }
    return character;
}

string AuxiliaryMethods::enterLine()
{
    string entry = "";
    getline(cin, entry);
    return entry;
}

int AuxiliaryMethods::enterInt()
{
    string entry = "";
    int number = 0;

    while (true)
    {
        getline(cin, entry);

        stringstream myStream(entry);
        if (myStream >> number)
            break;
        cout << "It is not a integer. Type again. " << endl;
    }
    return number;
}

bool AuxiliaryMethods::isDigit(char sign)
{
    return (sign >= '0' && sign <= '9');
}
