#pragma once
#include <iostream>
#include <fstream>
#include "clsDate.h"
#include "clsString.h"
#include "Global.h"





class LogFile
{

private:

	static vector<string> _GetLogData()
	{
		vector <string> vString;

		vString.push_back( clsDate::GetSystemDateTimeString());
		vString.push_back(CurrentUser.UserName);
		vString.push_back(CurrentUser.Password);
		vString.push_back(to_string(CurrentUser.Permissions));

		return vString;
	}

	static string _PrepareLogRecord(string Seperator)
	{
		vector <string> vLog = _GetLogData();

		return clsString::JoinString(vLog, Seperator);

	}
	



public:


	static void SaveLogs()
	{

	  fstream MyFile;
	  string LogRecord = _PrepareLogRecord("#//#");

	  MyFile.open("LoginRegister.txt", ios::out | ios::app);

	  if (MyFile.is_open())
	  {
		  MyFile << LogRecord << endl;

		  MyFile.close();
	  }

	}

	static vector<vector<string>> ReadAllLogs(string Seperator = "#//#")
	{
		vector<vector<string>> AllLogs;
		fstream MyFile("LoginRegister.txt", ios::in);

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