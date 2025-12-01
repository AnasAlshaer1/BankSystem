#pragma once
#include <iostream>
#include "clsUser.h";
#include "clsScreen.h";
#include "Global.h";
#include "clsMainScreen.h";
#include "clsUtil.h";
class clsLoginScreen: protected clsScreen{

private:
	static bool _Login() {
		short FailsLoginCount =0 ;
		bool LoginFaild = false;
		string Username, Password;
		do {
			

			if (LoginFaild) {
				FailsLoginCount++;
				cout << "\nInvalid Username/Password!\n";
				cout << "You have " << (3-FailsLoginCount) << " Trial (s) to login." << endl;
					
			}
			if (FailsLoginCount == 3) {
				cout << "\n\nYou are locked after 3 faild trials" << endl;

				return false;
			}

			cout << "\nEnter Username? ";
			cin >> Username;
			cout << "Enter Password? ";
			cin >> Password;

			CurrentUser = clsUser::Find(Username, Password);

			LoginFaild = CurrentUser.IsEmpty();

			


		} while (LoginFaild);

		
		    CurrentUser.RegisterLogIn();

			clsMainScreen::ShowMainMenue();
			
			return true;
	}


public:
	static bool ShowLoginScreen() {

		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		return _Login();
	}






};

