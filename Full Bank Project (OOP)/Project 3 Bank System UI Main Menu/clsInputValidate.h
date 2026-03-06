#pragma once
#include <iostream>
#include <string>
#include"clsString.h"
#include "clsDate.h"




class clsInputValidate
{

public:

	static bool IsNumberBetween(short Number, short From, short To)
	{
		return Number >= From && Number <= To;
	}

	static bool IsNumberBetween(int Number, int From, int To)
	{
		return Number >= From && Number <= To;
	}

	static bool IsNumberBetween(float Number, float From, float To)
	{
		return Number >= From && Number <= To;
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		return Number >= From && Number <= To;
	}

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		return (clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			&&
			(clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To));

	}

	static short ReadShortNumber(string Invalid = "Invalid Number, Enter again\n")
	{

		short Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << Invalid;
		}
		return Number;
	}

	static int ReadIntNumber(string Invalid = "Invalid Number, Enter again\n")
	{

		int Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << Invalid;
		}
		return Number;
	}

	static double ReadDblNumber(string Invalid = "Invalid Number, Enter again\n")
	{

		double Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << Invalid;
		}
		return Number;
	}

	static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		short Number = ReadShortNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadShortNumber();
		}
		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		return Number;
	}


	static double ReadFloatNumber(string Invalid = "Invalid Number, Enter again\n")
	{
		float Number;

		cin >> Number;

		while (cin.fail())
		{
			//user didn't input a number
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << Invalid;

			cin >> Number;
		}

		return Number;
	}



	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValiDate(Date);
	}

	static string ReadString()
	{
		string S1 = "";
		getline(cin >> ws, S1);
		return S1;
	}












};

