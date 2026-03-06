#pragma once
#include <iostream>
#include "clsString.h"
#include "clsScreen.h"
#include "clsFindClientScreen.h"
#include "TransferLog.h"
#include "clsConsoleColor.h"




class clsTransferScreen : protected clsScreen
{

private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << FormatCurrency(Client.AccountBalance);
        cout << "\n___________________\n";
    }


    static string _ReadAccountNumber(string Message)
    {
        string AccountNumber;
        cout << Message;
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            clsConsoleColor::Red();
            cout << "\nAccount number is not found, choose another one: ";
            clsConsoleColor::Default();
            AccountNumber = clsInputValidate::ReadString();
        }
        return AccountNumber;
    }

    static float _ReadAmount(clsBankClient SourceClient)
    {
        float Amount;
        cout << "\nEnter Transfer Amount ? ";
        Amount = clsInputValidate::ReadFloatNumber();

        while (Amount > SourceClient.AccountBalance)
        {
            clsConsoleColor::Red();
            cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
            clsConsoleColor::Default();
            Amount = clsInputValidate::ReadDblNumber();
        }
        return Amount;


    }
   




public:

    static void ShowTransferScreen()
    {
        _DrawScreenHeader("\tFind Client Screen");

        clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("\nPlease Enter Account Number to Transfer From : "));

        _PrintClient(SourceClient);

        clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("\nPlease Enter Account Number to Transfer To : "));

        _PrintClient(DestinationClient);

        float Amount = _ReadAmount(SourceClient);

        cout << "\nAre you sure you want to perform this operation? y/n? ";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient))
            {
                clsConsoleColor::Green();
                cout << "\nTransfer done successfully :)\n";
                clsConsoleColor::Default();
                TransferLog::SaveTransferLog(SourceClient, DestinationClient, Amount);
            }
            else
            {
                clsConsoleColor::Red();
                cout << "\nTransfer Failed \n";
                clsConsoleColor::Default();
            }
        }

        _PrintClient(SourceClient);
        _PrintClient(DestinationClient);


    }

};


