#pragma once
#include <iostream>
#include "clsScreen.h";
#include <iomanip>
#include "clsInputValidate.h";
#include "clsCurrrenciesListScreen.h";
#include "clsFindCurrencyScreen.h";
#include "clsUpdateCurrencyScreen.h";
#include "clsCurrencyCalculatorScreen.h";
class clsCurrencyExchangeScreen:protected clsScreen{
private:
    enum enCurrencyExchangeMenueOptions {
        eListCurrencies = 1, eFindCurrency = 2,
        eUpdateCurrencyRate = 3, eCurrencyCalculator = 4, eShowMainMenue = 5
    };

    static short _ReadCurrencyExchangeMenueOption() {
        short Number = 0;
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        Number = clsInputValidate::ReadNumberBetween<short>(1, 5);
        return Number;
    }

    static void _GoBackToTransactionsMenue() {
        cout << setw(37) << left << " " << "\n\tPress any key to go back to Main Menue...\n";
        system("pause>0");
        ShowCurrencyExchangeMenue();
    }

    static void _ShowCurrenciesListScreen() {
        clsCurrrenciesListScreen::ShowCurrenciesListScreen();
        //cout << "\nList Currencies Screen Will be here...\n";
    }

    static void _ShowFindCurrencyScreen() {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
        //cout << "\nFind Currency Screen Will be here...\n";
    }

    static void _ShowUpdateRateScreen() {
        clsUpdateCurrencyScreen::ShowUpdateCurrencyRateScreen();
        //cout << "\nUpdate Rate Screen Will be here...\n";
    }

    static void _ShowCurrencyCalculatorScreen() {
        clsCurrencyCalculatorScreen::ShowCurrencyCalaculatorScreen();
        //cout << "\nCurrency Calculator Screen Will be here...\n";
    }



    static void _PerformCurrencyExchangeMenueOption(enCurrencyExchangeMenueOptions CurrencyExhangeOption) {

        switch (CurrencyExhangeOption) {

        case enCurrencyExchangeMenueOptions::eListCurrencies: {
            system("cls");
            _ShowCurrenciesListScreen();
            _GoBackToTransactionsMenue();

            break;
        }
        case enCurrencyExchangeMenueOptions::eFindCurrency: {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToTransactionsMenue();

            break;
        }
        case enCurrencyExchangeMenueOptions::eUpdateCurrencyRate: {
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToTransactionsMenue();

            break;
        }
        case enCurrencyExchangeMenueOptions::eCurrencyCalculator: {
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToTransactionsMenue();

            break;
        }
    
        case enCurrencyExchangeMenueOptions::eShowMainMenue: {

        }

        }



    }

public:


    static void ShowCurrencyExchangeMenue() {
       


        system("cls");
        _DrawScreenHeader("\t  Currency Exchange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Exchange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrencyExchangeMenueOption((enCurrencyExchangeMenueOptions)_ReadCurrencyExchangeMenueOption());





    }







};

