#pragma once
#include <iostream>
#include <string>
#include "clsString.h";
#include <vector>
#include <fstream>
class clsCurrency {

private:
	enum enMode { EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;


	static clsCurrency  _ConvertLineToCurrencyObject(string Line, string Seperator = "#//#") {
		vector <string> vCurrency = clsString::Split(Line, Seperator);


		return clsCurrency(enMode::UpdateMode, vCurrency[0], vCurrency[1], vCurrency[2]
			, stod(vCurrency[3]));

	}

	static string _ConverCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
	{

		string stCurrencyRecord = "";
		stCurrencyRecord += Currency.Country() + Seperator;
		stCurrencyRecord += Currency.CurrencyCode() + Seperator;
		stCurrencyRecord += Currency.CurrencyName() + Seperator;
		stCurrencyRecord += to_string(Currency.Rate());

		return stCurrencyRecord;

	}


	static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrencies) {
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);

		if (MyFile.is_open()) {
			string Line;
			for (clsCurrency& c : vCurrencies) {
				Line = _ConverCurrencyObjectToLine(c);
				MyFile << Line << endl;

			}
			MyFile.close();

		}


	}

	static vector <clsCurrency> _LoadCurrencyDataFromFile() {
		fstream MyFile;
		vector <clsCurrency> vCurrencies;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open()) {
			string Line;

			while (getline(MyFile, Line)) {
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				vCurrencies.push_back(Currency);

			}
			MyFile.close();
		}
		return vCurrencies;
	}

	static clsCurrency _GetEmptyCurrencyObject() {


		return clsCurrency(enMode::EmptyMode, "", "", "", 0);

	}

	void _Update() {
		vector <clsCurrency> vCurrencies;
		vCurrencies = _LoadCurrencyDataFromFile();

		for (clsCurrency& c : vCurrencies) {
			if (c.CurrencyCode() == CurrencyCode()) {
				c = *this;
				break;
			}
		}

		_SaveCurrencyDataToFile(vCurrencies);

	}

public:

	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate) {
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;


	}

	string Country() {
		return _Country;
	}

	string CurrencyCode() {
		return _CurrencyCode;
	}

	string CurrencyName() {
		return _CurrencyName;
	}

	float Rate() {
		return _Rate;
	}

	void UpdateRate(float NewRate) {
		_Rate = NewRate;
		_Update();
	}

	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

	static clsCurrency FindByCode(string CurrencyCode) {
		CurrencyCode = clsString::UpperAllString(CurrencyCode);
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open()) {
			string line;
			while (getline(MyFile, line)) {
				clsCurrency Currency = _ConvertLineToCurrencyObject(line);
				if (CurrencyCode == Currency.CurrencyCode()) {
					MyFile.close();
					return Currency;
				}

			}
			MyFile.close();
		}

		return _GetEmptyCurrencyObject();


	}

	static clsCurrency FindByCountry(string Country) {
		Country = clsString::UpperAllString(Country);
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open()) {
			string line;
			while (getline(MyFile, line)) {
				clsCurrency Currency = _ConvertLineToCurrencyObject(line);
				if (Country == clsString::UpperAllString(Currency.Country())) {
					MyFile.close();
					return Currency;
				}

			}
			MyFile.close();
		}

		return _GetEmptyCurrencyObject();


	}

	static bool IsCurrencyExist(string CurrencyCode) {
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return (!Currency.IsEmpty());
	}

	static vector <clsCurrency> GetCurrenciesList() {
		return _LoadCurrencyDataFromFile();

	}

	float ConvertToUSD(float Amount) {

			return (float)(Amount / Rate());
		
 		

	}

	float ConvertToOtherCurrency(float Amount,clsCurrency Currency2) {

		float AmountInUSD = ConvertToUSD(Amount);

		if (Currency2.CurrencyCode() == "USD") {
			return AmountInUSD;
		}
		return (float)(AmountInUSD * Currency2.Rate());


	}


};

