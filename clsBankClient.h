#pragma once
#include <iostream>
#include <string>
#include "clsString.h";
#include <vector>
#include <fstream>
#include "clsPerson.h";
#include "clsDate.h";
using namespace std;



class clsBankClient: public clsPerson {

private:




	enum enMode { EmptyMode = 0, UpdateMode = 1 ,AddNewMode=2};
	enMode _Mode;



	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkedForDeleted=false;

	struct stTransferLogRecrod;

	static clsBankClient _ConvertLineToClientObject(string Line,string Seperator="#//#") {
		vector <string > vClient = clsString::Split(Line, Seperator);


		return clsBankClient(enMode::UpdateMode, vClient[0], vClient[1], vClient[2]
			, vClient[3], vClient[4], vClient[5], stod(vClient[6]));


	}

	static clsBankClient _GetEmptyClientObject() {
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "","", 0);
	}

	static string _ConvertClientObjectToLine(clsBankClient Client,string Seperator="#//#") {

		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.AccountNumber() + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance) ;



		return stClientRecord;
	}

	static void _SaveClientsDataToFile(vector <clsBankClient> vClients) {

		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);

		if (MyFile.is_open()) {
			string Line;
			for (clsBankClient& c : vClients) {
				if (c._MarkedForDeleted == false) {
					Line = _ConvertClientObjectToLine(c);
					MyFile << Line << endl;
				}
			}
			MyFile.close();

		}



	}

	static vector <clsBankClient> _LoadClientsDataFromFile() {
		fstream MyFile;
		vector <clsBankClient> vClients;
		
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open()) {
			string line;
			while (getline(MyFile, line)){
				clsBankClient Client = _ConvertLineToClientObject(line);
				vClients.push_back(Client);

			}
			MyFile.close();

		}
		return vClients;
	}

	void _Update() {
		fstream MyFile;
		vector <clsBankClient> _vClients = _LoadClientsDataFromFile();
		
		for (clsBankClient& c : _vClients) {
			if (c.AccountNumber() == AccountNumber()) {
				c = *this;
				break;
			}
		}

		_SaveClientsDataToFile(_vClients);





	}

	static void _AddDateLineToFile(string stDateLine) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);
		if (MyFile.is_open()) {

			MyFile << stDateLine << endl;
			MyFile.close();
		}

	
	}

	void _AddNew() {
		_AddDateLineToFile(_ConvertClientObjectToLine(*this));
	}

	string _PrepareTransferLogRecord(float Amount, clsBankClient DestinationClient,string UserName ,string Seperator = "#//#") {

		string stTransferLogRecord = "";

		stTransferLogRecord += clsDate::GetSystemDateTimeString() + Seperator;
		stTransferLogRecord += AccountNumber()+Seperator;
		stTransferLogRecord += DestinationClient.AccountNumber() + Seperator;
		stTransferLogRecord += to_string(Amount)+Seperator;
		stTransferLogRecord+= to_string(AccountBalance) + Seperator;
		stTransferLogRecord += to_string(DestinationClient.AccountBalance) + Seperator;
		stTransferLogRecord +=UserName ;




		return stTransferLogRecord;
	}

	static stTransferLogRecrod _ConvertTransferLogLineToRecord(string Dateline, string Seperator = "#//#") {
		vector <string> vTransferLogs = clsString::Split(Dateline, Seperator);
		stTransferLogRecrod TransferLogRecord;
		TransferLogRecord.DateTime = vTransferLogs[0];
		TransferLogRecord.SourceAccountNumber = vTransferLogs[1];
		TransferLogRecord.DestinationAccountNumber = vTransferLogs[2];
		TransferLogRecord.Amount = stod(vTransferLogs[3]);
		TransferLogRecord.srcBalanceAfter = stod(vTransferLogs[4]);
		TransferLogRecord.destBalanceAfter = stod(vTransferLogs[5]);
		TransferLogRecord.UserName = vTransferLogs[6];

		return TransferLogRecord;

	}

	void _RegisterTransferLog( float Amount, clsBankClient DestinationClient,string UserName) {
		string stDateLine = _PrepareTransferLogRecord(Amount, DestinationClient,UserName);
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open()) {

			MyFile << stDateLine << endl;
			MyFile.close();

		}
	}

