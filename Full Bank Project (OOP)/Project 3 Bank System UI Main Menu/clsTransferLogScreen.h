#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include "clsScreen.h"
#include "TransferLog.h"


class clsTransferLogScreen : protected clsScreen
{

private:

	static void _PrintTransferRecordLine(vector <string>& vLog)
	{
		cout << setw(8) << left << "" << "| " << setw(23) << left << vLog[0];
		cout << "| " << setw(8) << left << vLog[1];
		cout << "| " << setw(8) << left << vLog[2];
		cout << "| " << setw(8) << left << vLog[3];
		cout << "| " << setw(10) << left << vLog[4];
		cout << "| " << setw(10) << left << vLog[5];
		cout << "| " << setw(8) << left << vLog[6];
		cout << endl;
	}


public:


	static void ShowTransferLoginScreen()
	{
		vector<vector<string>> vTransferRecords = TransferLog::ReadAllTransferLogs();


		string Title = "\t  Transfer Log List Screen";
		string SubTitle = "\t    (" + to_string(vTransferRecords.size()) + ") Records(s)";

		_DrawScreenHeader(Title, SubTitle);


		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
		cout << "| " << left << setw(8) << "Date/Time";
		cout << "| " << left << setw(8) << "s.Acct";
		cout << "| " << left << setw(8) << "d.Acct";
		cout << "| " << left << setw(10) << "s.Balance";
		cout << "| " << left << setw(10) << "d.Balance";
		cout << "| " << left << setw(8) << "User";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;


		if (vTransferRecords.empty())
			cout << "\t\t\t\tNo Logins Available In the System!" << endl;
		else
		{
			for (vector<string>& Record : vTransferRecords)
				_PrintTransferRecordLine(Record);
		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;






	}








};

