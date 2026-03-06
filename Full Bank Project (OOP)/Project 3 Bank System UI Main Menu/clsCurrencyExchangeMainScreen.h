#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"


class clsCurrencyExchangeMainScreen : protected clsScreen
{

private:

	enum enCurrencyExchangeMenuOptions{eListCurrencies = 1,eFindCurrencies,eUpdateRate,eCurrencyCalculator,eExit};

	static short _ReadCurrencyExchangeMenuOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5] ? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5 ");
		return Choice;
	}

	static void _ShowListCurrenciesScreen()
	{
		//cout << "\nList Currencies Screen Will Be here soon ...\n" << endl;
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		//cout << "\nFind Currency Screen Will Be here soon ...\n" << endl;
		clsFindCurrencyScreen::ShowFindCurrencyScreen();

	}

	static void _ShowUpdateRateScreen()
	{
		//cout << "\nUpdate Screen Will Be here soon ...\n" << endl;
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		//cout << "\nShow Currency Calculator Will Be here soon ...\n" << endl;
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _GoBackToCurrencyExchangeMenu()
	{
		cout << "\n\nPress any key to go to Transactions Menu  ...\n";
		system("pause>0");
		ShowCurrnecyExchangeMainScreen();
	}

	static void _PerformCurrencyExchangeMenuOption(enCurrencyExchangeMenuOptions CurrencyExchangeMenuOptions)
	{

		switch (CurrencyExchangeMenuOptions)
		{

		case eListCurrencies:
		{
			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		}

		case eFindCurrencies:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		}

		case eUpdateRate:
		{
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		}


		case eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		}


		case eExit:
		{
			//Do Nothing Here the main screen will handle it
		}


		}


	}





public:


	static void ShowCurrnecyExchangeMainScreen()
	{


		system("cls");
		_DrawScreenHeader("\t  Currency Exchange Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Currency Exchange Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformCurrencyExchangeMenuOption((enCurrencyExchangeMenuOptions)_ReadCurrencyExchangeMenuOption());

	}














};

