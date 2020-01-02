#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cctype> 
using namespace std;

void ReplaceWordStr(string& str, string replacedWord, string wordToReplace); // ������ ��������� ����� � ������
char* UppercaseLatter(char* str1); // ���������� ������ ����� � ���������
int HowManyLettersTheText(char* str, char simbol); //
int HowManyNumbersText(char* str);

int main()
{
    setlocale(LC_ALL, "ru");

    // ����� ������������ ���� ���� �� ������������ 
    string str = "lorem Ipsum is simply dummy text of the printing 123 and typesetting industry.";
    string replacedWord = "text";
    string wordToReplace = "TEXT_NEW"; 
    char* ptrStr = new char[str.length() + 1]; // +1 ��� �������� �����
    strcpy(ptrStr, str.c_str());

    cout << endl << endl;
    cout << "���� ������: " << str << endl << endl;
    cout << "���������� �������� ����� - " << replacedWord << " �� ����� - " << wordToReplace << endl << endl;

    for (int i = 0; i < 50; i++) { cout << "_"; }
    //------------------------------------------------------------------------
    cout << endl << endl;

    ReplaceWordStr(str, replacedWord, wordToReplace); // ������ ��������� ����� � ������
    cout << "������ � ������� �����: " << str;

    cout << endl;
    for (int i = 0; i < 50; i++) { cout << "_"; }
    //------------------------------------------------------------------------
    cout << endl << endl;

    string str1 = UppercaseLatter(ptrStr); // �������������� ������ ����� � ���������

    cout << "������ � ����������� ������ �����: " << str1;

    cout << endl;
    for (int i = 0; i < 50; i++) { cout << "_"; }
    //------------------------------------------------------------------------
    cout << endl << endl;

    char simbol = 'i';

    int HowManyLetters = HowManyLettersTheText(ptrStr, simbol);

    cout << "������� �������� - '" << simbol  << "' � ������: " << HowManyLetters;

    cout << endl;
    for (int i = 0; i < 50; i++) { cout << "_"; }
    //------------------------------------------------------------------------
    cout << endl << endl;

    int HowManyNumbers = HowManyNumbersText(ptrStr);

    cout << "������� ���� � ������: " << HowManyNumbers;

    cout << endl << endl;
    delete[] ptrStr;
    system("pause>null");
}

void ReplaceWordStr(string& str, string replacedWord, string wordToReplace)
{
    int length = replacedWord.length();
    int find = str.find("text");

    str.replace(find, length, wordToReplace);  
}
char* UppercaseLatter(char* str1)
{
        str1[0] = toupper(str1[0]);

    return str1;
}
int HowManyLettersTheText(char* str, char simbol)
{
    int count = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == simbol)
        {
            count++;
        }
    }
    return count;
}
int HowManyNumbersText(char* str)
{
    int count = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        if (isdigit(str[i]))
        {
            count++;
        }
    }
    return count;
}