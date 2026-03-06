#pragma once
#include <Windows.h>
#include <iostream>

using namespace std;

class clsConsoleColor
{
public:
	
	static void Green()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	}

	static void Red()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	}

	static void Default()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	}



};

