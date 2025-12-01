#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsPerson.h";
#include "clsBankClient.h";
#include "clsInputValidate.h";

using namespace std;
class clsFindClientScreen : protected clsScreen{
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


public:
    static void ShowFindClientScreen() {
        if (!CheckAccessRights(clsUser::pFindClient)) {
            return;
        }


        _DrawScreenHeader("\tFind Client Screen");
        string AccountNumber = "";
        cout << "Please Enter client Account Number: " << endl;
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber)) {

            cout << "Account Number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();

        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);

       
      

            if (!Client.IsEmpty()) {
                cout << "\nClient Found :-) " << endl;
               

            }
            else {
                cout << "\nError Was not found :-(\n";
            }

            _PrintClient(Client);

        }

    



};

