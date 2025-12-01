#pragma once
#include <iostream>
#include "clsUser.h";
#include "clsScreen.h";
#include "clsInputValidate.h";
class clsAddNewUserScreen : protected clsScreen {

private :
    static void _ReadUserInfo(clsUser & User) {

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

    static void _PrintUser(clsUser & User)
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
	static void ShowAddNewUserScreen() {

		_DrawScreenHeader("\t  Add New User Screen");
		string UserName = "";
		cout << "Please Enter UserName: ";
		UserName = clsInputValidate::ReadString();

		while (clsUser::IsUserExist(UserName)) {
			cout << "UserName is Already used, Choose another one: ";
			UserName = clsInputValidate::ReadString();


		}

		clsUser User = clsUser::GetAddNewUserObject(UserName);
        _ReadUserInfo(User);
		
        clsUser::enSaveResults SaveResult;
        SaveResult = User.Save();

        switch (SaveResult) {
          case  clsUser::enSaveResults::svSucceeded :{
              cout << "\nUser Addeded Successfully :-)\n";
              _PrintUser(User);
              break;
            }
          case  clsUser::enSaveResults::svFaildEmptyObject: {
              cout << "\nError User was not saved because it's Empty";
           
              break;
          }
          case  clsUser::enSaveResults::svFaildUserExist: {
              cout << "\nError User was not saved because Username is used!\n";

              break;
          }
       
        }

	}



};

