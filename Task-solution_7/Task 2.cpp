#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cctype>   
using namespace std;

int mystrcmp(const char* str1, const char* str2); //������� ���������� ��� ������ �, ���� ������ ����� ���������� 0, 
                                                  //���� ������ ������ ������ ������, �� ���������� 1, ����� - 1.
int StringToNumber(char* str); //������� ������������ ������ � ����� � ���������� ��� �����
char* NumberToString(int  number);  //�������  ������������  �����  �  ������  �  ���������� ��������� �� ��� ������.
char* Uppercase(char* str1); //������� ����������� ������ � ������� �������.
char* Lowercase(char* str1); //������� ����������� ������ � ������ �������.
char* mystrrev(char* str);  //�������  �����������  ������  �  ����������  ���������  ��  ����� ������.

int main()
{
    setlocale(LC_ALL, "ru");

    string str1 = "123";
    string str2 = "abcsdf";

    char* ptrStr1Arr = new char[str1.length() + 1]; // +1 ��� �������� �����
    strcpy(ptrStr1Arr, str1.c_str());

    char* ptrStr2Arr = new char[str2.length() + 1]; // +1 ��� �������� �����
    strcpy(ptrStr2Arr, str2.c_str());

    /* ������� 2 ��� �������� ������������ ��������

    char* ptrStr1Arr = (char*)str1.c_str(); 

    char* ptrStr2Arr = (char*)str2.c_str(); 
    */
    //------------------------------------------------------------------------

    cout << "����� �� ����� ������ ������: ";

    for (int i = 0; i < str1.length(); i++) { cout << ptrStr1Arr[i]; }

    cout << endl;
    cout << "����� �� ����� ������ ������: ";
    
    for (int i = 0; i < str2.length(); i++) { cout << ptrStr2Arr[i]; }
    cout << endl;
    for (int i = 0; i < 50; i++){cout << "_";}

    //------------------------------------------------------------------------
    cout << endl << endl;

    int stringComp = mystrcmp(ptrStr1Arr, ptrStr2Arr); // ��������� ��������� ����� ������������ � ����������

    cout << "��������� ��������� �����: " << stringComp;
    
    cout << endl;
    for (int i = 0; i < 50; i++) { cout << "_"; }
    //------------------------------------------------------------------------
    cout << endl << endl;

    int convertStrToInt = StringToNumber(ptrStr1Arr); // ��������� ��������������� ������ � ����� ������������ � ����������
    
    cout << "��������������� ������ � �����: " << convertStrToInt;

    cout << endl;
    for (int i = 0; i < 50; i++) { cout << "_"; }
    //------------------------------------------------------------------------
    cout << endl << endl;

    int number = 11;

    string intToString = NumberToString(number); // ��������� ��������������� ����� � ������ ������������ � ����������

    cout << "��������� ��������������� �� Int � String: " << intToString;

    cout << endl;
    for (int i = 0; i < 50; i++) { cout << "_"; }
    //------------------------------------------------------------------------
    cout << endl << endl;

    string toUpper = Uppercase(ptrStr1Arr); // ��������� �������������� ������ � ������� ������

    cout << "��������� �������������� ������ � ������� ������: " << toUpper;

    cout << endl;
    for (int i = 0; i < 50; i++) { cout << "_"; }
    //------------------------------------------------------------------------
    cout << endl << endl;

    string toLower = Lowercase(ptrStr1Arr); // ��������� �������������� ������ � ������ ������


    cout << "��������� �������������� ������ � ������ ������: " << toLower;

    cout << endl;
    for (int i = 0; i < 50; i++) { cout << "_"; }
    //------------------------------------------------------------------------
    cout << endl << endl;

    string rrev = mystrrev(ptrStr1Arr); // ��������� ������� ������

    cout << "��������� ������� ������: " << rrev;

    cout << endl;
    for (int i = 0; i < 50; i++) { cout << "_"; }
    //------------------------------------------------------------------------
    cout << endl << endl;
    delete[] ptrStr1Arr, ptrStr2Arr;
    system("pause>null");
}

int mystrcmp(const char* str1, const char* str2)
{
    string str1_1 = string(str1);
    string str2_2 = string(str2);

    if (str1_1 == str2_2)
    {
        return 0;
    }
    else if (strlen(str1) > strlen(str2))
    {
        return 1;
    }
    else{
        return -1;
    }
}
int StringToNumber(char* str)
{
    int result;

    for (int i = 0; i < strlen(str); i++)
    {
        if (!isdigit(str[i]))
        {
            cout << "� ���� ������ ����������� �� �����!" << endl;
            return false;
        }
        else
        {
            result = atoi(str);
        }
    }
    return result;
}
char* NumberToString(int number)
{
    string temp = to_string(number);

    char* intToString = new char[temp.length() + 1];
    strcpy(intToString, temp.c_str());

    return intToString;
}
char* Uppercase(char* str1)
{
    for (int i = 0; i < strlen(str1); i++)
    {
        str1[i] = toupper(str1[i]);
    }
    return str1;
}
char* Lowercase(char* str1)
{
    for (int i = 0; i < strlen(str1); i++)
    {
        str1[i] = tolower(str1[i]);
    }
    return str1;
}
char* mystrrev(char* str)
{
    reverse(str, str + strlen(str));

    return str;
}