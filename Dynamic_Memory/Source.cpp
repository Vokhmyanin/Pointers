#include<iostream>
using namespace std;
void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	int n; //��������� ��������� �������
	cout << "������ ������ �������: "; cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;//��������� � ��������� ������� ����� ���������� ����������� � �������� �������������

	cout << arr[i] << "\t";
	}
	cout << endl;
	delete[] arr;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + 1) = rand() % 100;
	}
}