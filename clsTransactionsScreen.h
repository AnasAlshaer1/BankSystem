#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include <iomanip>
#include "clsDepositScreen.h";
#include "clsWithdrawScreen.h";
#include "clsTotalBalancesScreen.h";
#include "clsTransferScreen.h";
#include "clsTransferLogListScreen.h";
class clsTransactionsScreen : protected clsScreen{

private:
    enum enTransactionsMenueOptions {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3,eTransfer=4,eTransferLog=5 ,eShowMainMenue = 6
    };

    static short _ReadTransactionsMenueOption() {
        short Number = 0;
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        Number = clsInputValidate::ReadNumberBetween<short>(1, 6);
        return Number;
    }

    static void _GoBackToTransactionsMenue() {
        cout << setw(37) << left << " " << "\n\tPress any key to go back to Main Menue...\n";
        system("pause>0");
        ShowTransactionsMenue();
    }

    static void _ShowDepositScreen() {
        clsDepositScreen::ShowDopositScreen();
        //cout << "\nDeposit Screen Will be here...\n";
    }

    static void _ShowWithdrawScreen() {
        clsWithdrawScreen::ShowWithdrawScreen();
        //cout << "\nWithdraw Screen Will be here...\n";
    }

    static void _ShowTotalBalancesScreen() {
        clsTotalBalancesScreen::ShowTotalBalances();
        //cout << "\nBalances Screen Will be here...\n";
    }

    static void _ShowTransferScreen() {
        clsTransferScreen::ShowTransferScreen();
        //cout << "\nThe Transfer Screen Will be here...\n";
    }

    static void _ShowTransferLogScreen() {
        clsTransferLogListScreen::ShowTransferLogScreen();
      /*  cout << "\nThe Transfer Screen Will be here...\n";*/
    }

    static void _PerformTransactionsMenueOption(enTransactionsMenueOptions Transaction) {

        switch (Transaction) {

        case enTransactionsMenueOptions::eDeposit: {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();

            break;
        }
        case enTransactionsMenueOptions::eWithdraw: {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();

            break;
        }
        case enTransactionsMenueOptions::eShowTotalBalance : {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();

            break;
        }
        case enTransactionsMenueOptions::eTransfer: {
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenue();

            break;
        }
        case enTransactionsMenueOptions::eTransferLog: {
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionsMenue();

            break;
        }

        case enTransactionsMenueOptions::eShowMainMenue: {
            
        }

        }



    }

public:


    static void ShowTransactionsMenue() {
        if (!CheckAccessRights(clsUser::pTranactions)) {
            return;
        }


        system("cls");
        _DrawScreenHeader("\t  Transactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenueOption((enTransactionsMenueOptions)_ReadTransactionsMenueOption());





    }
};

