#pragma once

#include<iostream>
#include<string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "clsDate.h"

using namespace std;

class clsUtil
{


public:

    enum enType { SmallLetter = 1, CapitalLetter,Digit, SpecialCharacter ,MixChars };

    static void Srand()
    {
        // Seed the random number generator with the current time
        srand((unsigned)time(NULL)); //Called Only Once !
    }

    static int RandomNumber(int From, int To)
    {
        // Function To Generate Random Number

        int Rands = rand() % (To - From + 1) + From;
        return Rands;

        // rand() % (To - From + 1) → gives the number of values you need, always starting from 0.
        // + From → shifts these values from 0 to the actual start of the range.
    }

    static char GetRandomCharacters(enType Type)
    {
        if (Type == enType::MixChars)
        {
            Type = (enType)RandomNumber(1, 3);
        }

        switch (Type)
        {
        case(enType::SmallLetter):
        {
            return char(RandomNumber(97, 122));
            break;
        }
        case(enType::CapitalLetter):
        {
            return char(RandomNumber(65, 90));
            break;
        }
        case(enType::SpecialCharacter):
        {
            return char(RandomNumber(33, 47));
            break;
        }
        case (enType::Digit):
        {
            return char(RandomNumber(48, 57));
            break;
        }

        default:
            return '?';
        }
    }

    static string GenerateWord(enType Type, int LengthOfWord)
    {
        string Word;

        for (int i = 1; i <= LengthOfWord; i++)
        {
            Word = Word + GetRandomCharacters(Type);
        }
        return Word;
    }

    static string GenerateKey(enType Type)
    {
        string Key = "";

        for (int i = 0; i < 4; i++)
        {
            Key += GenerateWord(Type, 4);

            if (i < 3)
                Key += "-";
        }

        return Key;
    }

    static void GenerateKeys(int NumberOfKeys,enType Type)
    {
        for (int i = 1; i <= NumberOfKeys; i++)
        {
            cout << "Key [ " << i << " ] : " << GenerateKey(Type) << endl;
        }
    }

    static void Swap(int& A, int& B)
    {
        int temp;

        temp = A;
        A = B;
        B = temp;
    }

    static void Swap(double& A, double& B)
    {
        double temp;

        temp = A;
        A = B;
        B = temp;
    }

    static void Swap(string& A, string& B)
    {
        string temp;

        temp = A;
        A = B;
        B = temp;
    }

    static void Swap(clsDate& A, clsDate& B)
    {
        clsDate temp;

        temp = A;
        A = B;
        B = temp;

    }

    static void ShuffleArray(int Arr[100], int Length)
    {
        for (int i = 0; i < Length; i++)
        {
            Swap(Arr[RandomNumber(1, Length) - 1], Arr[RandomNumber(1, Length) - 1]);

        }
    }

    static void ShuffleArray(string Arr[100], int Length)
    {
        for (int i = 0; i < Length; i++)
        {
            Swap(Arr[RandomNumber(1, Length) - 1], Arr[RandomNumber(1, Length) - 1]);

        }
    }

    static void FillArrayWithRandomNumber(int Arr[100], int Length,int From,int To)   
    {
        for (int i = 0; i < Length; i++)
            Arr[i] = RandomNumber(From, To);
    }
    
    static void FillArrayWithRandomWords(string Arr[100], int Length,enType Type,int LengthOfWord)
    {
        for (int i = 0; i < Length; i++)
        {
            Arr[i] = GenerateWord(Type,LengthOfWord);
        }
    }

    static void FillArrayWithRandomKeys(string Arr[100], int Length,enType Type)
    {
        for (int i = 0; i < Length; i++)
        {
            Arr[i] = GenerateKey(Type);
        }
    }

    static string Tabs(int NumberOfTabs)
    {
         string tabs = "";
        for (int i = 1; i <= NumberOfTabs; i++)
        {
            tabs+= "    ";
        }
        return tabs;

    }
    
    static string EncryptionText(string Text,short Key = 2 )
     {
         for (int i = 0; i <= Text.length(); i++)
         {
             Text[i] = char(int(Text[i] + Key)); // To reach Letter in the text and it's Number in ASCII Then add Key to Encrypt it :)
         }
      
         return Text;
     }

    static string DecryptionText(string Text,short Key = 2)
     {
         for (int i = Text.length(); i >= 0; i--)
         {
             Text[i] = char(int(Text[i] - Key));
         }

         return Text;
     }



    static string NumberToText(int Number)
    {

        if (Number == 0)
        {
            return "";
        }

        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
        "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
          "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

            return  arr[Number] + " ";

        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
        {
            return  "One Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 200 && Number <= 999)
        {
            return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 1999)
        {
            return  "One Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 2000 && Number <= 999999)
        {
            return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 1999999)
        {
            return  "One Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 2000000 && Number <= 999999999)
        {
            return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return  "One Billion " + NumberToText(Number % 1000000000);
        }
        else
        {
            return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
        }


    }






};

