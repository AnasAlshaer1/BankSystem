#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsPerson.h";
#include "clsBankClient.h";
#include "clsInputValidate.h";

using namespace std;
class clsUpdateClientScreen:protected clsScreen{


private:
    static void _ReadClientInfo(clsBankClient& Client) {

        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::ReadString();
        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate::ReadString();
        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::ReadString();
        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::ReadString();
        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();
        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadNumber<float>();


    }

    static void _PrintClient(clsBankClient& Client)
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
    static void ShowUpdateClientScreen() {

        if (!CheckAccessRights(clsUser::pUpdateClients)) {
            return;
        }

        _DrawScreenHeader("\tUpdate Client Screen");

        string AccountNumber = "";
        cout << "Please Enter client Account Number: " << endl;
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber)) {

            cout << "Account Number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();

        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);

        _PrintClient(Client);

        cout << "\nUpdate Client Info:" << endl;
        cout << "\n___________________" << endl;

        char ans = 'n';
        cout << "\nAre you sure you want to update this client? y/n? ";
        cin >> ans;

        if (ans == 'y' || ans == 'Y') {


            _ReadClientInfo(Client);
            clsBankClient::enSaveResults SaveResult;

            SaveResult = Client.Save();

            switch (SaveResult) {

            case clsBankClient::enSaveResults::svSucceeded: {
                cout << "\nAccount Updated Successfully :-)";
                _PrintClient(Client);
                break;

            }
            case clsBankClient::enSaveResults::svFaildEmptyObject: {
                cout << "\nError Account was not saved because it's Empty";
                break;
            }


            }

        }
    }


};

