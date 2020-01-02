#include <iostream>
#include <ctime>
using namespace std;

void ArrOut(int*& arr, int size);
void ArrIn(int*& arr, int size);

int MaxArr(int*& arrA, int*& arrB, int size);
int MinArr(int*& arrA, int*& arrB, int size);
int AvgArr(int*& arrA, int*& arrB, int size);
int Action(int*& ptrArrA, int*& ptrArrB, int size, int (*Func)(int*&, int*&, int));

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(0));

    int menu = 0;
    const int SIZE = 5;

    int arrA[SIZE];
    int arrB[SIZE];
    int* ptrArrA = arrA;
    int* ptrArrB = arrB;
    //void (*Func)();

    ArrIn(ptrArrA, SIZE); // ���������� ������� �
    ArrIn(ptrArrB, SIZE); // ���������� ������� �

    cout << "����� ������� �:" << endl << endl;
    cout << "\t| ";
    ArrOut(ptrArrA, SIZE); // ����� ������� �

    cout << endl << endl;
    cout << "����� ������� B:" << endl << endl;
    cout << "\t| ";
    ArrOut(ptrArrB, SIZE); // ����� ������� �
    cout << endl << endl;

    cout << "1) ������������ ����� �� ���� ��������;" << endl;
    cout << "2) ����������� ����� �� ���� ��������;" << endl;
    cout << "3) ������� �������������� �� ���� ��������;" << endl << endl;
    cout << "������� ����� ����: "; cin >> menu;
    cout << endl;
  
    if (menu == 1)
    {
        cout << "������������ ����� �� ���� ��������: " << Action(ptrArrA, ptrArrB, SIZE, MaxArr) << endl;
    }
    else if (menu == 2)
    {
        cout << "����������� ����� �� ���� ��������: " << Action(ptrArrA, ptrArrB, SIZE, MinArr) << endl;
    }
    else if (menu == 3)
    {
        cout << "������� �������������� �� ���� ��������: " << Action(ptrArrA, ptrArrB, SIZE, AvgArr) << endl;
    }

    cout << endl << endl;
    system("pause>null");
}

void ArrOut(int*& arr, int size)
{
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " | ";
    }
}
void ArrIn(int*& arr, int size)
{
    for (int i = 0; i < size; i++) // ���������� �������� 
    {
        arr[i] = rand() % 100 - 50;      
    }
}
int MaxArr(int*& arrA, int*& arrB, int size)
{
    int tempA = arrA[0];
    int tempB = arrB[0];

    for (int i = 0; i < size; i++)
    {
        if (tempA < arrA[i])
        {
            tempA = arrA[i];
        }
        if (tempB < arrB[i])
        {
            tempB = arrB[i];
        }
    }    
    if (tempA > tempB)
    {
        return tempA;
    }
    else
    {
        return tempB;
    }
}
int MinArr(int*& arrA, int*& arrB, int size)
{
    int tempA = arrA[0];
    int tempB = arrB[0];

    for (int i = 0; i < size; i++)
    {
        if (tempA > arrA[i])
        {
            tempA = arrA[i];
        }
        if (tempB > arrB[i])
        {
            tempB = arrB[i];
        }
    }
    if (tempA < tempB)
    {
        return tempA;
    }
    else
    {
        return tempB;
    }
}
int AvgArr(int*& arrA, int*& arrB, int size)
{
    int summ = 0, avg;

    for (int i = 0; i < size; i++)
    {
        summ += arrA[i] + arrB[i];
    }

    avg = summ / size;

    return avg;
}
int Action(int*& ptrArrA, int*& ptrArrB, int size, int(*Func)(int*&, int*&, int))
{
    return  Func(ptrArrA, ptrArrB, size);
}