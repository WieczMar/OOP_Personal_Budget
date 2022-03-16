#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <vector>
#include <cstdlib>
#include "File.h"
#include "User.h"
#include "AuxiliaryMethods.h"
#include "Markup.h"

using namespace std;

class FileWithUsers : public File
{

public:
    FileWithUsers(string fileName) : File(fileName) {};
    void appendUserToFile(User user);
    vector <User> loadUsersFromFile();
    void saveAllUsersToFile(vector <User> users);
};

#endif
