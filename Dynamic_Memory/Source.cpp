#include<iostream>
using namespace std;

int** Allocate(const int rows, const int cols);
void Clear(int** arr, const int rows);

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);

void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, int value);
int* push_front(int* arr, int& n, int value);
int* push_insert(int* arr, int& n, int element, int value);
int* pop_back(int arr[], int&n);
int* pop_front(int arr[], int&n);
int* erase(int arr[], int&n, int index);

int** push_row_back(int**arr, int& rows, const int cols );
int** pop_row_back(int**arr, int& rows, const int cols );

void push_col_back(int** arr, const int rows, int& cols);
void pop_col_back(int** arr, const int rows, int& cols);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
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
#endif DYNAMIC_MEMORY_1

	int rows;
	int cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;
	int** arr = Allocate(rows, cols);
	//объявление двумерного динам. массива

	

	
	// Использование двум. дин. массива
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << endl;

	arr=push_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << endl;

	Print(arr = pop_row_back(arr, rows, cols), rows, cols);
	cout << endl;

	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << endl;

	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	Clear(arr, rows);
	//удаление двум. дин. массива
	
}
int** Allocate(const int rows, const int cols)
{
	int** arr = new int* [rows]; //создае массив указателей
	//Выделяем память под строки
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	return arr;
}
void Clear(int** arr, const int rows)
{
	//1.удаляем строки:
	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}
	//удаление массива указателей:
	delete[]arr;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
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
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
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
int** push_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1] {};//создаем буферный массив указателей
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];//копируем адреса строк в новый массив
	delete[]arr;//удаляем исходный массив указателей
	buffer[rows] = new int[cols] {};//создаем добавляемую строку
	rows++; //после добавления строки кол-во строк увеличивается на 1
	return buffer;
}
int** pop_row_back(int** arr, int& rows, const int cols)
{
	delete[] arr[rows - 1];
	int** buffer = new int*[--rows]{};
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];
	delete[]arr;
	return buffer;
}
void push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows;i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void pop_col_back(int** arr, const int rows, int& cols)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[]arr[i];
		arr[i] = buffer;
	}
}