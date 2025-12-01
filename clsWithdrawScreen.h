#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsBankClient.h";
#include "clsInputValidate.h";
class clsWithdrawScreen : protected clsScreen{

private:
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

    static string _ReadAccountNumber() {
        string AccountNumber = "";
        cout << "Please Enter AccountNumber? ";
        cin >> AccountNumber;
        return AccountNumber;
    }


public:

    static void ShowWithdrawScreen() {

        _DrawScreenHeader("\t   Withdraw Screen");
        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber)) {

            cout << "Client with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _ReadAccountNumber();

        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);


        double Amount = 0;
        cout << "\nPlease Enter Withdraw amount? ";
        Amount = clsInputValidate::ReadNumber<double>();

        char answer = 'n';
        cout << "Are you sure you want to perform this transaction? y/n? ";
        cin >> answer;

        if (answer == 'y' || answer == 'Y') {

         
            if (Client.Withdraw(Amount)) {

                cout << "\nAmount Withdraw Successfully.\n";
                cout << "\nNew Balance Is: " << Client.AccountBalance << endl;
            }
            else {
                cout << "\nCannot Withdraw, Insuffecient Balance!" << endl;
                cout << "\nAmount To Withdraw is: " << Amount;
                cout << "\nNew Balance Is: " << Client.AccountBalance << endl;
            }

        }
        else {
            cout << "\nOperation was cancelled.\n";
        }
    }





};

