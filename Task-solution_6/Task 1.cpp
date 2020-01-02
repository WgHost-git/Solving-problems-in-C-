#include <iostream>
using namespace std;

void dynamicArrayOne(int*& arr1, int& size); // ������� ������������� ������������ ������ ����������� �������
void initializingOneDimensionalDynamicArray(int*& arr, int& size); // ������� ������������� ������������� �������
void printingOneDimensionalArray(int*& arr, int& size); // ������� ������ ����������� ������������� �������
void deletingOneDimensionalArray(int*& arr); // ������� �������� ������������� �������
void addingElementEndOneDimensionalArray(int*& arr, int& size, int element); // ������� ���������� �������� � ����� �������
void insertsSpecifiedIndex(int*& arr, int index, int element, int& size); // ������� ������� �������� �� ���������� ������� 
void deleteSpecifiedIndex(int*& arr, int index, int& size);

int main()
{
	setlocale(LC_ALL, "ru");

	int size;
	int* arr;
	int element = 10;
	int index;

	cout << "Enter an array size from 5 to 20: "; cin >> size;

	//______________________________________________________________________________________________________

	dynamicArrayOne(arr, size); // ������� ������������� ������������ ������ ����������� �������
	initializingOneDimensionalDynamicArray(arr, size); // ������� ������������� ������������� �������
	printingOneDimensionalArray(arr, size); // ������� ������ ����������� ������������� �������
//______________________________________________________________________________________________________

	cout << endl << endl;
	cout << "Enter the item to insert: "; cin >> element; cout << endl;
	cout << "Adding an element to the end of a one-dimensional dynamic array: " << endl << endl;

	addingElementEndOneDimensionalArray(arr, size, element); // ������� ���������� �������� � ����� �������
	printingOneDimensionalArray(arr, size); // ������� ������ ����������� ������������� �������

//______________________________________________________________________________________________________

	cout << endl << endl;
	cout << "Enter the index number you want to replace from 1 to " << size << ": ";
	cin >> index; cout << endl;
	cout << "Enter the item to insert: "; cin >> element;

	insertsSpecifiedIndex(arr, index, element, size); // ������� ������� �������� �� ���������� �������
	printingOneDimensionalArray(arr, size); // ������� ������ ����������� ������������� �������

//______________________________________________________________________________________________________

	cout << endl << endl;
	cout << "Enter the index number you want to delete from 1 to " << size << ": ";
	cin >> index; cout << endl;

	deleteSpecifiedIndex(arr, index, size); // ������� �������� �������� �� ���������� �������
	printingOneDimensionalArray(arr, size); // ������� ������ ����������� ������������� �������

//______________________________________________________________________________________________________

	deletingOneDimensionalArray(arr);
	cout << endl << endl;
	system("pause>null");
}

// ������� ������������� ������������ ������ ���������� �������
void dynamicArrayOne(int*& arr, int& size)
{
	arr = new int[size];
}

// ������� ������������� ������������� �������
void initializingOneDimensionalDynamicArray(int*& arr, int& size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = i;
	}
}

// ������� ������ ����������� ������������� �������
void printingOneDimensionalArray(int*& arr, int& size)
{
	cout << endl;
	cout << "\t\t";

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " | ";
	}

}

// ������� �������� ������������� �������
void deletingOneDimensionalArray(int*& arr)
{
	//cout << &arr << endl;
	delete[] arr;
}

// ������� ���������� �������� � ����� �������
void addingElementEndOneDimensionalArray(int*& arr, int& size, int element)
{
	int* tempArr = new int[size];

	for (int i = 0; i < size; i++)
	{
		tempArr[i] = arr[i];
	}

	deletingOneDimensionalArray(arr);
	size++;
	dynamicArrayOne(arr, size);

	for (int i = 0; i < size - 1; i++)
	{
		arr[i] = tempArr[i];
	}

	arr[size - 1] = element;

	deletingOneDimensionalArray(tempArr);
}

// ������� ������� �������� �� ���������� �������
void insertsSpecifiedIndex(int*& arr, int index, int element, int& size)
{
	int temp;
	int* tempArr = new int[size];

	for (int i = 0; i < size; i++)
	{
		tempArr[i] = arr[i];
	}

	deletingOneDimensionalArray(arr);
	size++;
	dynamicArrayOne(arr, size);

	for (int i = 0, x = 0; i < size, x < size + 1; i++, x++)
	{
		if (i == index - 1)
		{
			arr[x] = tempArr[i];
			temp = arr[x];
			arr[x] = element;
			x++;
			arr[x] = temp;
		}
		else
		{
			arr[x] = tempArr[i];
		}
	}

	deletingOneDimensionalArray(tempArr);
}

// ������� �������� �������� �� ���������� �������
void deleteSpecifiedIndex(int*& arr, int index, int& size)
{
	int temp;
	int* tempArr = new int[size];

	for (int i = 0; i < size; i++)
	{
		tempArr[i] = arr[i];
	}

	deletingOneDimensionalArray(arr);
	size--;
	dynamicArrayOne(arr, size);

	for (int i = 0, x = 0; i < size, x < size; i++, x++)
	{
		if (i == index - 1)
		{
			i++;
			arr[x] = tempArr[i];
		}
		else
		{
			arr[x] = tempArr[i];
		}
	}

	deletingOneDimensionalArray(tempArr);
}