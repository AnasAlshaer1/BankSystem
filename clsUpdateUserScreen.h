#pragma once
#include <iostream>
#include "clsUser.h";
#include "clsScreen.h";
#include "clsInputValidate.h";
class clsUpdateUserScreen: protected clsScreen{

private:
    static void _ReadUserInfo(clsUser& User) {

        cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidate::ReadString();
        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidate::ReadString();
        cout << "\nEnter Email: ";
        User.Email = clsInputValidate::ReadString();
        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate::ReadString();
        cout << "\nEnter Password: ";
        User.Password = clsInputValidate::ReadString();
        cout << "\nEnter Permission: ";
        User.Permissions = _ReadPermissionsToSet();


    }

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

    static int _ReadPermissionsToSet() {
        int Permissions = 0;
        char answer = 'n';

        cout << "\nDo you want to give full access? y/n? ";
        cin >> answer;

        if (answer == 'y' || answer == 'Y') {

            return -1;
        }

        cout << "\nDo you want to give access to : " << endl;

        cout << "\nShow Client List? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {

            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client ? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {

            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client ? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {

            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client ? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {

            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client ? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {

            Permissions += clsUser::enPermissions::pFindClient;
        }
        cout << "\nTransactions ? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {

            Permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users  ? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {

            Permissions += clsUser::enPermissions::pManageUsers;
        }
        cout << "\nShow Login Register? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {

            Permissions += clsUser::enPermissions::pShowLogInRegister;
        }

        return Permissions;

    }

public:
    static void ShowUpdateUserScreen() {

        _DrawScreenHeader("\tUpdate User Screen");

        string UserName = "";
        cout << "Please Enter User UserName: " << endl;
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName)) {

            cout << "UserName is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();

        }
        clsUser User = clsUser::Find(UserName);

        _PrintUser(User);

        cout << "\nUpdate User Info:" << endl;
        cout << "\n___________________" << endl;

        char ans = 'n';
        cout << "\nAre you sure you want to update this User? y/n? ";
        cin >> ans;

        if (ans == 'y' || ans == 'Y') {


            _ReadUserInfo(User);
            clsUser::enSaveResults SaveResult;

            SaveResult = User.Save();

            switch (SaveResult) {

            case clsUser::enSaveResults::svSucceeded: {
                cout << "\nUser Updated Successfully :-)";
                _PrintUser(User);
                break;

            }
            case clsUser::enSaveResults::svFaildEmptyObject: {
                cout << "\nError User was not saved because it's Empty";
                break;
            }


            }

        }
    }



};

