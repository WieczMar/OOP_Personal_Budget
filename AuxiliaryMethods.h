#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods
{
public:
    static char enterChar();
    static string enterLine();
    static int enterInt();
    static string convertIntToString(int number);
    static int convertStringToInt(string number);
    static string convertDateIntToString(int dateNumber);
    static string convertFloatToString(float number);
    static float convertStringToFloat(string number);
    static bool isDigit(char sign);

};

#endif
