#pragma once
#include <iostream>
#include "clsUser.h";
#include "clsScreen.h";
#include "clsInputValidate.h";
class clsFindUserScreen :protected clsScreen{
private:
    static void _PrintUser(clsUser& User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }


public:
    static void ShowFindUserScreen() {

        _DrawScreenHeader("\tFind User Screen");
        string UserName = "";
        cout << "Please Enter User UserName: " << endl;
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName)) {

            cout << "UserName is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();

        }
        clsUser User = clsUser::Find(UserName);




        if (!User.IsEmpty()) {
            cout << "\nUser Found :-) " << endl;


        }
        else {
            cout << "\nUser Was not found :-(\n";
        }

        _PrintUser(User);

    }



};

