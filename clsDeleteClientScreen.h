#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsBankClient.h";
#include "clsInputValidate.h";
#include "clsPerson.h";

using namespace std;
class clsDeleteClientScreen : protected clsScreen{

private :

    static void _PrintClient(clsBankClient & Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName : " << Client.GetFirstName();
        cout << "\nLastName  : " << Client.GetLastName();
        cout << "\nFull Name : " << Client.FullName();
        cout << "\nEmail     : " << Client.GetEmail();
        cout << "\nPhone     : " << Client.GetPhone();
        cout << "\nAcc.Number: " << Client.AccountNumber();
        cout << "\nPassword  : " << Client.PinCode;
        cout << "\nBalance   : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }



public:

    static void ShowDeleteClientScreen() {

        if (!CheckAccessRights(clsUser::pDeleteClient)) {
            return;
        }

        _DrawScreenHeader("\tDelete Client Screen");
        string AccountNumber = "";
        cout << "Please Enter client Account Number: " << endl;
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber)) {

            cout << "Account Number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();

        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);

        _PrintClient(Client);
        char ans = 'n';
        cout << "\nAre you sure you want to delete this client y/n? ";
        cin >> ans;

        if (ans == 'y' || ans == 'Y') {

            if (Client.Delete()) {
                cout << "\nClient Deleted Successfully :-) " << endl;
                _PrintClient(Client);

            }
            else {
                cout << "\nError Client was not Deleted\n";
            }


        }

    }






};

