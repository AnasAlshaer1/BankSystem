#pragma once
#include "clsScreen.h";
#include <iostream>
#include "clsDate.h";
#include "clsBankClient.h";
#include <iomanip>
class clsTransferLogListScreen: protected clsScreen{

private :

    static void PrintLoginRegisterRecord(clsBankClient::stTransferLogRecrod TransferLogRecord) {


        cout << setw(8) << left << "";
        cout << "| " << setw(20) << left << TransferLogRecord.DateTime;
        cout << "| " << setw(10) << left << TransferLogRecord.SourceAccountNumber;
        cout << "| " << setw(10) << left << TransferLogRecord.DestinationAccountNumber;
        cout << "| " << setw(10) << left << TransferLogRecord.Amount;
        cout << "| " << setw(10) << left << TransferLogRecord.srcBalanceAfter;
        cout << "| " << setw(10) << left << TransferLogRecord.destBalanceAfter;
        cout << "| " << setw(10) << left << TransferLogRecord.UserName;




    }




public:

	static void ShowTransferLogScreen() {
		vector <clsBankClient::stTransferLogRecrod> vTransferLogs = clsBankClient::GetTransferLogList();
		string Title = "\t Tansfer Log List Screen";
        string SubTitle = "\t     (" + to_string(vTransferLogs.size()) +") Record(s)";
		
			_DrawScreenHeader(Title,SubTitle);

            cout << setw(8) << left << "" <<
                "\n\t_______________________________________________________";
            cout << "_________________________________________\n" << endl;

            cout << setw(8) << left << "";
            cout << "| " << left << setw(20) << "Date/Time";
            cout << "| " << left << setw(10) << "s.Acct";
            cout << "| " << left << setw(10) << "d.Acct";
            cout << "| " << left << setw(10) << "Amount";
            cout << "| " << left << setw(10) << "s.Balance";
            cout << "| " << left << setw(10) << "d.Balance";
            cout << "| " << left << setw(10) << "User";
            cout << setw(8) << left << "" <<
                "\n\t_______________________________________________________";
            cout << "_________________________________________\n" << endl;

            if (vTransferLogs.size() == 0) {
                cout << "\t\t\t\tNo Users Available in the system!";
            }
            else {

                for (clsBankClient::stTransferLogRecrod & Record : vTransferLogs) {
                    PrintLoginRegisterRecord(Record);
                    cout << endl;
                }

                cout << setw(8) << left << "" <<
                    "\n\t_______________________________________________________";
                cout << "_________________________________________\n" << endl;
            }



	}





};

