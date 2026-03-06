#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "Global.h"
#include "LogFile.h"
#include "clsConsoleColor.h"


class clsLoginScreen : protected clsScreen
{

private:

	static bool _Login()
	{
		bool LoginFailed = false;

		string Username, Password;

		short Tries = 3;


		do
		{
			if (LoginFailed)
			{
				Tries--;
				clsConsoleColor::Red();
				cout << "\nInvalid Username/Password!\n";
				clsConsoleColor::Default();
				cout << "You have " << Tries << " Trial(s) to login!\n\n";
			}


			if (Tries == 0)
			{
				clsConsoleColor::Red();
				cout << "\n\nYou are locked after 3 failed trials !\n\n";
				clsConsoleColor::Default();
				return false;
			}

			cout << "Enter Username ?";
			cin >> Username;

			cout << "Enter Password ?";
			cin >> Password;

			CurrentUser = clsUser::Find(Username, Password);

			LoginFailed = CurrentUser.IsEmpty();

			if (!LoginFailed)
			{
				LogFile::SaveLogs();
			}


		} while (LoginFailed);

		clsMainScreen::ShowMainMenu();
		return true;
	}

		





public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		return _Login();
	}

	




};

