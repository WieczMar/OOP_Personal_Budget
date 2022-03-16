#ifndef FILEWITHREVENUES_H
#define FILEWITHREVENUES_H
#include <iostream>
#include <vector>

#include "Revenue.h"
#include "Markup.h"
#include "File.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithRevenues: File
{
	int lastRevenueId;

public:
	FileWithRevenues(string fileNameWithRevenues) : File(fileNameWithRevenues)
	{
		lastRevenueId = 0;
	};

	void appendRevenueToFile(Revenue revenue);
	vector <Revenue> loadRevenuesFromFile(int idLoggedUser);
	int getLastRevenueId();
};

#endif
