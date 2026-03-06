#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsConsoleColor.h"


class clsUpdateClientScreen : protected clsScreen
{

private:

    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
    }

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

    static void ShowUpdateClientScreen()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
        {
            return;  // this will exit the function and it will not continue
        }


        _DrawScreenHeader("\t Update Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            clsConsoleColor::Red();
            cout << "\nAccount Number is not found, choose another one : ";
            clsConsoleColor::Default();
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        cout << "\n\nUpdate Client Info:";
        cout << "\n_____________________\n";

        _ReadClientInfo(Client1);

        clsBankClient::enSaveResult SaveResult;

        SaveResult = Client1.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResult::svSucceeded:
        {
            clsConsoleColor::Green();
            cout << "\nAccount Updated Successfully :)\n"; 
            clsConsoleColor::Default();
           _PrintClient(Client1);

            break;
        }
        case clsBankClient::enSaveResult::svFaildEmptyObject:
        {

            clsConsoleColor::Red();
            cout << "\nError Account was not saved because it's Empty";
            clsConsoleColor::Default();
            break;
        }

        }

    }



};

