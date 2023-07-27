#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* push_back(int arr[], int& n, int value);
int* push_front(int* arr, int& n, int value);
int* push_insert(int* arr, int& n, int element, int value);
int* pop_back(int arr[], int&n);
int* pop_front(int arr[], int&n);
int* erase(int arr[], int&n, int index);
void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Ведите размер массива: "; cin >> n;
	int* arr = new int[n];
	int value;

	FillRand(arr, n);
	Print(arr, n);


	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	
	int element;
	cout << "Введите добавляемое значение: "; cin >> value;
	cout << "Введите элемент : "; cin >> element;
	arr = push_insert(arr, n, element, value);
	Print(arr, n);


	Print(arr=pop_back(arr, n),n);
	arr = pop_front(arr, n);
	Print(arr, n);

	int index;
	cout << "Введите номер элемента для удаления: "; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);

	delete[]arr;
	
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{

		cout << arr[i] << "\t";

	}
	cout << endl;
}
int* push_back(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
	return arr;
}
int* push_front(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;

	return arr;
}
int* push_insert(int* arr, int& n,int element, int value)
{

	int* buffer = new int[n + 1];
	for (int i =0; i < element; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = element; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[element] = value;
	n++;

	return arr;
}
int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[]arr;
	return buffer;

}
int* pop_front(int arr[], int& n)
{
	int* buffer = new int[n-1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[]arr;
	n--;
	return buffer;
}
int* erase(int arr[], int& n, int index)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	n--;
	delete[]arr;
	return buffer;
}