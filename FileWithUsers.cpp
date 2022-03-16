#include "FileWithUsers.h"

void FileWithUsers::appendUserToFile(User user)
{
    CMarkup xml;

    bool fileExists = xml.Load(getFileName());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("Id", AuxiliaryMethods::convertIntToString(user.getId()));
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("FirstName", user.getFirstName());
    xml.AddElem("SecondName", user.getSecondName());

    xml.Save(getFileName());
}

vector <User> FileWithUsers::loadUsersFromFile()
{
    CMarkup xml;
    User user;
    vector <User> users;

    bool fileExists = xml.Load(getFileName());

    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("User"))
    {
        xml.IntoElem();

        xml.FindElem("Id");
        MCD_STR strSN = xml.GetData();
        user.setId(AuxiliaryMethods::convertStringToInt(strSN));

        xml.FindElem("Login");
        strSN = xml.GetData();
        user.setLogin(strSN);

        xml.FindElem("Password");
        strSN = xml.GetData();
        user.setPassword(strSN);

        xml.FindElem("FirstName");
        strSN = xml.GetData();
        user.setFirstName(strSN);

        xml.FindElem("SecondName");
        strSN = xml.GetData();
        user.setSecondName(strSN);
        xml.OutOfElem();

        users.push_back(user);
    }

    return users;
}

void FileWithUsers::saveAllUsersToFile(vector <User> users)
{
    CMarkup xml;

    xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    xml.AddElem("Users");

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        xml.FindElem();
        xml.IntoElem();
        xml.AddElem("User");
        xml.IntoElem();
        xml.AddElem("Id", AuxiliaryMethods::convertIntToString(itr->getId()));
        xml.AddElem("Login", itr->getLogin());
        xml.AddElem("Password", itr->getPassword());
        xml.AddElem("FirstName", itr->getFirstName());
        xml.AddElem("SecondName", itr->getSecondName());
        xml.OutOfElem();
        xml.OutOfElem();
    }
        xml.Save(getFileName());
}




