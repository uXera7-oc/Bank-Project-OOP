#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include "clsUtil.h"


using namespace std;

class clsUser : public clsPerson
{

private:

	enum enMode{EmptyMode = 0,UpdateMode,AddNewMode};
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;

	bool _MarkedForDelete = false;

	static clsUser _ConvertLineToUserObject(string Line, string Seperator = "#//#")
	{
		vector <string> vUserData;
		vUserData = clsString::SplitString(Line, Seperator);

		return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3], vUserData[4],
			clsUtil::DecryptionText(vUserData[5]), stoi(vUserData[6]));
	}

	static string _ConvertUserObjectToLine(clsUser User, string Seperator = "#//#")
	{
		string UserRecord = "";

		UserRecord += User.FirstName + Seperator;
		UserRecord += User.LastName + Seperator;
		UserRecord += User.Email + Seperator;
		UserRecord += User.Phone + Seperator;
		UserRecord += User.UserName + Seperator;
		UserRecord += clsUtil::EncryptionText(User._Password) + Seperator;
		UserRecord += to_string(User._Permissions);

		return UserRecord;
	}

	static vector <clsUser> _LoadUsersDataFromFile()
	{
		vector <clsUser> vUsers;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//Read Mode

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				vUsers.push_back(User);
			}
			MyFile.close();
		}
		return vUsers;

	}

	static void _SaveUsersDataToFile(vector <clsUser> vUsers)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out);//Overwrite

		string DataLine;

		if (MyFile.is_open())
		{
			for (clsUser U : vUsers)
			{
				if (U.MarkedForDeleted() == false)
				{
					//We only Write records that are not marked for delete
					DataLine = _ConvertUserObjectToLine(U);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}

	}

	void _Update()
	{
		vector <clsUser> _vUsers;
		_vUsers = _LoadUsersDataFromFile();

		for (clsUser& U : _vUsers)
		{
			if (U.UserName == _UserName)
			{
				U = *this;
				break;
			}
		}

		_SaveUsersDataToFile(_vUsers);

	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}

	void _AddDataLineToFile(string DataLine)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;

			MyFile.close();
		}

	}

	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}


public:

	enum enPermissions{eAll = -1, pListClients = 1,pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClients = 8, pFindClient = 16, pTransactions = 32,pManageUsers = 64 ,pLoginRegister = 128};


	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone,
		string UserName, string Password, int Permissions) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	bool MarkedForDeleted()
	{
		return _MarkedForDelete;
	}

	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}

	string GetUserName()
	{
		return _UserName;
	}

	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;

	void SetPassword(string Password)
	{
		_Password = Password;
	}
	
	string GetPassword()
	{
		return _Password;
	}

	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}

	int GetPermissions()
	{
		return _Permissions;
	}

	__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

	static clsUser Find(string UserName)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//Read Mode

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName)
				{
					MyFile.close();
					return User;
				}
			}
			MyFile.close();

		}
		return _GetEmptyUserObject();
	}

	static clsUser Find(string UserName,string Password)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//Read Mode

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName && User.Password == Password)
				{
					MyFile.close();
					return User;
				}
			}
			MyFile.close();

		}
		return _GetEmptyUserObject();
	}

	enum enSaveResult{svFailedEmptyObject = 0, svSucceeded , svFailedUserExists};

	enSaveResult Save()
	{

		switch (_Mode)
		{
		case EmptyMode:
		{
			if (IsEmpty())
			{
				return svFailedEmptyObject;
			}
		}

		case UpdateMode:
		{
			_Update();
			return svSucceeded;
			break;
		}

		case AddNewMode:
		{
			//This Will add new record to File or DataBase
			if (clsUser::IsUserExist(_UserName))
			{
				return svFailedUserExists;
			}
			else
			{
				_AddNew();
				//We Need to set the mode to update after adding new user
				_Mode = UpdateMode;

				return svSucceeded;
			}
			break;
		}



		}
	}

	static bool IsUserExist(string UserName)
	{
		clsUser User = clsUser::Find(UserName);
		return(!User.IsEmpty());
	}

	bool Delete()
	{
		vector <clsUser> _vUsers;
		_vUsers = _LoadUsersDataFromFile();

		for (clsUser& U : _vUsers)
		{
			if (U.UserName == _UserName)
			{
				U._MarkedForDelete = true;
				break;
			}
		}
		_SaveUsersDataToFile(_vUsers);
		*this = _GetEmptyUserObject();

		return true;
	}

	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(AddNewMode, "", "", "", "", UserName, "", 0);
	}

	static vector <clsUser> GetUserList()
	{
		return _LoadUsersDataFromFile();
	}

	bool CheckAccessPermission(enPermissions Permission)
	{
		if (this->Permissions == eAll)
			return true;
		if((Permission & this->Permissions) == Permission)
			return true;
		else
			return false;

	}




};

