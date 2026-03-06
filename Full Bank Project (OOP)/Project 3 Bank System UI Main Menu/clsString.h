//-----------This Library Provides REUSABLE and Modular Fuctions
//-----------Implementin Solutions from the C++ Problem Solving V3
//-----------Exercises Covered 23 to 44


#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <vector>


using namespace std;

class clsString
{
private:
	string _Value;

public:

	clsString()
	{
		_Value = "";
	}

	clsString(string Value)
	{
		_Value = Value;
	}

	void SetValue(string Value)
	{
		_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;


    static void CountEachWordInString(string S1)
    {
        string Space = " ";
        short pos = 0;
        string sWord;
        short Counter = 0;


        //Using find() function to get the position of Space
        while ((pos = S1.find(Space)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); //Store the Word
            if (sWord != " ")
            {
                Counter++;
            }
            S1.erase(0, pos + Space.length());//Erasing until position and move to the next word

        }

        if (S1 != " ")
        {
            Counter++;
        }

        cout << "The Number of Words in your String is : " << Counter << endl;


    }

    void CountEachWordInString()
    {
        CountEachWordInString(_Value);
    }

    static void PrintFirstLetterOfEachWordInString(string Message)
    {
        bool IsFirstLetter = true;

        cout << "First Letters of this String : " << endl;

        for (short i = 0; i < Message.length(); i++)
        {
            if (Message[i] != ' ' && IsFirstLetter)
            {
                cout << Message[i] << endl;
            }
            //To Check if We are in the beginning of a new word
            IsFirstLetter = (Message[i] == ' ' ? true : false);
        }
    }

    void PrintFirstLetterOfEachWordInString()
    {
        PrintFirstLetterOfEachWordInString(_Value);
    }

    static void PrintUpperFirstLetterOfEachWordInString(string Message)
    {
        bool IsFirstLetter = true;


        for (short i = 0; i < Message.length(); i++)
        {
            if (Message[i] != ' ' && IsFirstLetter)
            {
                Message[i] = toupper(Message[i]);

            }
            //To Check if We are in the beginning of a new word
            IsFirstLetter = (Message[i] == ' ' ? true : false);
        }
        cout << "String after conversion : " << endl;
        cout << Message << endl;
    }

    void PrintUpperFirstLetterOfEachWordInString()
    {
        PrintUpperFirstLetterOfEachWordInString(_Value);
    }

    static void PrintLowerFirstLetterOfEachWordInString(string Message)
    {
        bool IsFirstLetter = true;


        for (short i = 0; i < Message.length(); i++)
        {
            if (Message[i] != ' ' && IsFirstLetter)
            {
                Message[i] = tolower(Message[i]);

            }
            //To Check if We are in the beginning of a new word
            IsFirstLetter = (Message[i] == ' ' ? true : false);
        }
        cout << "String after conversion : " << endl;
        cout << Message << endl;
    }

    void PrintLowerFirstLetterOfEachWordInString()
    {
        PrintLowerFirstLetterOfEachWordInString(_Value);
    }

  
    static string UpperAllString(string Message)
    {

        for (short i = 0; i < Message.length(); i++)
        {
            Message[i] = toupper(Message[i]);

        }
        return Message;
    }



    void PrintUpperLettersOfaString()
    {
        UpperAllString(_Value);
    }


    static string LowerAllString(string Message)
    {

        for (short i = 0; i < Message.length(); i++)
        {
            Message[i] = tolower(Message[i]);

        }
        return Message;
    }


    void PrintLowerLettersOfaString()
    {
        LowerAllString(_Value);
    }

    static void AllLettersInverter(string Message)
    {
        for (int i = 0; i < Message.length(); i++)
        {

            if (isupper(Message[i]))
            {
                Message[i] = tolower(Message[i]);
            }
            else
            {
                Message[i] = toupper(Message[i]);
            }
        }

        cout << "String After Inverting All Letter Case :" << endl;
        cout << Message << endl;

    }

    void AllLettersInverter()
    {
        AllLettersInverter(_Value);
    }

    static void StringLength(string Message)
    {
        int Counter = 0;
        for (short i = 0; i < Message.length(); i++)
        {

            if (Message[i] != ' ')
            {
                Counter++;
            }
        }
        cout << "String Length = " << Counter << endl;

    }

    void StringLength()
    {
        StringLength(_Value);
    }

    static void CapitalLettersCounter(string Message)
    {
        int Counter = 0;
        for (short i = 0; i < Message.length(); i++)
        {
            if (isupper(Message[i]))
            {
                Counter++;
            }
        }
        cout << "Capital Letters Count = " << Counter << endl;
    }

    void CapitalLettersCounter()
    {
        CapitalLettersCounter(_Value);
    }

    static void SmallLettersCounter(string Message)
    {
        int Counter = 0;
        for (short i = 0; i < Message.length(); i++)
        {
            if (islower(Message[i]))
            {
                Counter++;
            }
        }
        cout << "Small Letters Count = " << Counter << endl;
    }

    void SmallLettersCounter()
    {
        SmallLettersCounter(_Value);
    }

    static short CountLetters(string Message, char Letter)
    {
        short Counter = 0;

        for (short i = 0; i < Message.length(); i++)
        {
            if (Message[i] == Letter)
            {
                Counter++;
            }
        }
        return Counter;
    }

    short CountLetters(char Letter)
    {
        return  CountLetters(_Value, Letter);
    }

    static char InvertLetterCase(char Letter)
    {
        return isupper(Letter) ? tolower(Letter) : toupper(Letter);
    }

    static short CountLettersInvertCase(string Message, char Letter)
    {
        short Counter = 0;
        char Inverted = InvertLetterCase(Letter);

        for (short i = 0; i < Message.length(); i++)
        {
            if (Message[i] == Inverted)
                Counter++;
        }
        return Counter;
    }

    static short CountLettersAllCases(string Message, char Letter)
    {
        return CountLetters(Message, Letter) + CountLettersInvertCase(Message, Letter);
    }

    short CountLettersAllCases(char Letter)
    {
        return CountLetters(_Value,Letter) + CountLettersInvertCase(_Value,Letter);
    }

    static bool IsVowel(char Letter)
    {
        Letter = tolower(Letter);

        return ((Letter == 'a') || (Letter == 'e') || (Letter == 'i') || (Letter == 'o') || (Letter == 'u'));

    }

    static short CountVowels(string S1)
    {
        short Counter = 0;
        for (short i = 0; i < S1.length(); i++)
        {
            if (IsVowel(S1[i]))
            {
                Counter++;
            }
        }
        return Counter;
    }

    short CountVowels()
    {
        return CountVowels(_Value);
    }

    static void PrintAllVowels(string S1)
    {

        for (short i = 0; i < S1.length(); i++)
        {
            if (IsVowel(S1[i]))
            {
                cout << S1[i] << "     ";
            }
        }
    }

    void PrintAllVowels()
    {
        PrintAllVowels(_Value);
    }


    static void PrintEachWordInString(string S1)
    {

        cout << "Your String Words Are : " << endl;

        for (short i = 0; i < S1.length(); i++)
        {
            cout << S1[i];
            if (S1[i] != ' ')
            {
                continue;
            }
            cout << endl;
            cout << S1[i];

        }
    }

    void PrintEachWordInString()
    {
        PrintEachWordInString(_Value);
    }


    static vector <string> SplitString(string S1, string Delim)
    {
        vector <string> vString;
        short pos = 0;
        string sWord;


        while ((pos = S1.find(Delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); //Store the Word
            if (sWord != " ")
            {
                vString.push_back(sWord);
            }
            S1.erase(0, pos + Delim.length());//Erasing until position and move to the next word

        }

        if (S1 != " ")
        {
            vString.push_back(S1);
        }

        return  vString;
    }

    vector <string> SplitString(string Delim)
    {
        return SplitString(_Value, Delim);
    }

    
    static string TrimLeft(string S1)
    {

        while (!S1.empty() && S1[0] == ' ')
        {
            S1.erase(0, 1);

        }

        return S1;

    }

    void TrimLeft()
    {
        _Value = TrimLeft(_Value);
    }

    static string TrimRight(string S1)
    {
        while (!S1.empty() && S1.back() == ' ')
        {
            S1.pop_back();

        }

        return S1;
    }

    void TrimRight()
    {
         _Value = TrimRight(_Value);
    }

    static string Trim(string S1)
    {
        S1 = TrimLeft(S1);
        S1 = TrimRight(S1);


        return S1;
        //OR return (TrimLeft(TrimRight(S1)));
    }

    void Trim()
    {
         _Value = Trim(_Value);
    }

    static string JoinString(vector<string> vString, string Space)
    {
        string S1 = "";

        for (string& s : vString)
        {
            S1 = S1 + s + Space;

        }
        return S1.substr(0, S1.length() - Space.length());//To Cut The Last Spaces

    }

    static string JoinString(string ArrayStr[], short Length, string Space)
    {
        string S1 = "";

        for (short i = 0; i < Length; i++)
        {
            S1 += ArrayStr[i] + Space;
        }
        return S1.substr(0, S1.length() - Space.length());

    }

    static void ReverseString(string S1)
    {
        vector <string> vReversed = SplitString(S1, " ");

        cout << "Reversed String : " << endl;

        for (short i = vReversed.size() - 1; i >= 0; i--)
        {
            cout << vReversed[i] << " ";

        }

    }

    void ReverseString()
    {
        ReverseString(_Value);
    }

    static string ReplaceWordInStringUsingBuiltInFunction(string S1, string StringToReplace, string sReplace)
    {
        short pos = S1.find(StringToReplace);

        while (pos != std::string::npos)
        {
            S1 = S1.replace(pos, StringToReplace.length(), sReplace);
            pos = S1.find(StringToReplace);//To Find The Next One
        }

        return S1;

    }

    static string ReplaceWordInStringUsingSplits(string S1, string StringToReplace, string sReplace)
    {
        short pos = S1.find(StringToReplace);

        while (pos != std::string::npos)
        {
            string S1Before = S1.substr(0, pos);
            string S1After = S1.substr(pos + StringToReplace.length());

            S1 = S1Before + sReplace + S1After;

            pos = S1.find(StringToReplace);//To Find The Next One
        }

        return S1;


    }

    static string RemovePunctuations(string S1)
    {
        string S2 = "";

        for (int i = 0; i < S1.length(); i++)
        {
            if (!ispunct(S1[i]))
            {
                S2 += S1[i];
            }
        }
        return S2;

    }

    void RemovePunctuations()
    {
       _Value =  RemovePunctuations(_Value);
    }

  
   





















};

