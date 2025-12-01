#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsCurrency.h";
class clsUpdateCurrencyScreen:protected clsScreen{

	static void _PrintCurrency(clsCurrency Currency) {
		cout << "\n\nCurrency Card:";
		cout << "\n-----------------------------";
		cout << "\n\nCountry      : " << Currency.Country();
		cout << "\nCode         : " << Currency.CurrencyCode();
		cout << "\nName         : " << Currency.CurrencyName();
		cout << "\nRate(1$)=    : " << Currency.Rate();
		cout << "\n-----------------------------";

	}

	static float _ReadRate() {
		cout << "\nEnter New Rate: ";
		float NewRate = 0;
		NewRate = clsInputValidate::ReadNumber < float > ();
		return NewRate;
	}


public:

	static void ShowUpdateCurrencyRateScreen() {
		_DrawScreenHeader("\t Update Currency Screen");

		cout << "Please Enter Currency Code: ";
		string CurrencyCode = "";
		CurrencyCode = clsInputValidate::ReadString();

	     
		while (!clsCurrency::IsCurrencyExist(CurrencyCode)) {
			cout << "\nCurrency is not found, Choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();

		}
		
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

			_PrintCurrency(Currency);
			char answer = 'n';
			cout << "\nAre you sure you want to update the rate of this Currency y/n? ";
			cin >> answer;

			if (answer == 'y' || answer == 'Y') {

				cout << "\n\nUpdate Currency Rate:";
				cout << "\n----------------------------\n";
			
				Currency.UpdateRate(_ReadRate());
				cout << "\nCurrency Rate Updated Successfully";
				_PrintCurrency(Currency);
			

		}





	}


};

