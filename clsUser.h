#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h";
#include <fstream>
#include <vector>
#include "clsBankClient.h";
#include "clsDate.h";
#include "clsUtil.h";

using namespace std;
class clsUser : public clsPerson{
	
private:
	enum enMode{ EmptyMode=0,UpdateMode=1,AddNewMode=2};
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;

	bool _MarkedForDelete = false;
	
	struct stLoginRegisterRecord;


	static clsUser _ConvertLineToUserObject(string Line, string Seperator = "#//#") {
		vector <string > vUser = clsString::Split(Line, Seperator);


		return clsUser(enMode::UpdateMode, vUser[0], vUser[1], vUser[2]
			, vUser[3], vUser[4], clsUtil::DecryptText(vUser[5]), stoi(vUser[6]));


	}

	static clsUser _GetEmptyUserObject() {
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static string _ConvertUserObjectToLine(clsUser User, string Seperator = "#//#") {

		string stUserRecord = "";

		stUserRecord += User.FirstName + Seperator;
		stUserRecord += User.LastName + Seperator;
		stUserRecord += User.Email + Seperator;
		stUserRecord += User.Phone + Seperator;
		stUserRecord += User.UserName + Seperator;
		stUserRecord +=  clsUtil::EncryptText(User.Password) + Seperator;
		stUserRecord += to_string(User.Permissions);



		return stUserRecord;
	}

	static void _SaveUsersDataToFile(vector <clsUser> vUsers) {

		fstream MyFile;
		MyFile.open("Users.txt", ios::out);

		if (MyFile.is_open()) {
			string Line;
			for (clsUser& U : vUsers) {
				if (U._MarkedForDelete == false) {
					Line = _ConvertUserObjectToLine(U);
					MyFile << Line << endl;
				}
			}
			MyFile.close();

		}



	}

	static vector <clsUser> _LoadUsersDataFromFile() {
		fstream MyFile;
		vector <clsUser> vUsers;

		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open()) {
			string line;
			while (getline(MyFile, line)) {
				clsUser User = _ConvertLineToUserObject(line);
				vUsers.push_back(User);

			}
			MyFile.close();

		}
		return vUsers;
	}

	void _Update() {
		fstream MyFile;
		vector <clsUser> _vUsers = _LoadUsersDataFromFile();

		for (clsUser & U : _vUsers) {
			if (U.UserName==UserName) {
				U = *this;
				break;
			}
		}

		_SaveUsersDataToFile(_vUsers);





	}

	static void _AddDateLineToFile(string stDateLine) {
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);
		if (MyFile.is_open()) {

			MyFile << stDateLine << endl;
			MyFile.close();
		}


	}

	void _AddNew() {
		_AddDateLineToFile(_ConvertUserObjectToLine(*this));
	}


	 string _PrepareLogInRecord( string Seperator = "#//#") {
		
		string stUserRecord = "";

		stUserRecord += clsDate::GetSystemDateTimeString() + Seperator;
		stUserRecord += UserName + Seperator;
		stUserRecord += clsUtil::EncryptText(Password) + Seperator;
		stUserRecord += to_string(Permissions);

		

		return stUserRecord;
	}


	 static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string DateLine, string Seperator = "#//#") {
		 vector <string> LoginRegisterDataLine = clsString::Split(DateLine, Seperator);
		 stLoginRegisterRecord LoginRegisterRecord;
		 LoginRegisterRecord.DateTime = LoginRegisterDataLine[0];
		 LoginRegisterRecord.UserName = LoginRegisterDataLine[1];
		 LoginRegisterRecord.Password = clsUtil::DecryptText(LoginRegisterDataLine[2]);
		 LoginRegisterRecord.Permissions = stoi(LoginRegisterDataLine[3]);

		 return LoginRegisterRecord;


	 }


	
public:

	enum enPermissions {
		eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64,
		pShowLogInRegister = 128
	};

	struct stLoginRegisterRecord {
		string DateTime;
		string UserName;
		string Password;
		int Permissions;
	};




	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone
		, string UserName, string Password, int Permissions) :
		clsPerson(FirstName, LastName, Email, Phone) {

		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}


	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

	bool MarkedForDelete() {
		return _MarkedForDelete;
	}

	void setUserName(string UserName) {
		_UserName = UserName;
	}

	string GetUserName() {
		return _UserName;
	}
	__declspec(property(get = GetUserName, put = setUserName)) string UserName;

	void setPassword(string Password) {
		_Password = Password;
	}

	string GetPassword() {
		return _Password;
	}

	__declspec(property(get = GetPassword, put = setPassword)) string Password;

	void setPermissions(int Permissions) {
		_Permissions = Permissions;
	}

	int GetPermissions() {
		return _Permissions;
	}
	__declspec(property(get = GetPermissions, put = setPermissions)) int Permissions;

	static clsUser Find(string UserName) {


		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open()) {
			string line;
			while (getline(MyFile, line)) {
				clsUser User = _ConvertLineToUserObject(line);
				if (User.UserName == UserName) {
					MyFile.close();
					return User;
				}

			}
			MyFile.close();

		}
		return _GetEmptyUserObject();
	}

	static clsUser Find(string UserName, string Password) {


		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open()) {
			string line;
			while (getline(MyFile, line)) {
				clsUser User = _ConvertLineToUserObject(line);
				if (User.UserName == UserName && User.Password == Password) {
					MyFile.close();
					return User;
				}

			}
			MyFile.close();

		}
		return _GetEmptyUserObject();
	}

	static clsUser GetAddNewUserObject(string UserName) {

		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	bool Delete() {

		vector <clsUser> _vUsers = _LoadUsersDataFromFile();

		for (clsUser & U : _vUsers) {
			if (U.UserName == UserName) {
				U._MarkedForDelete = true;
				break;
			}
		}
		_SaveUsersDataToFile(_vUsers);
		*this = _GetEmptyUserObject();

		return true;
	}

	static vector <clsUser> GetUsersList() {
		return _LoadUsersDataFromFile();
	}

	/*static double GetTotalBalances() {
		vector <clsUser> vUsers = clsUser::GetUsersList();

		double TotalBalances = 0;
		for (clsUser & U : vUsers) {
			TotalBalances += U.GetTotalBalances();

		}
		return TotalBalances;
	}*/

	 bool CheckAccessPermission(enPermissions Permission) {
		if (this->Permissions == enPermissions::eAll) 
			return true;
		
		if ((Permission & this->Permissions) == Permission) 
			return true;
		else
			return false;

	}

	

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExist = 2 };

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
			if (IsUserExist(UserName)) {
				return enSaveResults::svFaildUserExist;
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

	static bool IsUserExist(string UserName) {
		clsUser User = clsUser::Find(UserName);
		return (!User.IsEmpty());

	}

	 void RegisterLogIn() {
		 string stDateLine = _PrepareLogInRecord();
		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::out | ios::app);

		if (MyFile.is_open()) {
			
					MyFile << stDateLine << endl;
					MyFile.close();
				
			}
			

		}



	 static vector <stLoginRegisterRecord> GetLoginRegisterList() {
		 fstream MyFile;
		 vector <stLoginRegisterRecord> vLoginRegistersRecord;

		 MyFile.open("LoginRegister.txt", ios::in);
		 if (MyFile.is_open()) {
			
			 string line;

			 stLoginRegisterRecord LoginRegisterRecord;

			 while (getline(MyFile, line)) {
				 LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(line);
				 vLoginRegistersRecord.push_back(LoginRegisterRecord);

			 }
			 MyFile.close();

		 }
		 return vLoginRegistersRecord;
	 }

	
};

