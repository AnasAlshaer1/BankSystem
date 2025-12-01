#pragma once
#include <iostream>
#include "clsScreen.h";
#include <iomanip>
#include "clsInputValidate.h";
#include "clsBankClient.h";

using namespace std;
class clsAddNewClientScreen : protected clsScreen{
private :
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
	static void ShowAddNewClientScreen() {

        if (!CheckAccessRights(clsUser::pAddNewClient)) {
            return;
        }

        _DrawScreenHeader("Add New Client Screen");
        string AccountNumber = "";
        cout << "Please Enter client Account Number: " << endl;
        AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClientExist(AccountNumber)) {

            cout << "Account Number is already exist, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();

        }
        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

        _ReadClientInfo(NewClient);
        clsBankClient::enSaveResults SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult) {

        case clsBankClient::enSaveResults::svSucceeded: {
            cout << "\nAccount Added Successfully :-)";
            _PrintClient(NewClient);
            break;

        }
        case clsBankClient::enSaveResults::svFaildEmptyObject: {
            cout << "\nError Account was not saved because it's Empty";
            break;
        }
        case clsBankClient::enSaveResults::svFaildAccountNumberExist: {
            cout << "\nError account wan not saved because account Number is user!\n";
            break;
        }

        }
        //what the hell are you talking about please let us know about it 
        //and if you have any idea about it just let me know about it

    }














};

