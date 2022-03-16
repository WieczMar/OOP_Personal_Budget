#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
    int id;
    string login;
    string password;
    string firstName;
    string secondName;

public:
    User (int id=0, string login="", string password="", string firstName="", string secondName="")
    {
        this->id = id;
        this->login = login;
        this->password = password;
        this->firstName = firstName;
        this->secondName = secondName;
    }
    void setId(int newId);
    void setLogin(string newLogin);
    void setPassword(string newPassword);
    void setFirstName(string newFirstName);
    void setSecondName(string newSecondName);

    int getId();
    string getLogin();
    string getPassword();
    string getFirstName();
    string getSecondName();
};

#endif
