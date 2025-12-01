#pragma once
#include "clsScreen.h";
#include <iostream>
#include <iomanip>
#include "clsUser.h";
using namespace std;
class clsLoginRegisterScreen: protected clsScreen{

private:

    static void PrintLoginRegisterRecord(clsUser::stLoginRegisterRecord LoginRegisterRecord) {


        cout << setw(8) << left << "";
        cout << "| " << setw(35) << left << LoginRegisterRecord.DateTime;
        cout << "| " << setw(20) << left << LoginRegisterRecord.UserName;
        cout << "| " << setw(20) << left << LoginRegisterRecord.Password;
        cout << "| " << setw(10) << left << LoginRegisterRecord.Permissions;
       


    }


public:

    static void ShowLoginRegisterList() {

        if (!CheckAccessRights(clsUser::enPermissions::pShowLogInRegister)) {
            return;
        }


        vector <clsUser::stLoginRegisterRecord> vLoginRegistersRecord = clsUser::GetLoginRegisterList();
       

        
        string title = "\t  Login Register List Screen";
        string SubTitle = "\t  (" + to_string(vLoginRegistersRecord.size()) + ") Records (s)";
        _DrawScreenHeader(title, SubTitle);

        cout << setw(8) << left << "" <<
            "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" ;
        cout << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" <<
            "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vLoginRegistersRecord.size() == 0) {
            cout << "\t\t\t\tNo Users Available in the system!";
        }
        else {

            for (clsUser::stLoginRegisterRecord & Record : vLoginRegistersRecord) {
                PrintLoginRegisterRecord(Record);
                cout << endl;
            }

            cout << setw(8) << left << "" <<
                "\n\t_______________________________________________________";
            cout << "_________________________________________\n" << endl;
        }






    }









};

