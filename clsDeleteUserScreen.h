#pragma once
#include <iostream>
#include "clsPerson.h";
#include "clsUser.h";
#include "clsScreen.h";
#include "clsInputValidate.h";
class clsDeleteUserScreen : protected clsScreen{

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

    static void ShowDeleteUserScreen() {

        _DrawScreenHeader("\tDelete User Screen");
        string UserName = "";
        cout << "Please Enter User Name: " << endl;
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName)) {

            cout << "UserName is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();

        }
        clsUser User = clsUser::Find(UserName);

        _PrintUser(User);
        char ans = 'n';
        cout << "\nAre you sure you want to delete this User y/n? ";
        cin >> ans;

        if (ans == 'y' || ans == 'Y') {

            if (User.Delete()) {
                cout << "\nUser Deleted Successfully :-) " << endl;
                _PrintUser(User);

            }
            else {
                cout << "\nError User was not Deleted\n";
            }


        }

    }

};

