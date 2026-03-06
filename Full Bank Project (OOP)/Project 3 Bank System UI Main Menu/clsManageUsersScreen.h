#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"


using namespace std;

class clsManageUsersScreen : protected clsScreen
{

private:

	enum enManageUsersMenuOptions{eListUsers = 1,eAddNewUser,eDeleteUser,eUpdateUser,eFindUser,eMainMenu};

	static short _ReadManageUsersMenuOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6 ");
		return Choice;

	}

	static void _GoBackToManageUsersMenu()
	{
		cout << "\n\nPress any key to go to Transactions Menu  ...\n";
		system("pause>0");
		ShowManageUsersMenu();
	}

	static void _ShowListUsersScreen()
	{
		//cout << "\nList Users Screen Will be Here Soon ...\n";
		clsListUsersScreen::ShowListUsersScreen();
	}

	static void _ShowAddNewUserScreen()
	{
		//cout << "\nAdd New Users Screen Will be Here Soon ...\n";
		clsAddNewUserScreen::ShowAdduserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		//cout << "\nDelete User Screen Will be Here Soon ...\n";
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		//cout << "\nUpdate User Screen Will be Here Soon ...\n";
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		//cout << "\nFind User Screen Will be Here Soon ...\n";
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _PerformManageUsersOption(enManageUsersMenuOptions ManageUsersOptions)
	{
		switch (ManageUsersOptions)
		{
		case eListUsers:
		{
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersMenu();
			break;
		}

		case eAddNewUser:
		{
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenu();
			break;
		}

		case eDeleteUser:
		{
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenu();
			break;
		}

		case eUpdateUser:
		{
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenu();
			break;

		}

		case eFindUser:
		{
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenu();
			break;
		}

		case eMainMenu:
		{
			//Do Nothing Here the main screen will handle it
		}

		}



	}





public:

	static void ShowManageUsersMenu()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;  // this will exit the function and it will not continue
		}

		system("cls");
		_DrawScreenHeader("\t  Manage Users Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Manage Users Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users\n";
		cout << setw(37) << left << "" << "\t[2] Add New User\n";
		cout << setw(37) << left << "" << "\t[3] Delete User\n";
		cout << setw(37) << left << "" << "\t[4] Update User\n";
		cout << setw(37) << left << "" << "\t[5] Find User\n";
		cout << setw(37) << left << "" << "\t[6] Main Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformManageUsersOption((enManageUsersMenuOptions)_ReadManageUsersMenuOption());
	}







};

