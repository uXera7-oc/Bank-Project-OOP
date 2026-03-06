#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include "clsScreen.h"
#include "LogFile.h"



class clsLoginRegisterScreen : protected clsScreen
{

private:



	static void _PrintLoginRegisterRecordLine(vector <string> &vLog)
	{
		cout << setw(8) << left << "" << "| " << setw(35) << left << vLog[0];
		cout << "| " << setw(20) << left << vLog[1];
		cout << "| " << setw(20) << left << vLog[2];
		cout << "| " << setw(10) << left << vLog[3];
		cout << endl;
	}






public:

	static void ShowLoginRegisterScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
		{
			return;  // this will exit the function and it will not continue
		}


		vector<vector<string>> vLoginRegisterRecords = LogFile::ReadAllLogs();


		string Title = "\t  Login Register List Screen";
		string SubTitle = "\t    (" + to_string(vLoginRegisterRecords.size()) + ") Records(s)";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(10) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vLoginRegisterRecords.empty())
			cout << "\t\t\t\tNo Logins Available In the System!" << endl;
		else
		{
			for (vector<string>& Record : vLoginRegisterRecords)
				_PrintLoginRegisterRecordLine(Record);
		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;


	}





};

