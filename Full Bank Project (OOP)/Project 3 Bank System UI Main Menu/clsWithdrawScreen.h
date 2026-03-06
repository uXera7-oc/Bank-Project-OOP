#pragma once
#include<iostream>
#include "clsConsoleColor.h"


class clsWithdrawScreen : protected clsScreen
{

private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << FormatCurrency(Client.AccountBalance);
		cout << "\n___________________\n";
	}

	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\nPlease enter Account Number ";
		cin >> AccountNumber;
		return AccountNumber;
	}


public:

	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("\t  Withdraw Screen");

		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with [" << AccountNumber << "] does not exist\n";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		double Amount = 0;
		cout << "\nPlease enter Withdraw amount ";
		Amount = clsInputValidate::ReadDblNumber();

		cout << "\nAre you sure you want to perform this transaction? y/n";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			
			if(Client1.Withdraw(Amount))
			{
				clsConsoleColor::Green();
				cout << "\nAmount Withdrew Successfully :) \n";
				clsConsoleColor::Default();
				cout << "\nNew Balance is : " << FormatCurrency(Client1.AccountBalance);
			}
			else
			{
				clsConsoleColor::Red();
				cout << "\nCannot Withdraw, Insufficient Balance!\n";
				clsConsoleColor::Default();
				cout << "\nAmount to withdraw is : " << FormatCurrency(Amount);
				cout << "\nYour Balance is : " << FormatCurrency(Client1.AccountBalance);
			}
		}
		else
		{
			clsConsoleColor::Red();
			cout << "\nOperation was Cancelled\n";
			clsConsoleColor::Default();
		}

	}

};

