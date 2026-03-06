#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "Global.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeMainScreen.h"
#include "clsConsoleColor.h"

using namespace std;

class clsMainScreen : protected clsScreen
{
private:

	enum enMainMenuOptions { eListClients = 1, eAddNewClient, eDeleteClient, eUpdateClient,eFindClient,eShowTransactionsMenu,eManageUsers,eLoginRegister,eCurrency,eExit};

	static short _ReadMainMenuOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10] ? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1,10,"Enter Number between 1 and 10 ");
		return Choice;
	}

	static void _GoBackToMainMenu()
	{
		cout << setw(37) << left << "" << "\n\tPress any Key to go back to Main Menu ...\n";
		system("pause>0");
		ShowMainMenu();

	}

	static void _ShowAllClientsScreen()
	{
		// cout << "Clients Screen Will be Here Soon . . ." << endl;
		clsClientListScreen::ShowClientsList();
	}

	static void _ShowAddNewClientScreen()
	{
		//cout << "Add New Client Screen Will be Here Soon . . ." << endl;
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _ShowDeleteClientScreen()
	{
		//cout << "Delete Client Screen Will be Here Soon . . ." << endl;
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen()
	{
		//cout << "Update Client Screen Will be Here Soon . . ." << endl;
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen()
	{
		//cout << "Find Client Screen Will be Here Soon . . ." << endl;
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsMenuScreen()
	{
		//cout << "Transactons Screen Will be Here Soon . . ." << endl;
		clsTransactionsScreen::ShowTransactionsMenu();
	}

	static void _ShowManageUsersScreen()
	{
		//cout << "Manage Users Screen Will be Here Soon . . ." << endl;
		clsManageUsersScreen::ShowManageUsersMenu();
	}

	/*static void _ShowEndScreen()
	{
		cout << "Logout Screen Will be Here Soon . . ." << endl;
	}*/


	static void _ShowLoginRegisterScreen()
	{
		clsLoginRegisterScreen::ShowLoginRegisterScreen();

	}

	static void _ShowCurrencyExchangeMainScreen()
	{
		clsCurrencyExchangeMainScreen::ShowCurrnecyExchangeMainScreen();
	}

	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
		//Then it Will go back to main Function
	}

	static void _PerformMainMenuOption(enMainMenuOptions MainMenuOption)
	{
		switch (MainMenuOption)
		{
		case eListClients:
		{
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenu();
			break;
		}
		case eAddNewClient:
		{
			system("cls");
			_ShowAddNewClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case eDeleteClient:
		{
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenu();
			break;
		}

		case eUpdateClient:
		{
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenu();
			break;
		}

		case eFindClient:
		{
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenu();
			break;
		}

		case eShowTransactionsMenu:
		{
			system("cls");
			_ShowTransactionsMenuScreen();
			_GoBackToMainMenu();
			break;
		}

		case eManageUsers:
		{
			system("cls");
			_ShowManageUsersScreen();
			_GoBackToMainMenu();
			break;
		}

		case eLoginRegister:
		{
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenu();
			break;
		}

		case eCurrency:
		{
			system("cls");
			_ShowCurrencyExchangeMainScreen();
			_GoBackToMainMenu();
			break;
		}


		case eExit:
		{
			system("cls");
			//_ShowEndScreen();
			_Logout();
			break;

		}

		}
	}

	static void _PrintMenuOption(short Number, string Text, clsUser::enPermissions Permission)
	{
		cout << setw(37) << left << "";

		if (CurrentUser.CheckAccessPermission(Permission) || CurrentUser.Permissions == clsUser::eAll)
		{
			clsConsoleColor::Green();
		}
		else
		{
			clsConsoleColor::Red();
		}

		cout << "\t[" << Number << "] " << Text << "\n";

		clsConsoleColor::Default();
	}

	static void _ShowLegend()
	{
		cout << setw(37) << left << "";

		clsConsoleColor::Green();
		cout << "Green";
		clsConsoleColor::Default();
		cout << " : Access Allowed\n";

		cout << setw(37) << left << "";

		clsConsoleColor::Red();
		cout << "Red";
		clsConsoleColor::Default();
		cout << "   : Access Denied\n\n";
	}


public:

	static void ShowMainMenu()
	{
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");
		_ShowLegend();

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PrintMenuOption(1, "Show Client List", clsUser::pListClients);
		_PrintMenuOption(2, "Add New Client", clsUser::pAddNewClient);
		_PrintMenuOption(3, "Delete Client", clsUser::pDeleteClient);
		_PrintMenuOption(4, "Update Client Info", clsUser::pUpdateClients);
		_PrintMenuOption(5, "Find Client", clsUser::pFindClient);
		_PrintMenuOption(6, "Transactions", clsUser::pTransactions);
		_PrintMenuOption(7, "Manage Users", clsUser::pManageUsers);
		_PrintMenuOption(8, "Login Register", clsUser::pLoginRegister);
		cout << setw(37) << left << "" << "\t[9] Currency Exchange\n";
		cout << setw(37) << left << "" << "\t[10] Logout\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformMainMenuOption((enMainMenuOptions)_ReadMainMenuOption());

	}




};

