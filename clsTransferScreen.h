#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsBankClient.h";
#include "clsInputValidate.h";
#include "Global.h";
class clsTransferScreen : protected clsScreen{


private:

	static void _PrintClient(clsBankClient Client) {
		cout << "\nClient Card:";
		cout << "\n-----------------\n";
		cout << "\nFull Name    : " << Client.FullName();
		cout << "\nAcc. Number  : " << Client.AccountNumber();
		cout << "\nBalance      : " << Client.AccountBalance;
		cout << "\n-----------------\n";

	}

	static string _ReadAccountNumber(string Message) {
		string AccountNumber = "";
		cout << "\n" << Message;
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nAccount Number is not found,choose another Account Number: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}

	static float _ReadAmount(clsBankClient SourceClient) {
		float Amount = 0;
		cout << "\nEnter Transfer Amount? ";
		Amount = clsInputValidate::ReadNumber<float>();

		while (Amount>SourceClient.AccountBalance) {
			cout << "\nAmount Exceeds the available Balance, Enter another Amount? ";
			Amount = clsInputValidate::ReadNumber<float>();

		}

		return Amount;


	}
public:

	static void ShowTransferScreen() {
		_DrawScreenHeader("\t Transfer Screen");

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("\nPlease Enter Account Number to Transfer From: "));

		_PrintClient(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("\nPlease Enter Account Number to Transfer To: "));

		_PrintClient(DestinationClient);
		
		float Amount = _ReadAmount(SourceClient);
			char answer = 'n';
			cout << "\nAre you sure you want to perform this operation? y/n? ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y') {
				
				if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName)) {
					cout << "\nTransfer Done Sccessfully" << endl;
				}
				else {
					cout << "\nTransfer Faild\n";
				}
				
		}
			_PrintClient(SourceClient);
			_PrintClient(DestinationClient);


	}






};