public:



	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone
		, string AccountNumber, string PinCode, float AccountBalance) :
		clsPerson(FirstName, LastName, Email, Phone) {

		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;

	}


	struct stTransferLogRecrod {
		string DateTime;
		string SourceAccountNumber;
		string DestinationAccountNumber;
		float Amount;
		float srcBalanceAfter;
		float destBalanceAfter;
		string UserName;


	};

	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

	string AccountNumber() {
		return _AccountNumber;
	}

	bool MarkedForDeleted() {
		return _MarkedForDeleted;
	}

	void setPinCode(string PinCode) {
		_PinCode = PinCode;
	}
	
	string GetPinCode() {
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = setPinCode)) string PinCode;

	void setAccountBalance(float AccountBalance) {
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance() {
		return _AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = setAccountBalance)) float AccountBalance;

	//void Print()
	//{
	//	cout << "\nClient Card:";
	//	cout << "\n___________________";
	//	cout << "\nFirstName : " << GetFirstName();
	//	cout << "\nLastName  : " << GetLastName();
	//	cout << "\nFull Name : " << FullName();
	//	cout << "\nEmail     : " << GetEmail();
	//	cout << "\nPhone     : " << GetPhone();
	//	cout << "\nAcc.Number: " << _AccountNumber;
	//	cout << "\nPassword  : " << _PinCode;
	//	cout << "\nBalance   : " << _AccountBalance;
	//	cout << "\n___________________\n";

	//}

	static clsBankClient Find(string AccountNumber) {


		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open()) {
			string line;
			while (getline(MyFile, line)) {
				clsBankClient Client = _ConvertLineToClientObject(line);
				if (Client.AccountNumber() == AccountNumber) {
					MyFile.close();
					return Client;
				}

			}
			MyFile.close();

		}
		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode) {


		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open()) {
			string line;
			while (getline(MyFile, line)) {
				clsBankClient Client = _ConvertLineToClientObject(line);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode==PinCode) {
					MyFile.close();
					return Client;
				}

			}
			MyFile.close();

		}
		return _GetEmptyClientObject();
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber) {

		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete() {
		
		vector <clsBankClient> _vClients = _LoadClientsDataFromFile();
		
		for (clsBankClient & C : _vClients) {
			if (C.AccountNumber() == AccountNumber()) {
				C._MarkedForDeleted = true;
				break;
			}
		}
		_SaveClientsDataToFile(_vClients);
		*this = _GetEmptyClientObject();

		return true;
	}

	static vector <clsBankClient> GetClientsList() {
		return _LoadClientsDataFromFile();
	}

	static vector<stTransferLogRecrod> GetTransferLogList() {
		fstream MyFile;
		vector <stTransferLogRecrod> vTransferLogs;
		MyFile.open("TransferLog.txt", ios::in);
		if (MyFile.is_open()) {
			string line;
			stTransferLogRecrod TransferLogRecord;
			while (getline(MyFile, line)) {
				TransferLogRecord = _ConvertTransferLogLineToRecord(line);
				vTransferLogs.push_back(TransferLogRecord);
			}

			MyFile.close();

		}
		return vTransferLogs;

	}

	static double GetTotalBalances() {
		vector <clsBankClient> vClients =clsBankClient::GetClientsList();

		double TotalBalances = 0;
		for (clsBankClient& c : vClients) {
			TotalBalances += c.AccountBalance;

		}
		return TotalBalances;
	}

	void Deposit(double Amount) {
		_AccountBalance += Amount;
		Save();
	}

	bool Withdraw(double Amount) {
		if (Amount > _AccountBalance) {
			return false;
		}
		else {
			_AccountBalance -= Amount;
			Save();
			return true;
		}
	}

	bool Transfer(float amount,clsBankClient & DestinationClient,string UserName) {

		if (amount > AccountBalance) {
			return false;
		}
		else {
			Withdraw(amount);
			DestinationClient.Deposit(amount);
			_RegisterTransferLog(amount, DestinationClient, UserName);
			return true;
		}

	}


	enum enSaveResults{svFaildEmptyObject=0,svSucceeded=1,svFaildAccountNumberExist=2};

	enSaveResults Save() {

		switch (_Mode) {

		case enMode::EmptyMode: {
			if (IsEmpty()) {
				return enSaveResults::svFaildEmptyObject;
			}
		}
		case enMode::UpdateMode: {
			_Update();

			return enSaveResults::svSucceeded;
			break;
		}

		case enMode::AddNewMode: {
			if (IsClientExist(AccountNumber())) {
				return enSaveResults::svFaildAccountNumberExist;
			}
			else {
				_AddNew();

				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}
			break;
		}

		}
	}

	static bool IsClientExist(string AccountNumber) {
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return (!Client.IsEmpty());

	}




	
};

