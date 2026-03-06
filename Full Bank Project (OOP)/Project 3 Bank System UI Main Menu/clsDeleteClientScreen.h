#pragma once
#include <iostream>
#include <iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include "clsConsoleColor.h"

class clsDeleteClientScreen: protected clsScreen
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

public:

	static void ShowDeleteClientScreen()
	{

        if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
        {
            return;  // this will exit the function and it will not continue
        }

        _DrawScreenHeader("\t Delete Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter Account Number : ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            clsConsoleColor::Red();
            cout << "\nAccount number is not found choose another one : ";
            clsConsoleColor::Default();
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        cout << "\nAre you sure you want to delete this client y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            if (Client1.Delete())
            {
                clsConsoleColor::Green();
                cout << "\nClient Deleted Successfully :)\n";
                clsConsoleColor::Default();
                _PrintClient(Client1);
            }
            else
            {
                clsConsoleColor::Red();
                cout << "\nError Client was not Deleted\n";
                clsConsoleColor::Default();

            }

        }

	}


};

