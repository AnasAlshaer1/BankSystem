#pragma once
#include "clsScreen.h";
#include <iostream>
#include "clsInputValidate.h";
#include "clsCurrency.h";
class clsCurrencyCalculatorScreen : protected clsScreen {

private:
	static void _PrintCurrencyCard(clsCurrency Currency,string Title="Currency Card") {
		cout << "\n"<<Title<<"\n";
		cout << "-----------------------------";
		cout << "\n\nCountry      : " << Currency.Country();
		cout << "\nCode         : " << Currency.CurrencyCode();
		cout << "\nName         : " << Currency.CurrencyName();
		cout << "\nRate(1$)=    : " << Currency.Rate();
		cout << "\n-----------------------------\n\n";

	}

	static float _ReadAmount() {
		float Amount = 0;
		cout << "\nEnter Amount to Exchange: ";
		Amount = clsInputValidate::ReadNumber<float>();
		return Amount;
	}

	static clsCurrency _GetCurrency(string Message) {
		string CurrencyCode = "";
		cout << Message;
		CurrencyCode = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist(CurrencyCode)) {
			cout << "\nCurrency code is not found, Choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		return Currency;
	}

	static void _PrintCalaculationsResults(float Amount,clsCurrency Currency1,clsCurrency Currency2){
		_PrintCurrencyCard(Currency1, "Convert From:");

		float AmountInUSD = Currency1.ConvertToUSD(Amount);

		cout << Amount << " " << Currency1.CurrencyCode() << " = " << AmountInUSD << " USD\n";
	
		if (Currency2.CurrencyCode() == "USD") {
			return;
		}
		_PrintCurrencyCard(Currency2,"To:");
		float AmountInCurrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);

		cout << Amount << " " << Currency1.CurrencyCode() << " = " << AmountInCurrency2 <<
			" " << Currency2.CurrencyCode();

	}

public:
	static void ShowCurrencyCalaculatorScreen() {
		char Continue = 'y';
	
		while(Continue == 'y' || Continue == 'Y') {
				system("cls");
			
		
		_DrawScreenHeader("\t Currency Calcluator Screen");

			clsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency1 Code: ");
			clsCurrency CurrencyTo = _GetCurrency("\nPlease Enter Currency2 Code: ");
			float Amount = _ReadAmount();


			_PrintCalaculationsResults(Amount, CurrencyFrom, CurrencyTo);

			
			cout << "\n\nDo you want to perform another calculation? y/n? ";
			cin >> Continue;



		} 
	}


};

