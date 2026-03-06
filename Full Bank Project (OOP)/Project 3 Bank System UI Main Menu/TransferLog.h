#pragma once
#include <iostream>
#include <fstream>
#include "clsDate.h"
#include "clsString.h"
#include "Global.h"



class TransferLog
{

private:

	static vector <string> _GetTransfereData(clsBankClient SourceClient,clsBankClient DestinationClient,float Amount)
	{
		vector <string> vString;

		vString.push_back(clsDate::GetSystemDateTimeString());
		vString.push_back(SourceClient.AccountNumber());
		vString.push_back(DestinationClient.AccountNumber());
		vString.push_back(to_string(Amount));
		vString.push_back(to_string(SourceClient.AccountBalance));
		vString.push_back(to_string(DestinationClient.AccountBalance));
		vString.push_back(CurrentUser.UserName);

		return vString;
	}

	static string _PrepareLogRecord(clsBankClient SourceClient, clsBankClient DestinationClient, float Amount,string Seperator)
	{
		vector <string> vLog = _GetTransfereData(SourceClient,DestinationClient,Amount);

		return clsString::JoinString(vLog, Seperator);
	}

	



public:

	static void SaveTransferLog(clsBankClient SourceClient, clsBankClient DestinationClient, float Amount)
	{
		fstream MyFile;
		string LogRecord = _PrepareLogRecord(SourceClient,DestinationClient,Amount,"#//#");

		MyFile.open("TransferLog.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << LogRecord << endl;
			MyFile.close();
		}

	}


	static vector<vector<string>> ReadAllTransferLogs(string Seperator = "#//#")
	{
		vector<vector<string>> AllLogs;
		fstream MyFile("TransferLog.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				vector<string> vLine = clsString::SplitString(Line, Seperator);
				AllLogs.push_back(vLine);
			}

			return AllLogs;

		}
	}

















};

