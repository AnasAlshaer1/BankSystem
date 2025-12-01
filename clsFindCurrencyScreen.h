#pragma once
#include <iostream>
#include "clsScreen.h";
#include <vector >
#include "clsInputValidate.h";
#include "clsCurrency.h";
using namespace std;
class clsFindCurrencyScreen:protected clsScreen{


private:

	static void _PrintCurrency(clsCurrency Currency) {
		cout << "\n\nCurrency Card:";
		cout << "\n-----------------------------";
		cout << "\n\nCountry      : " << Currency.Country();
		cout << "\nCode         : " << Currency.CurrencyCode();
		cout << "\nName         : " << Currency.CurrencyName();
		cout << "\nRate(1$)=    : " << Currency.Rate();
		cout << "\n-----------------------------";

	}

	static string _ReadCurrencyCode() {
		string CurrencyCode="";
		cout << "\nPlease Enter Currency Code: ";
		CurrencyCode = clsInputValidate::ReadString();
		return CurrencyCode;

	}
	
	static string _ReadCountry() {
		string Counrtry = "";
		cout << "\nPlease Enter Country Name: ";

		Counrtry = clsInputValidate::ReadString();
		return Counrtry;

	}

	static void _ShowResults(clsCurrency Currency) {
		if (!Currency.IsEmpty()) {
			cout << "\nCurrency Found :-)\n";
			_PrintCurrency(Currency);

		}
		else {
			cout << "\nCurrency Was not Found :-(\n";
		}
	}


public:

	static void ShowFindCurrencyScreen() {
		
		_DrawScreenHeader("\t  Find Currency Screen");
		short Answer=0;
		cout << "Find By: [1] Code or [2] Country ? ";
		cin >> Answer;

		if (Answer == 1) {
			string CourrencyCode = "";
			cout << "\nPlease Enter CurrencyCode: ";
			CourrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CourrencyCode);
			_ShowResults(Currency);
			
		
		}

		else{
			string Country = "";
			cout << "\nPlease Enter Country Name: ";
			Country = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			_ShowResults(Currency);





		}
		
	}



};

