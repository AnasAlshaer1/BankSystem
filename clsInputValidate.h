#pragma once
#include <iostream>
#include <string>
#include "clsDate.h";
#include "clsString.h";
using namespace std;

class clsInputValidate {


public:

	template <typename T> static bool IsNumberbetween(T Number, T From, T To) {
		if(Number>=From&&Number<=To)
				return true;
		else
		return false;

	}

	template <typename T>static T ReadNumber(string ErrorMessage = "Invalid Number, Enter again\n") {
		
		T Number = 0;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n');

			cout << ErrorMessage << endl;
		}


		return Number;
	}
	
	template <typename T>static T ReadNumberBetween(T From, T To, string ErrorMessage="Number is not within range, Enter again:\n") {
		T Number = 0;
		Number = ReadNumber<int>();
		while (!IsNumberbetween(Number,From,To)) {
			cout << ErrorMessage << endl;
			Number = ReadNumber<int>();


		}
		return Number;

	}

	static bool IsValidDate(clsDate Date) {

		return clsDate::IsValidDate(Date);

	}

	static string ReadString() {
		string S1 = "";
		getline(cin>>ws, S1);

		return S1;
	}

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		//Date>=From && Date<=To
		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			&&
			(clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			)
		{
			return true;
		}

		//Date>=To && Date<=From
		if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			&&
			(clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			)
		{
			return true;
		}

		return false;
	}


};

